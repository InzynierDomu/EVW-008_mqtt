#include <Arduino.h>

const char* WIFI_SSID = "ssid"; ///< WiFi ssid
const char* WIFI_PASS = "pass"; ///< WiFi password

const char* MQTT_SERV = "192.168.1.139"; ///< broker ip
const char* MQTT_ID = "EVW-008";    ///<  mqtt id
const char* MQTT_USER = "user";    ///< mqtt user
const char* MQTT_PASS = "pass"; ///< mqtt password
const char* SUB_TOPIC = "EVW-008/+"; ///< subscribe topic to control outputs

const char* TOPIC_OUT1 = "EVW-008/output1"; ///< topic to control 1st relay
const char* TOPIC_OUT2 = "EVW-008/output2"; ///< topic to control 2st relay
const char* TOPIC_OUT3 = "EVW-008/output3"; ///< topic to control 3st relay
const char* TOPIC_OUT4 = "EVW-008/output4"; ///< topic to control 4st relay

const uint8 PCF8574_ADDRESS = 0x20; ///< pcf8574 deafult addres on EVW-008