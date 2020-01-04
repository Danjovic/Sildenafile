/////////////////////////////////////////////////////////////////
/*                                                             */
/*                                                             */
/*          Configure your screen settings here                */
/*    Delete the // of the lines appropriate to your device    */
/*                                                             */
/*                                                             */
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
//
// Display Type
//

//#define LCDSCREEN16x2   1         /*Set if you are using a 1602 LCD screen */
//#define LCD_I2C_ADDR    0x27      /*Set the i2c address of your 1602LCD usually 0x27 or 0x3f*/

#define OLED1306       1          /*Defines if you are using a 128x64 or 128x32 OLED screen */
//#define OLED1306_0.91  1          /*Defines if you are using a 0.91" 128x32 screen.*/
//#define OLED1306_1.3   1          /* Use this line as well if you have a 1.3" OLED screen */

//#define P8544   1                 /*Set if you are using an 84x48 PCD8544 screen */

//#define LCD_USE_1602_LCD_MODULE  1 /*Not used at the moment */

//#define SERIALSCREEN  1           /*For Testing purposes only */

/////////////////////////////////////////////////////////////////
//
// Logotype
//
#define TZXDuino_Logo  1

/////////////////////////////////////////////////////////////////
//
// I/O pins
//
#if defined(__AVR__)
//
// Pin definition for Arduino boards
//
#define chipSelect    10            //Sd card chip select pin
#define btnPlay       17            //Play Button
#define btnStop       16            //Stop Button
#define btnUp         15            //Up button
#define btnDown       14            //Down button
#define btnMotor      6             //Motor Sense (connect pin to gnd to play, NC for pause)
#define btnRoot       7             //Return to SD card root
#define outputPin     9              // Audio Output PIN - Set accordingly to your hardware.
#define outputPinPORT PORTB
#define outputPinBIT  PORTB1

#elif defined(__arm__) && defined(__STM32F1__)
//
// Pin definition for Blue Pill boards
//

#define chipSelect    PB12            //Sd card chip select pin

#define btnPlay       PA0           //Play Button
#define btnStop       PA1           //Stop Button
#define btnUp         PA2           //Up button
#define btnDown       PA3           //Down button
#define btnRoot       PA4           //Return to SD card root

#define btnMotor      PA8     //Motor Sense (connect pin to gnd to play, NC for pause)
#define outputPin     PA9    // this pin is 5V tolerant and PWM output capable

#endif
