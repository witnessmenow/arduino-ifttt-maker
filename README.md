# arduino-ifttt-maker
A library for raising events on the maker service on IFTTT. (Basically create the "this" in an IFTTT from your arduino)

## Installing

The downloaded code can be included as a new library into the IDE selecting the menu:

     Sketch / include Library / Add .Zip library

Include IFTTTMaker in your project:

    #include <IFTTTMaker.h>

and pass it a Maker service key (you can find it [here](https://ifttt.com/services/maker/settings)) and a SSL Client (See the examples for more details)

    #define KEY "zzzzzzzzzzzzzzzzzzzzzzz"
    // WiFiSSLClient client; //For 101 boards
    WiFiClientSecure client; //For ESP8266 boards
    IFTTTMaker ifttt(KEY, client);

    ifttt.triggerEvent(EVENT_NAME); //returns true if successful

*NOTE:* This library has not been tested with the 101 boards as I do not have a compatible board. If you can help please let me know!
