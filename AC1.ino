//variaveis do led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

bool estadoLedVermelho = false;

//adicao botao 
const int botao1 = 2;
const int botao2 = 3;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const int botaoDelay = 10;

void setup()
{
      pinMode(A0, INPUT);
      pinMode(A1, INPUT);

      pinMode(vermelho, OUTPUT);
      pinMode(verde, OUTPUT);
      pinMode(azul, OUTPUT);

      Serial.begin(9600);
      //print nome do projeto e grupo
      Serial.println("AC1 - Meu Primeiro Projeto 2021");
      Serial.println("                           V1.0");
      Serial.println("Grupo: Comando Galicea");
}

void loop()
{
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
      Serial.println("botao 1 pressionado");
    ledVermelho(true);
      lastDebounceTime1 = millis();
  }
  if((millis() - lastDebounceTime2) > botaoDelay && digitalRead(botao2)){
      Serial.println("botao 2 pressionado");
    ledVermelho(false);
      lastDebounceTime2 = millis();
  }
//teste temperatura
  if(getTemperatura() >= 15){
    ledAzul(true);
    Serial.println("alta temperatura");
  }else{
      ledAzul(false);
    Serial.println("temperatura ideal");
  }
  //teste luminosidade
  if(getLuminosidade() > 5){
       ledVerde(true);
       Serial.println("alta luminosidade");
  }else{
      ledVerde(false);
    Serial.println("luminosidade ideal");
  }
  delay(10);
}

void ledVermelho(bool estado)void ledVermelho(bool estado){
     digitalWrite(vermelho,estado);
}
void ledVerde(bool estado){
     digitalWrite(verde,estado);
}
void ledAzul(bool estado){
    digitalWrite(azul,estado);
}

int getTemperatura(){
      int temperaturaC;
    temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
      return temperaturaC;

} 
//funcao de leitura da luminosidade
int getLuminosidade(){)
      int luminosidade;
    luminosidade = map(analogRead(A1), 6, 619, -3, 10);
      return luminosidade;
}
