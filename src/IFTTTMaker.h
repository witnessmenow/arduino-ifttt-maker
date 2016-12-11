/*

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/


#ifndef IFTTTMaker_h
#define IFTTTMaker_h

#include <Arduino.h>
#include <Client.h>
#include <ArduinoJson.h>

#define HOST "maker.ifttt.com"
#define SSL_PORT 443


class IFTTTMaker
{
  public:
    IFTTTMaker (String key, Client &client);
    String sendTriggerEvent(String eventName);
    String sendTriggerEventWithData(String eventName, JsonObject& payload);
    bool triggerEvent(String eventName, String value1 = "", String value2 = "", String value3= "");

  private:
    String _key;
    Client *client;
    const int maxMessageLength = 1000;
    bool checkForSucessResponse(String response);
};

#endif
