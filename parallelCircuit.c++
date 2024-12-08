int i=0;
int j=0;
int leds[4] = {7, 6, 5, 4};

void setup() {
  // Pin modlarını çıkış olarak ayarlıyoruz
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  for(i=0 ; i<4 ; i++){
    
    for(j=0;j<4;j++){
    	digitalWrite(leds[i], LOW);
    }
    digitalWrite(leds[i], HIGH);
    delay(1000); // 1 saniye bekle
    digitalWrite(leds[i], LOW);
  }
  
}