 #include <LiquidCrystal.h>
#include <Keypad.h> 
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);
char ingreso;///variable de ingleso en el switch

////////////////// configuracion Keypad

const byte ROWS = 4; //4 filas
const byte COLS = 4; //4 columnas
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
byte rowPins[ROWS] = {40, 39, 38, 37}; //filas del keypad
byte colPins[COLS] = {36, 35, 34, 33}; //columnas del keypad
Keypad teclado = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
////// fin configuracion keypad

void setup() { 
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.write("Bienvenido a su");
  lcd.setCursor(0,1);
  lcd.write("Sistema de Riego");

   Serial.begin(9600);//HUMEDAD UNO
}

void loop() {
  leerIngreso();
  }

void leerIngreso() {
  ingreso = teclado.getKey();
  if (ingreso != NO_KEY)
    switch (ingreso) {
      case 'A':    // 
          lcd.setCursor(0, 0);
          lcd.print(" opcion A ");
          lcd.setCursor(0, 1);
          lcd.print(" opcion A ");
          delay(5000);
          cls();
        break;
      case 'B':
          lcd.setCursor(0, 0);
            humedad1();//
        break;

      case 'C':
       
        break;
      case 'D':
        break;
      case '*':
       
        break;
      case '#':
        
        break;       
}
}

void cls(){
  lcd.setCursor(0, 0);
  lcd.print("***Agro-Water***");
  lcd.setCursor(0, 1);
  lcd.print("*****Activo*****");
  }

void humedad1(){
  int a0=analogRead(2);
 Serial.println(a0);
 lcd.setCursor(0, 0);
 lcd.print(" HUMEDAD SENSOR 1");
 if (a0>=800){
          lcd.setCursor(0, 1);
          lcd.print("--esta seco-----");
          delay(5000);
  }
 if(a0<=600) {
  lcd.setCursor(0, 1);
          lcd.print("---mojado ------");
          delay(5000);
  }
cls();
  }
