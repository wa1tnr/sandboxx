NOTE.md

Mon 21 Feb 12:52:17 UTC 2022

It was unclear which LCD library was preferred, when
this project was constructed (in February 2022).

The lib was chosen based on what someone else had
asked about; there is an internal LCD library in
the Arduino IDE that may or may not be a close
match to this lib (this wasn't checked at all).

EDIT: checked - they are not the same - this one
is i2c whereas the Arduino IDE 'stock' lib seems
to be data-pin driven:

exhibit

```
// LiquidCrystal.cpp

 41 LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
 42                              uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
 43 {
 44   init(1, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);
 45 }
```

The Arduino IDE stores at least one version of
this library; in the reference PC's installation,
this was found here:

    ~/arduino-1.8.19/libraries/LiquidCrystal/

Comparison is left to the end-user to perform,
as the present project is working fine as-is. ;)

See also:

    https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library.git

END.
