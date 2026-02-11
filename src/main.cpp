/**
 * @file main.cpp
 * @brief This file contains the main logic for interfacing an OLED display with an Arduino.
 *
 * This program initializes an SSD1306 OLED display and prints a message on it.
 *
 * @author Kashish Gupta
 * @date 2024-07-27
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/**
 * @def SCREEN_WIDTH
 * @brief Width of the OLED display in pixels.
 */
#define SCREEN_WIDTH 128

/**
 * @def SCREEN_HEIGHT
 * @brief Height of the OLED display in pixels.
 */
#define SCREEN_HEIGHT 64

/**
 * @def OLED_ADDRESS
 * @brief I2C address of the OLED display.
 */
#define OLED_ADDRESS 0x3C

/**
 * @brief Adafruit_SSD1306 display object.
 *
 * This object is used to control the OLED display.
 */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

/**
 * @brief Setup function.
 *
 * This function is called once when the Arduino starts up. It initializes the serial communication,
 * the OLED display, and prints a message on the display.
 */
void setup() {
    // write your initialization code here
    Serial.begin(9600);
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
        Serial.println(F("OLED not found"));
        while (true);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Arduino Uno R4");
    display.println("OLED with I2C");
    display.println("kashish vansh ved ayush");
    display.display();
}

/**
 * @brief Loop function.
 *
 * This function is called repeatedly after the setup function has completed. It is empty in this
 * example.
 */
void loop() {
// write your code here

}