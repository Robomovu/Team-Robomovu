//Variables globales
long rpm;
volatile byte pulsos;
unsigned long timeold;
//De Acuerdo a Disco encoder variar
unsigned int pulsosPorVuelta=50;

void contador()
{
 pulsos=pulsos+1; 
}

void setup() 
{
  Serial.begin(115200);
  pinMode(2,INPUT);
  attachInterrupt(0,contador,RISING);
  pulsos=0;
  rpm=0;
  timeold=0;

}

void loop() 
{
if(millis()-timeold>=1000)
{
  detachInterrupt(0);
  rpm=(60*1000 / pulsosPorVuelta) / (millis()-timeold)*pulsos;
  timeold=millis();
  pulsos=0;

  Serial.print("RPM = ");
  Serial.println(rpm, DEC);
  attachInterrupt(0, contador, RISING);
  }

}
