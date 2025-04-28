import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class SubmitButton extends StatelessWidget {
  final String text;
  final VoidCallback callback;

  const SubmitButton({Key? key, required this.text, required this.callback})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: callback,
      child: Container(
        margin: const EdgeInsets.only(bottom: 5),
        decoration: BoxDecoration(
            color: Theme.of(context).primaryColor,
            borderRadius: BorderRadius.circular(5)),
        padding: const EdgeInsets.symmetric(vertical: 10, horizontal: 20),
        width: double.infinity,
        child: Center(
          child: Text(text, style: Theme.of(context).textTheme.labelLarge),
        ),
      ),
    );
  }
}

class TextFieldContainer extends StatelessWidget {
  final Widget child;

  const TextFieldContainer({Key? key, required this.child}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.only(bottom: 2.5),
      decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(10),
          border: Border.all(width: 2, color: Theme.of(context).primaryColor)),
      child: child,
    );
  }
}

class StyledContainer extends StatelessWidget {
  final Widget child;

  const StyledContainer({Key? key, required this.child}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.only(bottom: 5),
      padding: const EdgeInsets.symmetric(vertical: 10, horizontal: 50),
      decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(10),
          border: Border.all(
            width: 2,
            color: Theme.of(context).primaryColor,
          )),
      child: child,
    );
  }
}

class BalanceContainer extends StatelessWidget {
  final String text;

  const BalanceContainer({Key? key, required this.text}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
        margin: const EdgeInsets.only(bottom: 5),
        padding: const EdgeInsets.symmetric(vertical: 5, horizontal: 5),
        width: double.infinity,
        child: StyledContainer(
          child: SelectableText.rich(
            TextSpan(
              children: <TextSpan>[
                TextSpan(
                    text: "Balance: ",
                    style: Theme.of(context).textTheme.displayMedium),
                TextSpan(
                    text: text, style: Theme.of(context).textTheme.bodyLarge),
              ],
            ),
          ),
        ));
  }
}

class ResponseContainer extends StatelessWidget {
  final String text;

  const ResponseContainer({Key? key, required this.text}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
        margin: const EdgeInsets.only(bottom: 5),
        padding: const EdgeInsets.symmetric(vertical: 5, horizontal: 5),
        width: double.infinity,
        child: StyledContainer(
          child: SelectableText.rich(
            TextSpan(
              children: <TextSpan>[
                TextSpan(
                    text: "Response: ",
                    style: Theme.of(context).textTheme.displayMedium),
                TextSpan(
                    text: text, style: Theme.of(context).textTheme.bodyLarge),
              ],
            ),
          ),
        ));
  }
}

AppBar buildAppBar(BuildContext context) {
  return AppBar(
    leadingWidth: 80,
    actions: [
      Padding(
        padding: const EdgeInsets.only(right: 20, bottom: 10, top: 10),
        child: Image.asset("assets/pdk_logo.png"),
      )
    ],
    leading: Icon(
      CupertinoIcons.bitcoin_circle_fill,
      color: Theme.of(context).secondaryHeaderColor,
      size: 40,
    ),
    title:
        Text("Payjoin Demo", style: Theme.of(context).textTheme.displayLarge),
  );
}

class SelectFeeRange extends StatelessWidget {
  const SelectFeeRange({super.key, this.feeRange});
  final FeeRangeEnum? feeRange;
  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        const Padding(
          padding: EdgeInsets.symmetric(horizontal: 24, vertical: 8),
          child: Text(
            'Choose a Fee Range',
          ),
        ),
        FeesRangeOptions(
          feeRange: feeRange,
        ),
      ],
    );
  }
}

enum FeeRangeEnum {
  high('High', 2000),
  medium('Medium', 1000),
  low('Low', 500);

  final String name;
  final int feeValue;

  const FeeRangeEnum(this.name, this.feeValue);

  @override
  String toString() => '$feeValue sats';
}

class FeesRangeOptions extends StatefulWidget {
  const FeesRangeOptions(
      {super.key, this.feeRange = FeeRangeEnum.high, this.onFeeRangeChanged});
  final FeeRangeEnum? feeRange;
  final Function(FeeRangeEnum?)? onFeeRangeChanged;
  @override
  State<FeesRangeOptions> createState() => _FeesRangeOptionsState();
}

class _FeesRangeOptionsState extends State<FeesRangeOptions> {
  @override
  Widget build(BuildContext context) {
    return Column(
      children: <Widget>[
        RadioListTile<FeeRangeEnum>(
          title: ListTile(
            title: Text(FeeRangeEnum.high.name),
            subtitle: const Text('10 - 30 minutes'),
            trailing: Text(FeeRangeEnum.high.toString()),
          ),
          value: FeeRangeEnum.high,
          groupValue: widget.feeRange,
          onChanged: onChangeFeeRange,
        ),
        RadioListTile<FeeRangeEnum>(
          title: ListTile(
            title: Text(FeeRangeEnum.medium.name),
            subtitle: const Text('30 - 60 minutes'),
            trailing: Text(FeeRangeEnum.medium.toString()),
          ),
          value: FeeRangeEnum.medium,
          groupValue: widget.feeRange,
          onChanged: onChangeFeeRange,
        ),
        RadioListTile<FeeRangeEnum>(
          title: ListTile(
            title: Text(FeeRangeEnum.low.name),
            subtitle: const Text('2 - 12 hours'),
            trailing: Text(FeeRangeEnum.low.toString()),
          ),
          value: FeeRangeEnum.low,
          groupValue: widget.feeRange,
          onChanged: onChangeFeeRange,
        ),
      ],
    );
  }

  onChangeFeeRange(FeeRangeEnum? value) {
    if (widget.onFeeRangeChanged != null) {
      widget.onFeeRangeChanged!(value);
    }
    Navigator.pop(context, value);
  }
}

class CustomSwitchTile extends StatelessWidget {
  const CustomSwitchTile(
      {super.key,
      required this.title,
      required this.onChanged,
      required this.value});
  final String title;
  final bool value;
  final Function(bool) onChanged;
  @override
  Widget build(BuildContext context) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        Text(
          title,
          style: Theme.of(context).textTheme.bodyLarge,
        ),
        Align(
          alignment: Alignment.centerRight,
          child: Switch(
            value: value,
            onChanged: onChanged,
          ),
        ),
      ],
    );
  }
}
