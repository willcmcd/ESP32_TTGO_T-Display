# Display Test
After some difficulty getting the display working in a different sketch, I decided to break down the problem.  Ultimately, I found that I had not properly configured the TFT_eSPI library, and that I hadn't selected the correct board when programming.

### TFT_eSPI Config
The TFT_eSPI library provides a large number of 'User Setup' header files, which can be selected by commenting out the default setup include, and uncommenting the desired one in the file `Documents/Arduino/libraries/TFT_eSPI/User_Setup_Select.h`.  The library author has provided this functionality to assist the writing of portable code.

```cpp
// to get display to work when using LilyGo TTGO T-Display, find and uncomment the following line
// in the TFT_eSPI User_Setup_Select.h file. [Documents/arduino/libraries/TFT_eSPI/]
// #include <User_Setups/Setup26_TTGO_T_Display.h>
```

### Board 
I was mistaken in my selection of board in the build step.  Originally I was using the generic `ESP32 Dev Module`, which didn't provide the correct pin defines for the TFT_eSPI library to pick up.  It took some internet searching to find that I should instead be using the 'TTGO LoRa32-OLED', as there doesn't appear to be a board configuration for my exact device.
