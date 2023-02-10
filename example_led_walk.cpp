#include <random>
#include <Arduino.h>

/**
 * Class to control a single LED, with its brightness
 * varying as a random walk between the min and max parameters.
 * At each step, the brightness is increased or decreased by a
 * random amount, bounded by the step parameter.
 */
class LEDRandomWalk {
    public:
        /**
         * Constructor.
         * @param pin The pin to which the LED is connected.
         * @param min The minimum brightness of the LED.
         * @param max The maximum brightness of the LED.
         * @param step The maximum amount by which the brightness can change at each step.
         */
        LEDRandomWalk(int pin, int min, int max, int step) : pin(pin), min(min), max(max), step(step) {
            // Set the pin to output mode.
            pinMode(pin, OUTPUT);
            // Set the initial brightness to the minimum.
            brightness = min;
        }

        /**
         * Step the LED.
         * This method should be called repeatedly to update the LED.
         */
        void step() {
            // Update the brightness by a random amount.
            brightness += random(-step, step);
            // Constrain the brightness to the min and max values.
            brightness = constrain(brightness, min, max);
            // Set the LED brightness.
            analogWrite(pin, brightness);
        }

        /**
         * Temporarily turn off the LED by setting its brightness to zero.
         */
        void off() {
            brightness = 0;
            analogWrite(pin, 0);
        }


    private:
        int pin;
        int min;
        int max;
        int step;
        int brightness;
};


// EOF

## Same thing but in Python

class LEDRandomWalk:
    def __init__(self, pin, min, max, step):
        self.pin = pin
        self.min = min
        self.max = max
        self.step = step
        self.brightness = min
        self.off()

    def step(self):
        self.brightness += random.randint(-self.step, self.step)
        self.brightness = max(self.min, min(self.max, self.brightness))
        analogWrite(self.pin, self.brightness)

    def off(self):
        self.brightness = 0
        analogWrite(self.pin, 0)
