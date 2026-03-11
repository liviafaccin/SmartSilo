// Declarando as variáveis
float tempo;        // A variável tempo recebe o tempo que o som demora para ir e voltar.
float distancia=0;  // Declarando a variável que vai receber a distância
int trig=9;
int echo=10;



float alturaSilo = 400;
float raioSilo = 50;
float areaCirculo = (raioSilo*raioSilo)* 3.14;
float volumeTotal = areaCirculo * alturaSilo;


float percentualLimite = 90;
float percentualMinimo = 10;





float distanciaMinima = alturaSilo - (alturaSilo * percentualLimite / 100);
float distanciaMaxima = alturaSilo - (alturaSilo * percentualMinimo / 100);


void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);  //Informando que o pino é de saída
  pinMode(echo, INPUT);   //Informando que o pino é de entrada
 
 }

void loop() {
  
  digitalWrite(trig, LOW);          //Desligando o envio de som
  delayMicroseconds(2);             //Tempo que vai ficar desligado
  digitalWrite (trig, HIGH);        //Liga o envio de som
  delayMicroseconds(10);            //Tempo que vai ficar ligado
  digitalWrite (trig, LOW);         //Desligando o envio de som
  
  tempo=pulseIn(echo, HIGH);        // A variável "TEMPO" recebe o tempo que o som demora para ir e voltar de um obstaculo
  
  //Como o tempo está dobrado, pois é o tempo de ir e voltar, dividimos por 2
  //Velocidade do som aproximadamente 0.0343 centimetro por microsegundos
  distancia= (tempo/2)*0.0343 ;   
  
  float volumeOcupado = areaCirculo * (alturaSilo - distancia);
  float percentualOcupado = volumeOcupado/volumeTotal * 100; 
  
  

	//Serial.print("Volume : ");
	//Serial.print(volumeOcupado);
  	//Serial.println(" centimetros cubicos");
  	Serial.print(percentualOcupado);
    Serial.println("%");
  
  
  
  // Se a distância for menor que 10cm os três LED pisca
  if (distancia<=distanciaMinima){
    Serial.println("SILO ACIMA DO LIMITE, VOCÊ PRECISA ENSVAZIAR");
  }else if(distancia <=distanciaMaxima){
    Serial.println("SILO DENTRO DO LIMITE");
  }else{
    Serial.println("SILO ABAIXO DO LIMITE, VOCÊ PRECISA ENCHER");
  }
  
  delay(1000);
    
}