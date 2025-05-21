Pod::Spec.new do |s|
  s.name             = 'payjoin_flutter'
  s.version          = '0.23.0'
  s.summary          = 'A new Flutter FFI plugin project.'
  s.description      = <<-DESC
A new Flutter FFI plugin project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }

  s.source           = { :path => '.' }
  s.source_files     = 'Classes/**/*'
  s.script_phase = {
  :name => 'Build Rust library',
  :script => 'sh "$PODS_TARGET_SRCROOT/../cargokit/build_pod.sh" ../rust payjoin_flutter',
  :execution_position => :before_compile,
  :input_files => ['${BUILT_PRODUCTS_DIR}/cargokit_phony'],
  :output_files => ["${BUILT_PRODUCTS_DIR}/libpayjoin_flutter.a"],
  }
  s.pod_target_xcconfig = {
  'DEFINES_MODULE' => 'YES',
  # Flutter.framework does not contain a i386 slice.
  'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386',
  'OTHER_LDFLAGS' => '-force_load ${BUILT_PRODUCTS_DIR}/libpayjoin_flutter.a',
  }
end