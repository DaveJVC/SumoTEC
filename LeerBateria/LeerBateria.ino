/*
  Este código lee por medio del ADC una bateríad e 3.7 V y mapea dicho valor entre 0 y 100%
  siendo 0 % si cae debajo de 3.4 V (límite seguro), en cuyo caso, lo que hay dentro del loop deja de funcionar.
  Además, enciende una luz RGB con señales PWM según el estado de la batería
  VERDE     -> >50%
  AMARILLO  -> <50%
  ROJO      -> <15%

  Nótese que el ESP32 solo puede leer valores analóigicos de hasta 3.3 V, por lo que un divisor de tensión
  de la batería al ESP32 es necesario, valores utilizados: 100 kOhm y 27 kOhm.
*/

#define pinBateria 13
#define pinRojo 12
#define pinVerde 14

const int canalPWMRojo = 0;   // Canal PWM 0 para rojo
const int canalPWMVerde = 1;  // Canal PWM 1 para verde

void setup() {
  Serial.begin(115200);      // Para debugging
  
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  //ledcSetup(canalPWMRojo, 5000, 8);       // Seteo los canales del PWM a 5 kHz y 8 bits de resolución (0-256)
  //ledcSetup(canalPWMVerde, 5000, 8);
  //ledcAttachPin(pinRojo, canalPWMRojo);   // Asigno canal PWM 0 a pin rojo
  //ledcAttachPin(pinVerde, canalPWMVerde); // Asigno canal PWM 1 a pin verde
}

void loop() {
  long nivelBateria = leerBateria();

  Serial.print(nivelBateria); Serial.println(" %"); // Para debugging
  delay(2000);

  if(nivelBateria > 0.0) {    // Si el nivel de batería fuera a bajar de 0, el programa no continuará
    if(nivelBateria < 15) {
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, HIGH);
      //colorLED(255, 0);  // Color rojo, significa que la batería bajó del 15%
    }
    else if(nivelBateria < 50) {
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, LOW);
      //colorLED(255, 255);  // Color amarillo, significa que la batería bajó del 50%
    }
    else {
      digitalWrite(pinRojo, HIGH);
      digitalWrite(pinVerde, LOW);
      //colorLED(0, 255);    // Color verde, significa que la batería está por encima del 50%
    }
  }
}

long leerBateria() {
  int miliVoltsBateria = analogReadMilliVolts(pinBateria);          // Resolucion de 12 bits (0 - 3300 mV)
  //long nivelBateria = map(miliVoltsBateria, 2673, 3300, 0.0, 100.0);
  long nivelBateria = (miliVoltsBateria-2673.0)/(3300.0 - 2673.0) * 100.0;
  return(nivelBateria);
}

void colorLED(int rojoDC, int verdeDC) {
  ledcWrite(canalPWMRojo, rojoDC);   // Activo PWM en pin rojo con "rojoDC" ciclo de trabajo
  ledcWrite(canalPWMVerde, verdeDC); // Activo PWM en pin verde con "verdeDC" ciclo de trabajo
}