import 'package:flutter/material.dart';

ThemeData theme() {
  Color secondaryColor = Colors.orange;
  Color primaryColor = Colors.blue;
  return ThemeData(
      primaryColor: primaryColor,
      secondaryHeaderColor: secondaryColor,
      appBarTheme: const AppBarTheme(
        centerTitle: true,
        elevation: 0,
        backgroundColor: Colors.white,
      ),
      textTheme: const TextTheme(
          displayLarge: TextStyle(
              color: Colors.black, fontWeight: FontWeight.w900, fontSize: 18),
          displayMedium: TextStyle(
              color: Colors.black, fontWeight: FontWeight.w900, fontSize: 14.5),
          bodyLarge: TextStyle(
              color: Colors.black, fontWeight: FontWeight.w500, fontSize: 12),
          labelLarge: TextStyle(
              color: Colors.white, fontWeight: FontWeight.w800, fontSize: 13)),
      inputDecorationTheme: const InputDecorationTheme(
        border: InputBorder.none,
        contentPadding: EdgeInsets.symmetric(horizontal: 10, vertical: 5),
        hintStyle: TextStyle(
            color: Colors.black45, fontWeight: FontWeight.w500, fontSize: 10),
      ));
}
