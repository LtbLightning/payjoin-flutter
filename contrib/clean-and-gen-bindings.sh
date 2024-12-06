#!/bin/bash

# Delete generated files in lib/src/generated
echo "Deleting generated files in lib/src/generated..."
rm -rf lib/src/generated/*

# Delete generated files in rust/src/frb_generated
echo "Deleting generated files in rust/src/frb_generated..."
rm -rf rust/src/frb_generated*

# Clean the Flutter project
echo "Running flutter clean..."
flutter clean

# Get Flutter dependencies
echo "Running flutter pub get..."
flutter pub get

# Run make all
echo "Running make all..."
make all

echo "Script execution completed."