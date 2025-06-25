import 'package:flutter/material.dart';

ThemeData theme() {
  Color secondaryColor = Colors.orange;
  Color primaryColor = Colors.blue.withValues(alpha: 0.8);
  return ThemeData(
      primaryColor: primaryColor,
      secondaryHeaderColor: secondaryColor,
      appBarTheme: const AppBarTheme(
        centerTitle: true,
        elevation: 0,
        backgroundColor: Colors.white,
      ),
      textTheme: TextTheme(
          displayLarge: const TextStyle(
              color: Colors.black, fontWeight: FontWeight.w900, fontSize: 18),
          displayMedium: const TextStyle(
              color: Colors.black, fontWeight: FontWeight.w900, fontSize: 14.5),
          bodyLarge: TextStyle(
              color: Colors.black.withValues(alpha: 0.8),
              fontWeight: FontWeight.w500,
              fontSize: 12),
          labelLarge: const TextStyle(
              color: Colors.white, fontWeight: FontWeight.w800, fontSize: 13)),
      inputDecorationTheme: InputDecorationTheme(
        border: InputBorder.none,
        contentPadding: const EdgeInsets.symmetric(horizontal: 10, vertical: 5),
        hintStyle: TextStyle(
            color: Colors.black.withValues(alpha: 0.4),
            fontWeight: FontWeight.w500,
            fontSize: 10),
      ));
}
