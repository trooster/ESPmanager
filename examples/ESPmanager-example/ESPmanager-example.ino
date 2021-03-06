/*-------------------------------------------------------------------------------------------------------


							Example ESP Manager software..

BeerWare Licence, just give due credits

Upload files to the ESP using this command (on mac and linux anyway, can upload using serial via SPIFFS data upload too)
for file in `ls -A1`; do curl -F "file=@$PWD/$file" X.X.X.X/espman/upload; done
 * Thanks to me-no-dev

--------------------------------------------------------------------------------------------------------*/
#include <FS.h> //  Settings saved to SPIFFS
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncJson.h>

#include <ArduinoOTA.h>
#include <ArduinoJson.h> // required for settings file to make it readable

#include <Hash.h>
#include <ESP8266mDNS.h>

#include <ESPmanager.h>

AsyncWebServer HTTP(80);

ESPmanager settings(HTTP, SPIFFS);


//  You can specify a default hard coded set of credentials
/*
const char * defaultSSID = "";
const char * defaultPSK = "";
ESPmanager settings(HTTP, SPIFFS, "ESPManager", defaultSSID , defaultPSK);
*/

void setup()
{

	Serial.begin(115200);
	SPIFFS.begin();

	Serial.println("");
	Serial.println(F("Example ESPconfig - using ESPAsyncWebServer"));

	Serial.printf("Sketch size: %u\n", ESP.getSketchSize());
	Serial.printf("Free size: %u\n", ESP.getFreeSketchSpace());

	settings.begin();

	HTTP.begin();

	Serial.print(F("Free Heap: "));
	Serial.println(ESP.getFreeHeap());


}


void loop()
{
	settings.handle();
}
