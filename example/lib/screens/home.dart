import 'dart:io';

import 'package:bdk_flutter/bdk_flutter.dart' as bdk;
import 'package:bdk_flutter_demo/managers/payjoin_manager.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:payjoin_flutter/bitcoin_ffi.dart';
import 'package:payjoin_flutter/common.dart';
import 'package:payjoin_flutter/receive.dart';
import 'package:payjoin_flutter/send.dart';
import 'package:payjoin_flutter/uri.dart' as pjuri;
import 'package:url_launcher/url_launcher.dart';
import '../widgets/widgets.dart';

class Home extends StatefulWidget {
  const Home({Key? key}) : super(key: key);

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  late bdk.Wallet wallet;
  late bdk.Blockchain blockchain;
  String? displayText;
  String? address;
  String balance = "0";
  TextEditingController mnemonic = TextEditingController();
  TextEditingController recipientAddress = TextEditingController();
  TextEditingController amountController = TextEditingController();
  TextEditingController pjUriController = TextEditingController();
  TextEditingController psbtController = TextEditingController();
  TextEditingController receiverPsbtController = TextEditingController();
  bool _isPayjoinEnabled = false;
  bool isReceiver = false;
  Receiver? v2Session;
  Sender? sender;
  UncheckedProposal? uncheckedProposal;
  PayjoinProposal? payjoinProposal;
  FeeRangeEnum? feeRange;
  PayjoinManager payjoinManager = PayjoinManager();
  String pjUri = '';

  String get getSubmitButtonTitle => _isPayjoinEnabled
      ? sender != null
          ? "Finalize Payjoin"
          : isReceiver
              ? pjUri.isNotEmpty
                  ? "Handle Request"
                  : "Build Pj Uri"
              : "Perform Payjoin"
      : "Send Bit";

  Future<void> generateMnemonicHandler() async {
    var res = (await bdk.Mnemonic.create(bdk.WordCount.words12)).asString();

    setState(() {
      mnemonic.text = res;
      displayText = res;
    });
  }

  Future<List<bdk.Descriptor>> getDescriptors(String mnemonicStr) async {
    final descriptors = <bdk.Descriptor>[];
    try {
      for (var e in [
        bdk.KeychainKind.externalChain,
        bdk.KeychainKind.internalChain
      ]) {
        final mnemonic = await bdk.Mnemonic.fromString(mnemonicStr);
        final descriptorSecretKey = await bdk.DescriptorSecretKey.create(
          network: bdk.Network.signet,
          mnemonic: mnemonic,
        );
        final descriptor = await bdk.Descriptor.newBip86(
            secretKey: descriptorSecretKey,
            network: bdk.Network.signet,
            keychain: e);
        descriptors.add(descriptor);
      }
      return descriptors;
    } on Exception catch (e) {
      setState(() {
        displayText = "Error : ${e.toString()}";
      });
      rethrow;
    }
  }

  createOrRestoreWallet(
    String mnemonic,
    bdk.Network network,
    String? password,
    String path, //TODO: Derived error: Address contains key path
  ) async {
    try {
      final descriptors = await getDescriptors(mnemonic);
      await blockchainInit();
      final res = await bdk.Wallet.create(
          descriptor: descriptors[0],
          changeDescriptor: descriptors[1],
          network: network,
          databaseConfig: const bdk.DatabaseConfig.memory());
      setState(() {
        wallet = res;
      });
      var addressInfo = getNewAddress();
      address = addressInfo.address.asString();
      setState(() {
        displayText = "Wallet Created: $address";
      });
    } on Exception catch (e) {
      setState(() {
        displayText = "Error: ${e.toString()}";
      });
    }
  }

  void getBalance() {
    final balanceObj = wallet.getBalance();
    final res = "Total Balance: ${balanceObj.total.toString()}";
    if (kDebugMode) {
      print(res);
    }
    setState(() {
      balance = balanceObj.total.toString();
      displayText = res;
    });
  }

  bdk.AddressInfo getNewAddress() {
    final res =
        wallet.getAddress(addressIndex: const bdk.AddressIndex.increase());
    if (kDebugMode) {
      print(res.address);
    }
    address = res.address.asString();
    setState(() {
      displayText = address;
      if (isReceiver && address != null) {
        recipientAddress.text = address!;
      }
    });
    return res;
  }

  Future<void> sendTx(String addressStr, int amount) async {
    try {
      final txBuilder = bdk.TxBuilder();
      final address = await bdk.Address.fromString(
          s: addressStr, network: bdk.Network.signet);
      final script = address.scriptPubkey();

      final psbt = await txBuilder
          .addRecipient(script, BigInt.from(amount))
          .feeRate(1.0)
          .finish(wallet);

      final isFinalized = wallet.sign(psbt: psbt.$1);
      if (isFinalized) {
        final tx = psbt.$1.extractTx();
        final res = await blockchain.broadcast(transaction: tx);
        debugPrint(res);
      } else {
        debugPrint("psbt not finalized!");
      }

      setState(() {
        displayText = "Successfully broadcast $amount Sats to $addressStr";
      });
    } on Exception catch (e) {
      setState(() {
        displayText = "Error: ${e.toString()}";
      });
    }
  }

/* const BlockchainConfig.electrum(
              config: ElectrumConfig(
                  stopGap: 10,
                  timeout: 5,
                  retry: 5,
                  url: "ssl://electrum.blockstream.info:60002",
                  validateDomain: false)) */
  ///Step2:Client
  blockchainInit() async {
    String esploraUrl = 'https://mutinynet.com/api';
    try {
      blockchain = await bdk.Blockchain.create(
          config: bdk.BlockchainConfig.esplora(
              config: bdk.EsploraConfig(
                  baseUrl: esploraUrl, stopGap: BigInt.from(10))));
    } on Exception catch (e) {
      setState(() {
        displayText = "Error: ${e.toString()}";
      });
    }
  }

  Future<void> syncWallet() async {
    await wallet.sync(blockchain: blockchain);
    getBalance();
  }

  Future<void> changePayjoin(bool value) async {
    setState(() {
      _isPayjoinEnabled = value;
    });
    // Reset the payjoin state when disabling it.
    // This is useful to start a new payjoin session by toggling the switch.
    if (!value) {
      resetPayjoinSession();
    }
  }

  Future<void> changeFrom(bool value) async {
    setState(() {
      isReceiver = value;
    });
  }

  Future<void> chooseFeeRange() async {
    feeRange = await showModalBottomSheet(
      context: context,
      builder: (context) => SelectFeeRange(feeRange: feeRange),
      constraints: const BoxConstraints.tightFor(height: 300),
    );
  }

  @override
  Widget build(BuildContext context) {
    final formKey = GlobalKey<FormState>();
    return Scaffold(
        resizeToAvoidBottomInset: true,
        backgroundColor: Colors.white,
        /* Header */
        appBar: buildAppBar(context),
        body: SingleChildScrollView(
          padding: const EdgeInsets.all(30),
          child: Column(
            children: [
              /* Balance */
              BalanceContainer(
                text: "$balance Sats",
              ),
              /* Result */
              ResponseContainer(
                text: displayText ?? " ",
              ),
              StyledContainer(
                  child: Column(
                      mainAxisAlignment: MainAxisAlignment.start,
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: [
                    SubmitButton(
                        text: "Generate Mnemonic",
                        callback: () async {
                          await generateMnemonicHandler();
                        }),
                    TextFieldContainer(
                      child: TextFormField(
                          controller: mnemonic,
                          style: Theme.of(context).textTheme.bodyLarge,
                          keyboardType: TextInputType.multiline,
                          maxLines: 5,
                          decoration: const InputDecoration(
                              hintText: "Enter your mnemonic")),
                    ),
                    SubmitButton(
                      text: "Create Wallet",
                      callback: () async {
                        await createOrRestoreWallet(mnemonic.text,
                            bdk.Network.signet, "password", "m/84'/1'/0'");
                      },
                    ),
                    SubmitButton(
                      text: "Sync Wallet",
                      callback: () async {
                        await syncWallet();
                      },
                    ),
                    SubmitButton(
                        callback: () {
                          getNewAddress();
                        },
                        text: "Get Address"),
                  ])),
              /* Send Transaction */
              StyledContainer(
                  child: Form(
                key: formKey,
                child: Column(
                    mainAxisAlignment: MainAxisAlignment.start,
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: [
                      CustomSwitchTile(
                        title: "Payjoin",
                        value: _isPayjoinEnabled,
                        onChanged: changePayjoin,
                      ),
                      _isPayjoinEnabled ? buildPayjoinFields() : buildFields(),
                      v2Session == null && sender == null
                          ? SubmitButton(
                              text: getSubmitButtonTitle,
                              callback: () async {
                                _isPayjoinEnabled
                                    ? performPayjoin(formKey)
                                    : await onSendBit(formKey);
                              },
                            )
                          : Row(
                              mainAxisAlignment: MainAxisAlignment.center,
                              mainAxisSize: MainAxisSize.min,
                              children: [
                                const CircularProgressIndicator(),
                                const SizedBox(width: 16),
                                Expanded(
                                  child: Text(
                                    v2Session != null
                                        ? payjoinProposal != null
                                            ? 'Proposal sent, waiting for tx...'
                                            : uncheckedProposal != null
                                                ? 'Received request, adding inputs to proposal...'
                                                : 'Session initiated, waiting for request...'
                                        : 'Request sent, waiting for proposal to finalize tx...',
                                  ),
                                ),
                              ],
                            ),
                    ]),
              ))
            ],
          ),
        ));
  }

  onSendBit(formKey) async {
    if (formKey.currentState!.validate()) {
      await sendTx(recipientAddress.text, int.parse(amountController.text));
    }
  }

  showBottomSheet(
    String text, {
    String? toCopy,
    String? toUrl,
  }) {
    return showModalBottomSheet(
      useSafeArea: true,
      context: context,
      builder: (context) => Padding(
        padding: const EdgeInsets.all(16.0),
        child: Row(
          children: [
            Expanded(child: Text(text)),
            if (toCopy != null && toCopy.isNotEmpty)
              IconButton(
                onPressed: () {
                  Clipboard.setData(ClipboardData(text: toCopy));
                  Navigator.pop(context);
                  ScaffoldMessenger.of(context).showSnackBar(const SnackBar(
                    content: Text('Copied to clipboard!'),
                  ));
                },
                icon: const Icon(
                  Icons.copy,
                  size: 36,
                ),
              ),
            if (toUrl != null && toUrl.isNotEmpty)
              IconButton(
                onPressed: () {
                  launchUrl(Uri.parse(toUrl));
                },
                icon: const Icon(
                  Icons.open_in_browser,
                  size: 36,
                ),
              ),
          ],
        ),
      ),
    );
  }

  Widget buildFields() {
    return Column(
      children: [
        TextFieldContainer(
          child: TextFormField(
            controller: recipientAddress,
            validator: (value) {
              if (value == null || value.isEmpty) {
                return 'Please enter your address';
              }
              return null;
            },
            style: Theme.of(context).textTheme.bodyLarge,
            decoration: const InputDecoration(
              hintText: "Enter Address",
            ),
          ),
        ),
        TextFieldContainer(
          child: TextFormField(
            controller: amountController,
            validator: (value) {
              if (value == null || value.isEmpty) {
                return 'Please enter the amount';
              }
              return null;
            },
            keyboardType: TextInputType.number,
            style: Theme.of(context).textTheme.bodyLarge,
            decoration: const InputDecoration(
              hintText: "Enter Amount",
            ),
          ),
        ),
      ],
    );
  }

  Widget buildPayjoinFields() {
    return Column(
      children: [
        CustomSwitchTile(
          title: isReceiver ? "Receiver" : "Sender",
          value: isReceiver,
          onChanged: changeFrom,
        ),
        if (isReceiver) ...[
          buildReceiverFields(),
        ] else
          ...buildSenderFields()
      ],
    );
  }

  List<Widget> buildSenderFields() {
    if (sender == null) {
      return [
        TextFieldContainer(
          child: TextFormField(
            controller: pjUriController,
            validator: (value) {
              if (value == null || value.isEmpty) {
                return 'Please enter the pjUri';
              }
              return null;
            },
            style: Theme.of(context).textTheme.bodyLarge,
            keyboardType: TextInputType.multiline,
            maxLines: 5,
            decoration: const InputDecoration(hintText: "Enter pjUri"),
          ),
        ),
        Center(
          child: TextButton(
            onPressed: () => chooseFeeRange(),
            child: const Text(
              "Choose fee range",
            ),
          ),
        ),
      ];
    }
    return [];
  }

  Widget buildReceiverFields() {
    return pjUri.isEmpty ? buildFields() : Container();
  }

  Future performPayjoin(formKey) async {
    if (formKey.currentState!.validate()) {
      if (isReceiver) {
        await performReceiver(receiverWallet: wallet);
      } else {
        await performSender();
      }
    }
  }

  //Sender
  Future performSender() async {
    // Build payjoin request with original psbt and send it to the
    //  payjoin directory where the receiver can poll it
    final pjUri = await payjoinManager.stringToUri(pjUriController.text);
    final originalPsbt = await payjoinManager.buildOriginalPsbt(
      wallet,
      pjUri,
      feeRange?.feeValue ?? FeeRangeEnum.high.feeValue,
    );
    final request = await payjoinManager.buildPayjoinRequest(
      originalPsbt,
      pjUri,
      feeRange?.feeValue ?? FeeRangeEnum.high.feeValue,
    );
    setState(() {
      sender = request;
    });

    // Request and keep polling the payjoin directoy for the proposal
    //  from the receiver
    String psbt = originalPsbt;
    try {
      psbt = await payjoinManager.requestAndPollV2Proposal(
        sender!,
      );
      debugPrint('Receiver proposed payjoin PSBT: $psbt');
    } catch (e) {
      // No proposal received, make a normal tx with the original psbt
      debugPrint('No proposal received, broadcasting original tx');
    }

    // If a proposal is received, finalize the payjoin
    final transaction = await payjoinManager.extractPjTx(wallet, psbt);
    final txId = await blockchain.broadcast(transaction: transaction);
    debugPrint('Broacasted tx: $txId');
    resetPayjoinSession();

    showBottomSheet(
      '${psbt == originalPsbt ? 'Original tx with id' : 'Payjoin tx with id'} '
      '$txId broadcasted!',
      toCopy: txId,
      toUrl: 'https://mutinynet.com/tx/$txId',
    );
  }

  //Receiver
  Future performReceiver({required bdk.Wallet receiverWallet}) async {
    try {
      await initReceiverSession();

      final httpClient = HttpClient();
      UncheckedProposal? proposal;
      while (proposal == null) {
        final (request, clientResponse) = await v2Session!.extractReq();
        final url = Uri.parse(request.url.asString());
        final httpRequest = await httpClient.postUrl(url);

        httpRequest.headers.set('Content-Type', request.contentType);

        httpRequest.add(request.body);

        final response = await httpRequest.close();
        final responseBody = await response.fold<List<int>>(
            [], (previous, element) => previous..addAll(element));
        final uint8Response = Uint8List.fromList(responseBody);
        proposal = await v2Session!
            .processRes(body: uint8Response, ctx: clientResponse);
      }

      setState(() {
        uncheckedProposal = proposal;
      });

      // Extract the original transaction from the proposal in case you want
      //  to broadcast it if the sender doesn't finalize the payjoin
      final originalTxBytes = await proposal.extractTxToScheduleBroadcast();
      final originalTx =
          await bdk.Transaction.fromBytes(transactionBytes: originalTxBytes);

      // Process the proposal through the various checks
      final maybeInputsOwned = await proposal.assumeInteractiveReceiver();

      final maybeInputsSeen = await maybeInputsOwned.checkInputsNotOwned(
          isOwned: (outpoint) async =>
              false // TODO Implement actual ownership check
          );

      final outputsUnknown = await maybeInputsSeen.checkNoInputsSeenBefore(
          isKnown: (outpoint) async => false // TODO Implement actual seen check
          );

      final wantsOutputs = await outputsUnknown.identifyReceiverOutputs(
          isReceiverOutput: (script) async {
        return receiverWallet.isMine(script: bdk.ScriptBuf(bytes: script));
      });

      var wantsInputs = await wantsOutputs.commitOutputs();

      // Select and contribute inputs
      final unspent = receiverWallet.listUnspent();
      List<InputPair> candidateInputs = [];
      for (var input in unspent) {
        final txout = TxOut(
          value: input.txout.value,
          scriptPubkey: input.txout.scriptPubkey.bytes,
        );
        final psbtin = PsbtInput(
            witnessUtxo: txout, redeemScript: null, witnessScript: null);
        final previousOutput = OutPoint(
            txid: input.outpoint.txid.toString(), vout: input.outpoint.vout);
        final txin = TxIn(
            previousOutput: previousOutput,
            scriptSig: await Script.newInstance(rawOutputScript: []),
            witness: [],
            sequence: 0);
        final ip = await InputPair.newInstance(txin, psbtin);
        candidateInputs.add(ip);
      }
      final inputPair = await wantsInputs.tryPreservingPrivacy(
          candidateInputs: candidateInputs);

      wantsInputs =
          await wantsInputs.contributeInputs(replacementInputs: [inputPair]);
      final provisionalProposal = await wantsInputs.commitInputs();

      final finalProposal = await provisionalProposal.finalizeProposal(
          processPsbt: (i) => payjoinManager.processPsbt(i, receiverWallet),
          maxFeeRateSatPerVb: BigInt.from(25));

      setState(() {
        payjoinProposal = finalProposal;
      });

      final proposalPsbt = await finalProposal.psbt();
      final proposalTxId = await payjoinManager.getTxIdFromPsbt(proposalPsbt);
      debugPrint('Receiver proposal tx: $proposalTxId');

      // Send the proposal via POST request to directory
      final (proposalReq, proposalCtx) = await finalProposal.extractV2Req();
      final httpRequest = await httpClient.postUrl(
        Uri.parse(proposalReq.url.asString()),
      );
      httpRequest.headers.set('content-type', 'message/ohttp-req');
      httpRequest.add(proposalReq.body);
      final response = await httpRequest.close();
      final responseBody = await response.fold<List<int>>(
        [],
        (previous, element) => previous..addAll(element),
      );
      await finalProposal.processRes(
          res: responseBody, ohttpContext: proposalCtx);

      // Wait for the payjoin transaction to be broadcasted by the sender
      //  Still possible the payjoin wasn't finalized and the original tx was
      //  broadcasted instead by the sender, so also check for that
      // You could also put a timeout on waiting for the transaction and then
      //  broadcast the original tx yourself if no transaction is received
      final receivedTxId = await waitForTransaction(
        originalTxId: originalTx.txid(),
        proposalTxId: proposalTxId,
      );
      resetPayjoinSession();

      if (receivedTxId.isNotEmpty) {
        showBottomSheet(
          '${receivedTxId == proposalTxId ? 'Payjoin' : 'Original'} tx received!',
          toCopy: receivedTxId,
          toUrl: 'https://mutinynet.com/tx/$receivedTxId',
        );
      }
    } catch (e) {
      debugPrint(e.toString());
      if (e is PayjoinException) {
        showBottomSheet('PayJoin error: ${e.message}');
        resetPayjoinSession();
      }
    }
  }

  Future<void> initReceiverSession() async {
    final amountSats = BigInt.parse(amountController.text);
    debugPrint('AMOUNT SATS: $amountSats');
    final payjoinDirectory = await pjuri.Url.fromStr("https://payjo.in");
    final ohttpRelay = await pjuri.Url.fromStr("https://pj.bobspacebkk.com");

    final ohttpKeys = await pjuri.fetchOhttpKeys(
      ohttpRelay: ohttpRelay,
      payjoinDirectory: payjoinDirectory,
    );
    debugPrint('OHTTP KEYS FETCHED ${ohttpKeys.toString()}');
    // Create receiver session with new bindings
    final receiver = await Receiver.create(
      address: recipientAddress.text,
      network: Network.signet,
      directory: payjoinDirectory,
      ohttpKeys: ohttpKeys,
      ohttpRelay: ohttpRelay,
      expireAfter: BigInt.from(60 * 5), // 5 minutes
    );
    debugPrint('INITIALIZED RECEIVER');

    final pjUrl =
        receiver.pjUriBuilder().amountSats(amount: amountSats).build();
    final pjStr = pjUrl.asString();
    debugPrint('PAYJOIN URL: $pjStr');

    setState(() {
      v2Session = receiver;
      displayText = pjStr;
      pjUri = pjStr;
    });
  }

  Future<String> waitForTransaction({
    required String originalTxId,
    required String proposalTxId,
    int timeout = 1,
  }) async {
    debugPrint('Waiting for payjoin tx to be sent...');
    await syncWallet();
    final txs = wallet.listTransactions(includeRaw: false);
    try {
      final tx = txs.firstWhere(
          (tx) => tx.txid == originalTxId || tx.txid == proposalTxId);
      debugPrint('Tx found: ${tx.txid}');
      return tx.txid;
    } catch (e) {
      debugPrint('Tx not found, retrying after $timeout second(s)...');
      if (v2Session == null) {
        // The session was canceled, stop polling
        return '';
      }
      await Future.delayed(Duration(seconds: timeout));
      return waitForTransaction(
        originalTxId: originalTxId,
        proposalTxId: proposalTxId,
      );
    }
  }

  void resetPayjoinSession() {
    setState(() {
      pjUri = '';
      v2Session = null;
      sender = null;
      uncheckedProposal = null;
      payjoinProposal = null;
    });
    // Also clean the text controllers to start a new payjoin session
    recipientAddress.clear();
    amountController.clear();
    pjUriController.clear();
    receiverPsbtController.clear();
    psbtController.clear();
  }
}
