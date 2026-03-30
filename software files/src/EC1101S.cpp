#include "EC1101S.h"

EC1101S* EC1101S::instance_ = nullptr;

/**
 * @brief Constructor for the EC1101S class.
 *
 * Initializes an EC1101S object by assigning the specified pins for the rotary encoder
 * and setting default values for internal variables. This constructor prepares the
 * object for use with a rotary encoder that includes A, B, and optional button pins.
 *
 * @param pinA The pin number connected to the A terminal of the rotary encoder.
 * @param pinB The pin number connected to the B terminal of the rotary encoder.
 * @param pinSW The pin number connected to the button switch of the rotary encoder (optional).
 *
 * Example usage:
 * @code
 * EC1101S encoder(33, 21, 22);  // A: Pin 33, B: Pin 21, SW: Pin 22
 * @endcode
 */
EC1101S::EC1101S(uint8_t pinA, uint8_t pinB, uint8_t pinSW) :
  _pinA(pinA),
  _pinB(pinB),
  _pinSW(pinSW),
  _prevA(0),
  _prevB(0),
  _count(0),
  _click(0),
  _CW(0),
  _debounce(0),
  _maxCount(100)
{ }

/**
 * @brief Initializes the EC1101S rotary encoder.
 *
 * This function configures the rotary encoder pins, sets up their initial states,
 * and attaches an interrupt to handle changes on the A pin. It should be called
 * before using any other functions of the EC1101S class.
 * 
 * Example usage:
 * @code
 * encoder.begin();              // Initialize the encoder
 * @endcode
 */
void EC1101S::begin()
{
    instance_ = this;  // Tek encoder kullanacaksak bu pointer yeterli

    // Pin ayarları
    pinMode(_pinA, INPUT_PULLUP);
    pinMode(_pinB, INPUT_PULLUP);
    pinMode(_pinSW, INPUT_PULLUP);

    // Önceki pin değerlerini okuyalım
    _prevA = digitalRead(_pinA);
    _prevB = digitalRead(_pinB);

    // Interrupt ekle
    attachInterrupt(digitalPinToInterrupt(_pinA), EC1101S::isrA, CHANGE);
}

/**
 * @brief Sets the maximum count value for the rotary encoder.
 *
 * This function defines the upper limit for the encoder's count value. 
 * When the count reaches this value, it will not increment further.
 *
 * @param maxVal The maximum count value to set.
 *
 * Example usage:
 * @code
 * encoder.setMaxCount(100);  // Set the maximum count to 100
 * @endcode
 */
void EC1101S::setMaxCount(uint8_t maxVal)
{
    _maxCount = maxVal;
}

/**
 * @brief Sets the current count value for the rotary encoder.
 *
 * This function allows manually setting the current count value. 
 * It can be used to reset the count or initialize it to a specific value.
 *
 * @param val The count value to set.
 *
 * Example usage:
 * @code
 * encoder.setCount(50);  // Set the current count to 50
 * @endcode
 */
void EC1101S::setCount(uint8_t val)
{
    _count = val;
}

/**
 * @brief Gets the current count value of the rotary encoder.
 *
 * This function retrieves the current count value, which is updated
 * based on the rotary encoder's movements.
 *
 * @return The current count value.
 *
 * Example usage:
 * @code
 * uint8_t count = encoder.getCount();  // Get the current count value
 * @endcode
 */
uint8_t EC1101S::getCount() const
{
    return _count;
}

/**
 * @brief Updates the rotary encoder's state and adjusts the count value.
 *
 * This function processes the rotary encoder's state changes, applies debounce logic,
 * and increments or decrements the count value based on the rotation direction.
 * It should be called regularly in the `loop` function to ensure the encoder's state
 * is up to date.
 *
 * Example usage:
 * @code
 * while (true) {
 *     encoder.update();  // Update the encoder state
 * }
 * @endcode
 */
void EC1101S::update()
{
    // Debounce sayacını azalt
    if (_debounce)
    {
        _debounce--;
    }

    // Tıklama (döndürme) olduysa, count değerini ayarla
    if (_click)
    {
        if (_CW)
        {
            if (_count < _maxCount)
            {
                _count++;
            }
        }
        else
        {
            if (_count > 0)
            {
                _count--;
            }
        }
        _click = 0; // İşledikten sonra sıfırla
    }
}

/**
 * @brief Interrupt service routine (ISR) for the A pin of the rotary encoder.
 *
 * This function is triggered whenever a state change occurs on the A pin of the rotary encoder.
 * As it is declared as `static`, it uses the singleton `instance_` to call the `checkEncoder` 
 * method for processing the encoder's state. The function is designed to work with the `attachInterrupt`
 * mechanism.
 *
 * @note This function is marked with `IRAM_ATTR` to ensure it runs from IRAM, 
 * as required for interrupt handlers in some microcontrollers (e.g., ESP32).
 *
 * Example usage:
 * @code
 * attachInterrupt(digitalPinToInterrupt(33), EC1101S::isrA, CHANGE);
 * @endcode
 */
void IRAM_ATTR EC1101S::isrA()
{
    // Bu static fonksiyon, instance_ üzerinden sınıf içi fonksiyonu çağırır
    if (instance_ != nullptr)
    {
        instance_->checkEncoder();
    }
}

/**
 * @brief Processes the rotary encoder state to determine direction and update state variables.
 *
 * This function reads the current state of the rotary encoder's A and B pins and checks
 * for changes. It determines the direction of rotation (clockwise or counter-clockwise)
 * based on the pin states and updates internal variables accordingly. It is typically
 * called by the interrupt service routine `EC1101S::isrA`.
 *
 * @note This function is called internally and should not be called directly in most cases.
 *
 * Example usage (indirect):
 * @code
 * void IRAM_ATTR EC1101S::isrA()
 * {
 *     if (instance_ != nullptr)
 *     {
 *         instance_->checkEncoder();  // Calls this function
 *     }
 * }
 * @endcode
 */
void EC1101S::checkEncoder()
{   
    terminalA = digitalRead(_pinA);
    terminalB = digitalRead(_pinB);
    
    // Hem A hem B'deki değişimi kontrol et
    if ((_prevA != terminalA) || (_prevB != terminalB))
    {
        // Eğer A pininde değişiklik olduysa
        if (_prevA != terminalA)
        {
            // Yön hesaplama:
            if ((terminalB && !terminalA) ||
                (!terminalB && terminalA))
            {
                _CW = 1; // saat yönü
            }
            else
            {
                _CW = 0; // saat tersi
            }

            _prevA = terminalA;
            _prevB = terminalB;
            _click = 1; 
        }
        else
        {
            // Eğer B pininde değişiklik olduysa
            if ((!terminalB && terminalA) ||
                (terminalB && !terminalA))
            {
                _CW = 0;
            }
            else
            {
                _CW = 1;
            }
            _prevB = terminalA;
            _prevB = terminalB;
            _click = 1;
        }
    }
}