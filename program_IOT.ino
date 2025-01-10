// Library yang digunakan
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <FirebaseESP32.h>
#include <WiFi.h>

// Inisialisasi LCD dan Sensor DHT11
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Karakter Khusus untuk LCD
byte bar1[8] = { B11100, B11110, B11110, B11110, B11110, 11110, B11110, B11100 };
byte bar2[8] = { B00111, B01111, B01111, B01111, B01111, B01111, B01111, B00111 };
byte bar3[8] = { B11111, B11111, B00000, B00000, B00000, B00000, B11111, B11111 };
byte bar4[8] = { B11110, B11100, B00000, B00000, B00000, B00000, B11000, B11100 };
byte bar5[8] = { B01111, B00111, B00000, B00000, B00000, B00000, B00011, B00111 };
byte bar6[8] = { B00000, B00000, B00000, B00000, B00000, B00000, B11111, B11111 };
byte bar7[8] = { B00000, B00000, B00000, B00000, B00000, B00000, B00111, B01111 };
byte bar8[8] = { B11111, B11111, B00000, B00000, B00000, B00000, B00000, B00000 };

// Konfigurasi Firebase dan Wi-Fi
#define FIREBASE_HOST "https://aplikasiiot-5763d-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "CXSmN35k7S1dEqQXZ0nsPv6oyR5lMIzjblorweCR"
#define WIFI_SSID "samsung"
#define WIFI_PASSWORD "galaxyyy"
FirebaseData firebaseData;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;

#define DHTPIN 4
const int kipaspin = 18;
const int lampupin = 19;

void setup() {
  Serial.begin(9600);
  pinMode(kipaspin, OUTPUT);
  pinMode(lampupin, OUTPUT);
  digitalWrite(kipaspin, LOW);
  digitalWrite(lampupin, LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("MENGHUBUNGKAN");
  lcd.setCursor(6, 1);
  lcd.print("WIFI");
  delay(3000);
  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;

  Firebase.begin(&firebaseConfig, &firebaseAuth);

  lcd.createChar(1, bar1);
  lcd.createChar(2, bar2);
  lcd.createChar(3, bar3);
  lcd.createChar(4, bar4);
  lcd.createChar(5, bar5);
  lcd.createChar(6, bar6);
  lcd.createChar(7, bar7);
  lcd.createChar(8, bar8);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("WIFI TERHUBUNG");
  lcd.setCursor(0, 1);
  lcd.print("MENAMPILKAN SUHU");
  delay(3000);
  lcd.clear();
}

void custom0(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom1(int col) {
  lcd.setCursor(col, 0);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom2(int col) {
  lcd.setCursor(col, 0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(6);
}

void custom3(int col) {
  lcd.setCursor(col, 0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void custom4(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom5(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void custom6(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom7(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom8(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom9(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void printNumber(int value, int col) {
  if (value == 0) {
    custom0(col);
  }
  if (value == 1) {
    custom1(col);
  }
  if (value == 2) {
    custom2(col);
  }
  if (value == 3) {
    custom3(col);
  }
  if (value == 4) {
    custom4(col);
  }
  if (value == 5) {
    custom5(col);
  }
  if (value == 6) {
    custom6(col);
  }
  if (value == 7) {
    custom7(col);
  }
  if (value == 8) {
    custom8(col);
  }
  if (value == 9) {
    custom9(col);
  }
}

// Menampilkan Suhu pada LCD
void printTemperature(float temp) {
  int t = (int)temp;
  int d = t / 10;
  int u = t % 10;
  int decimal = ((int)((temp - t) * 10 + 0.1));

  printNumber(d, 3);
  printNumber(u, 6);
  lcd.setCursor(9, 1);
  lcd.print(".");
  printNumber(decimal, 10);
  lcd.setCursor(13, 0);
  lcd.write(223);
  lcd.print("C");
}

void loop() {
  float temp = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(temp)) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Gagal Membaca");
    lcd.setCursor(5, 1);
    lcd.print("Sensor");
    delay(300);
  } else {
  }

  String kondisi, lampu, kipas;
  if (temp < 28) {
    digitalWrite(lampupin, HIGH);
    digitalWrite(kipaspin, LOW);
    Serial.println(kondisi);
    kondisi = "Terlalu_Dingin";
    lampu = "ON";
    kipas = "OFF";
  } else if (temp > 30) {
    digitalWrite(lampupin, LOW);
    digitalWrite(kipaspin, HIGH);
    Serial.println(kondisi);
    kondisi = "Terlalu_Panas";
    lampu = "OFF";
    kipas = "ON";
  } else {
    digitalWrite(lampupin, HIGH);
    digitalWrite(kipaspin, LOW);
    Serial.println(kondisi);
    kondisi = "Normal";
    lampu = "ON";
    kipas = "OFF";
  }

// Mengirim data ke firebase
  if (Firebase.setFloat(firebaseData, "/Hasil_Pembacaan/suhu", temp)) {
    lcd.clear();
    printTemperature(temp);
    Serial.print("Suhu: ");
    Serial.print(temp);
    Serial.println(" *C");
    Serial.print("Kelembaban: ");
    Serial.print(h);
    Serial.println(" %");
    Serial.println();
    delay(300);
  }
  if (Firebase.setFloat(firebaseData, "/Hasil_Pembacaan/kelembaban", h)) {
  }
  if (Firebase.setString(firebaseData, "/Hasil_Pembacaan/kondisi", kondisi)) {
  }
  if (Firebase.setString(firebaseData, "/Hasil_Pembacaan/lampu", lampu)) {
  }
  if (Firebase.setString(firebaseData, "/Hasil_Pembacaan/kipas", kipas)) {
  } else {
    lcd.clear();
    Serial.println("hasil sensor tidak terkirim");
    Serial.println("Karena: " + firebaseData.errorReason());
    lcd.setCursor(0, 0);
    lcd.print("TIDAK TERHUBUNG");
    lcd.setCursor(0, 1);
    lcd.print(firebaseData.errorReason());
    delay(300);
  }

  delay(100);
}
