#include <Servo.h>
const int potPin = A0; // Potansiyometre sinyal pini A0'a bağlı
int potValue = 0;

Servo servo1; // 1. Servo
Servo servo2; // 2. Servo
Servo servo3; // 3. Servo

int buttonState = 0;
int lastButtonState = 0;
int mode = 0; // Mod durumunu tutar

int lastActiveLED = 0;

int leds[3] = {3, 4, 5};
Servo servos[3] = {servo1, servo2, servo3};

int i = 0;
int debounceDelay = 50; // Düğme basımı için debounce gecikmesi
unsigned long lastDebounceTime = 0;

void setup()
{
    pinMode(2, INPUT_PULLUP); // Düğme için pull-up

    for (int i = 0; i < 3; i++)
    {
        pinMode(leds[i], OUTPUT);
    }

    servo1.attach(9);  // 1. Servo 9. pine bağlı
    servo2.attach(10); // 2. Servo 10. pine bağlı
    servo3.attach(11); // 3. Servo 11. pine bağlı

    servo1.write(0); // 1. Servo başlangıç pozisyonu
    servo2.write(0); // 2. Servo başlangıç pozisyonu
    servo3.write(0); // 3. Servo başlangıç pozisyonu

    attachInterrupt(digitalPinToInterrupt(2), toggleMode, FALLING);
    Serial.begin(9600);
    pinMode(potPin, INPUT);
}

void loop()
{

    potValue = analogRead(potPin); // Potansiyometre değerini oku (0 - 1023)
    Serial.print("Potansiyometre Değeri: ");
    Serial.println(potValue);

    switch (mode)
    {
    case 0:
        sequentialLEDs();
        break;
    case 1:
        followLEDsWithServos();
        break;
    case 2:
        allActive();
        break;
    case 3:
        potantioServo();
        break;
    }
}

void sequentialLEDs()
{
    digitalWrite(leds[lastActiveLED], LOW); // Bir önceki LED'i kapat

    lastActiveLED = (lastActiveLED + 1) % 3; // Sonraki LED'e geç
    digitalWrite(leds[lastActiveLED], HIGH); // Yeni LED'i yak
    delay(500);                              // 500 ms bekle
}

void followLEDsWithServos()
{
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[2], HIGH);

    servos[0].write(0);
    servos[2].write(0);
    delay(500);

    servos[0].write(90);
    servos[2].write(90);
    delay(500);
}

void allActive()
{
    for (i = 0; i < 3; i++)
    {
        digitalWrite(leds[i], HIGH);
        servos[i].write(0);
    }
    delay(500);

    for (i = 0; i < 3; i++)
    {
        digitalWrite(leds[i], LOW);
        servos[i].write(90);
    }
    delay(500);
}

void potantioServo()
{
    if (potValue < 125)
    {
        sequentialLEDs();
    }
    else if (potValue < 225)
    {
        followLEDsWithServos();
    }
    else if (potValue < 675)
    {
        allActive();
    }
    else
    {
        Serial.println("potansiyometre max değerde");
    }
}

void toggleMode()
{
    unsigned long currentTime = millis();

    // Debounce kontrolü
    if (currentTime - lastDebounceTime > debounceDelay)
    {
        mode = (mode + 1) % 4; // Mod durumunu artır ve sıfırla
        Serial.print("Yeni mod: ");
        Serial.println(mode);

        // Tüm LED'leri ve servoları sıfırla
        for (i = 0; i < 3; i++)
        {
            digitalWrite(leds[i], LOW);
            servos[i].write(90);
        }

        // Eğer Mod 0'a geri dönülürse, son LED'den devam et
        if (mode == 0)
        {
            digitalWrite(leds[lastActiveLED], HIGH); // Son LED'i açık bırak
        }
        lastDebounceTime = currentTime;
    }
}
