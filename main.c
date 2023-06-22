// C++ code
//

// Constantes de pinos
#define PIN_LED_BUZZ 7
#define PIN_TMP A0
#define PIN_FUN_ENGINE 8

// Variáveis
float valorTMP = 0.0;

void setup()
{
  pinMode(PIN_LED_BUZZ, OUTPUT);
  pinMode(PIN_TMP, INPUT);
  pinMode(PIN_FUN_ENGINE, OUTPUT);
  
  Serial.begin(9600);
}


void loop()
{
  valorTMP = analogRead(PIN_TMP);
  Serial.print("Valor TMP := ");
  Serial.print(valorTMP);
  valorTMP = convertToGraus(valorTMP);
  Serial.print(" => ");
  Serial.print(valorTMP);
  Serial.print(" ºC");
  Serial.print("\n");
  
  if(valorTMP > 30)
    digitalWrite(PIN_FUN_ENGINE, HIGH);
  if(valorTMP > 50)
    digitalWrite(PIN_LED_BUZZ, HIGH);
  else{
    analogWrite(PIN_FUN_ENGINE, LOW);
    digitalWrite(PIN_LED_BUZZ, LOW);
  }
  
  delay(1000); // Wait for 1000 millisecond(s)
}

float convertToGraus(float read){
  return 0.488*read - 49.1;
}
