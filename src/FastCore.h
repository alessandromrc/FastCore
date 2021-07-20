/*
  FastCore.h - Improvement of the Arduino Core Functions.
  Created by alessandromrc, 20 July 2021.
*/


#ifndef FastCore_h
#define FastCore_h

class FastCore {
  #define PB 1
  #define PC 2
  #define PD 3
  #define PDmin 0
  #define PDmax 7
  #define PBmin 8
  #define PDmax 13
  #define PCmin 14
  #define PCmax 19
  public:
    const int BitmaskConversion(const int pin) {
      // PD Bitmask conversion
      if (PDmin >= 0 && PDmax <= 7) {
        return PD;
      }

      // PB Bitmask conversion
      if (PBmin >= 8 && PDmax <= 13) {
        return PB;
      }

      // PC Bitmask conversion
      if (PCmin >= 14 && PCmax <= 19) {
        return PC;
      }
    }

  const void FastWrite(const int pin,
    const bool state) {
    if (state) {
      // Pin goes high
      if (BitmaskConversion(pin) == PB) {
        PORTB |= _BV(pin - PBmin);
      } else if (BitmaskConversion(pin) == PC) {
        PORTC |= _BV(pin - PCmin);
      } else if (BitmaskConversion(pin) == PD) {
        PORTD |= _BV(pin);
      }
    } else {
      // Pin goes low
      if (BitmaskConversion(pin) == PB) {
        PORTB &= ~_BV(pin - PBmin);
      } else if (BitmaskConversion(pin) == PC) {
        PORTC &= ~_BV(pin - PCmin);
      } else if (BitmaskConversion(pin) == PD) {
        PORTD &= ~_BV(pin);
      }
    }
  }
};

#endif