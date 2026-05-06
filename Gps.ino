#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial gpsSerial(10, 11);
TinyGPSPlus gps;

void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(9600);

  Serial.println("GPS INITIALIZING...");
  Serial.println();
}

void loop()
{
  while (gpsSerial.available() > 0)
  {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isValid())
  {
    Serial.println("===== GPS DATA =====");

    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);

    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);

    Serial.print("Satellites: ");
    Serial.println(gps.satellites.value());

    Serial.print("Altitude (meters): ");
    Serial.println(gps.altitude.meters());

    Serial.print("Speed (km/h): ");
    Serial.println(gps.speed.kmph());

    Serial.print("Date: ");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.println(gps.date.year());

    Serial.print("Time: ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.println(gps.time.second());

    Serial.println("====================");
    Serial.println();

    delay(2000);
  }
  else
  {
    Serial.println("Waiting for valid location...");
    delay(1000);
  }
}