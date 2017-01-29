#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

char ssid[] = "XXXX";       // your network SSID (name)
char password[] = "YYYYY";  // your network key

String subredditName = "arduino";

long checkRedditDueTime;
int checkRedditDelay = 60000; // 60 x 1000 (1 minute)


void setup() {

  Serial.begin(115200);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

}

String getTitleOfNewestPost(String sub) {
  return "";
}

void loop() {
  long now = millis();
  if(now >= checkRedditDueTime) {
    Serial.println("---------");
    String title = getTitleOfNewestPost(subredditName);
    if(title != "") {
      Serial.println("Most recent post on /r/" + subredditName);
      Serial.println(title);
    } else {
     Serial.println("Error getting title."); 
    }
    Serial.println("---------");
    checkRedditDueTime = now + checkRedditDelay;
  }
}
