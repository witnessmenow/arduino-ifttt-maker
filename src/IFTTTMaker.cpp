
/*
Copyright (c) 2015 Giancarlo Bacchio. All right reserved.

TelegramBot - Library to create your own Telegram Bot using
ESP8266 on Arduino IDE.
Ref. Library at https:github/esp8266/Arduino

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


#include "IFTTTMaker.h"

IFTTTMaker::IFTTTMaker(String key, Client &client)	{
  _key = key;
  this->client = &client;
}

String IFTTTMaker::sendTriggerEvent(String eventName) {
	String response="";
  bool finishedHeaders = false;
  bool currentLineIsBlank = true;
	long now;
	bool avail;
	// Connect with IFTTT
	if (client->connect(HOST, SSL_PORT)) {
		//Serial.println(".... connected to server");
		String a="";
		char c;
		int ch_count=0;
    // https://maker.ifttt.com/trigger/test/with/key/dlXGlz3V1ixIjQf6S7V686
		client->println("GET https://maker.ifttt.com/trigger/"+eventName+"/with/key/"+_key);
		now=millis();
		avail=false;
    //Serial.println("starting timer");
		while (millis()-now<1500) {
			while (client->available()) {
				char c = client->read();
				//Serial.print(c);
        response = response + c;
			}
		}
	}

  //Serial.println("response");
  //Serial.println(response);
  return response;
}

bool IFTTTMaker::triggerEvent(String eventName){
  //String command="https://www.googleapis.com/youtube/v3/channels?part=statistics&id="+channelId;
  String response = sendTriggerEvent(eventName);       //recieve reply from telegram.org
  if(checkForSucessResponse(response)){
    return true;
  }

  return false;
}

bool IFTTTMaker::checkForSucessResponse(String response) {

  int index = response.indexOf("Congratulations!");

  return index > -1;
}
