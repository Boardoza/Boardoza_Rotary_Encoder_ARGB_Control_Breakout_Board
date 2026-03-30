#ifndef EC1101S_H
#define EC1101S_H

#include "Arduino.h"

class EC1101S {
public:
    EC1101S(uint8_t pinA, uint8_t pinB, uint8_t pinSW);
    void begin();
    uint8_t getCount() const;
    void update();
    void setMaxCount(uint8_t maxVal);
    void setCount(uint8_t val);
private:
    static void IRAM_ATTR isrA(); // interrupt routine
    void checkEncoder(); // control function
    static EC1101S* instance_;

    uint8_t _pinA;
    uint8_t _pinB;
    uint8_t terminalA;
    uint8_t terminalB;
    uint8_t _pinSW;

    volatile uint8_t _prevA;
    volatile uint8_t _prevB;

    volatile uint8_t _count;
    volatile uint8_t _click;
    volatile uint8_t _CW; // CW=1 clockwise, 0 counterclockwise
    volatile uint8_t _debounce;
    uint8_t _maxCount;
};

#endif