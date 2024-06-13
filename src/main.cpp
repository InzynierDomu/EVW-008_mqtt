#include "config.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PCF8574.h>
#include <PubSubClient.h>
#include <map>

WiFiClient wifiClient;            ///< wifi client
PubSubClient client(wifiClient);  ///< mqtt client
PCF8574 pcf8574(PCF8574_ADDRESS); ///< expander handler

/**
 * @brief Defines a custom comparator for comparing C-style strings (char pointers).
 */
struct CharPtrComparator
{
  bool operator()(const char* lhs_topic, const char* rhs_topic) const
  {
    return strcmp(lhs_topic, rhs_topic) < 0;
  }
};

std::map<const char*, uint8_t, CharPtrComparator> topic_pins;

/**
 * @brief Setup wifi
 */
void setup_wifi()
{
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

/**
 * @brief Get the pin associated with a topic.
 * @param topic The topic for which to retrieve the pin number.
 * @return The pin number associated with the topic, or 0 if the topic is not found.
 */
uint8_t getPinByTopic(const char* topic)
{
    auto it = topic_pins.find(topic);
    if (it != topic_pins.end())
    {
        return it->second; // Return the pin associated with the topic
    }
    else
    {
        return 0; // Return 0 if the topic is not found
    }
}

/**
 * @brief reaction for recive mqtt message
 * @param topic: topic of message
 * @param payload: paylod of message
 * @param length: lenght pyload
 */
void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  Serial.println((uint8)*payload);
  auto pin = getPinByTopic(topic);
  pcf8574.digitalWrite(pin, ((uint8)*payload)-48);
}

/**
 * @brief main setup on startup
 */
void setup()
{
  Serial.begin(115200);

  pcf8574.pinMode(0, OUTPUT);
  pcf8574.pinMode(1, OUTPUT);
  pcf8574.pinMode(2, OUTPUT);
  pcf8574.pinMode(3, OUTPUT);
  pcf8574.begin();

  setup_wifi();
  client.setServer(MQTT_SERV, 1883);
  client.setCallback(callback);

  topic_pins[TOPIC_OUT1] = 0;
  topic_pins[TOPIC_OUT2] = 1;
  topic_pins[TOPIC_OUT3] = 2;
  topic_pins[TOPIC_OUT4] = 3;
}

/**
 * @brief establish connection with a mqtt broker
 */
void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(MQTT_ID, MQTT_USER, MQTT_PASS))
    {
      Serial.println("connected");
      client.subscribe(SUB_TOPIC);
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

/**
 * @brief mian loop
 */
void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
  delay(10);
}