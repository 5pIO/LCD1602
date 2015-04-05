Hello!

Keeping in with last weeks post on the 7 Segment display, we will play around with a few more displays. There are many different types of displays. This post will focus on a type of LCD called a Character LCD.

### Things Needed
*	A 1602(or similar) Character LCD Display
*	An MCU(Pi/Arduino/Beaglebone Black)

###Introduction
This is an LCD display, that unlike a graphical LCD, can only display characters. The display I am using is a 16 pin 1602 Character LCD display. This display has 2 rows of 16 characters/columns each. I got it as a part of the [KEYES Learning Kit for Raspberry Pi](http://www.dx.com/p/keyes-diy-board-learning-kit-for-raspberry-pi-translucent-multicolored-357738#.VSEiKhOUeQw) but it can also be ordered standalone from [ICStation](http://icstation.com). This tutorial should work for most character LCDs with the same instruction set.

A character display like this has 11 bus lines.

*	D0-D7, which are the data lines.
* 	RW, which tells the LCD if we are reading or writing to it.
*	EN, which we use to tell the LCD when data is ready for reading.
*	RS, which lets the MCU tell the LCD whether the data sent is for displaying or is a command byte.

The VO pin on the display must also be connected to a potentiometer between VCC and GND which acts as the contrast adjustment knob.

Even though there are 8 data lines, we can talk to this LCD using just 4. I, honestly, don't even know why there are 8 pins on it as I have not seen a visible difference between using 4 or 8.

We can look up the datasheet for the LCD, and it will tell us what data to send it for different characters as well as for command instructions(Clear, Cursor shift etc). To make our lives easier we will be using libraries that have already been built by others so that we can get up and running in just a few steps, no matter which MCU we use.


###Raspberry Pi
####Setup
For the Raspberry Pi, we will be using a [library](https://github.com/adafruit/Adafruit_Python_CharLCD) made by the good folks over at [Adafruit](http://adafruit.com). To set it up, you just need to do run the following steps:

*	Clone the git repository with a `git clone https://github.com/adafruit/Adafruit_Python_CharLCD`.
*	Make sure you have the RPi.GPIO library with a `sudo pip install RPi.GPIO`.
*  	Install the Adafruit library with `sudo python setup.py install`.

The wiring should look something like this:
<img src="/content/images/2015/04/Pi1604.png" width=400 />

####Code
Beacuse the library does most of the heavy lifting, all we need to define in the code is the pins we are using to connect to the dispay and the number of rows and columns in our display and then initialize the display. It should look something like this:
```
import Adafruit_CharLCD as LCD

# Raspberry Pi pin configuration:
lcd_rs        = 25  # Note this might need to be changed to 21 for older revision Pi's.
lcd_en        = 24
lcd_d4        = 23
lcd_d5        = 17
lcd_d6        = 27
lcd_d7        = 22
lcd_backlight = 4

# Define LCD column and row size for 16x2 LCD.
lcd_columns = 16
lcd_rows    = 2

# Initialize the LCD using the pins above.
lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7,
                           lcd_columns, lcd_rows, lcd_backlight)

# Print a two line message
lcd.message('Welcome to\n5P.IO')

```

Thats all! The final product should look something like this:
<img src="/content/images/2015/04/IMG_0022.JPG" width=400/>

###Beaglebone Black
####Setup
The folks over at Adafruit have done an awesome job by making the library basically the same for the BBB. To set it up you need to run the following steps:

*	Clone the git repository with a `git clone https://github.com/adafruit/Adafruit_Python_CharLCD`.
*	Make sure you have the RPi.GPIO library with a `sudo pip install Adafruit_BBIO`.
*  	Install the Adafruit library with `sudo python setup.py install`.

The wiring should look similar to this:
<img src="/content/images/2015/04/bbb1602.png" width=400 />

####Code
Once again the all the heavy lifting is done by the library. All we need to do is define the pins we are using to connect to the dispay and the number of rows and columns in our display and then initialize the display. It should look something like this:
```
import Adafruit_CharLCD as LCD

# Beaglebone Black Pin Configuration
lcd_rs        = 'P8_8'
lcd_en        = 'P8_10'
lcd_d4        = 'P8_18'
lcd_d5        = 'P8_16'
lcd_d6        = 'P8_14'
lcd_d7        = 'P8_12'
lcd_backlight = 'P8_7'

# Define LCD column and row size for 16x2 LCD.
lcd_columns = 16
lcd_rows    = 2

# Initialize the LCD using the pins above.
lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7,
                           lcd_columns, lcd_rows, lcd_backlight)

# Print a two line message
lcd.message('Welcome to\n5P.IO')

```
Once again, thats it! The final product should look something like this:
<img src="/content/images/2015/04/IMG_0026.JPG" width=400/>

###Arduino
####Setup
For the Arduino, we will be using the awesome [LiquidCrystal](http://http://playground.arduino.cc/Main/LiquidCrystal) library which is shipped with the Arduiono IDE. As it is already shipped with the IDE there are no additional steps required to set it up.

The wiring I used is:
<img src="/content/images/2015/04/Arduino1602-1.png" width=400 />

####Code
Just as with the Pi and the BBB, the library does most of the heavy lifting. All that needs to be done is Initialize an object of the LiquidCrystal [class](http://arduino.cc/en/Reference/LiquidCrystalConstructor) with the correct pin numbers. We then must `begin` the LCD with the correct number of columns and rows. The code should like:

```
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome to");
  lcd.setCursor(0,1);
  lcd.print("5P.IO");
}

void loop() {

}
```

The final product should like like this:
<img src="/content/images/2015/04/IMG_0027.JPG" width=400 />
