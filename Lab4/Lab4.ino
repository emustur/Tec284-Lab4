#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>


#include <U8x8lib.h>
DHT dht(3, DHT11);

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
dht.begin();
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
}
void loop() {
  float temp = dht.readTemperature() * 1.8 + 32;
  float humid = dht.readHumidity();
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
u8x8.println("Temperature: ");
u8x8.println(temp);
u8x8.println("Humidity: ");
u8x8.print(humid);
u8x8.print("%");

if(humid>70){
  tone(5,500,500);
  digitalWrite(4,HIGH);
  delay(500);
  digitalWrite(4,LOW);
  delay(500);

}
  else{
    noTone(5);
    }
}

