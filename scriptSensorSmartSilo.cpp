
float tempo;       
float distancia=0; 
int trig=9;
int echo=10;
int verm=13;
int ama=12;
int ver=11;


float alturaSilo = 200;
float raioSilo = 50;
float areaCirculo = (raioSilo*raioSilo)* 3.14;
float volumeTotal = areaCirculo * alturaSilo;


float percentualLimite = 90;
float percentualMinimo = 10;





float distanciaMinima = alturaSilo - (alturaSilo * percentualLimite / 100);
float distanciaMaxima = alturaSilo - (alturaSilo * percentualMinimo / 100);


void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT);   
  pinMode (verm, OUTPUT);
  pinMode (ama, OUTPUT);
  pinMode (ver, OUTPUT);
 }

void loop() {
  
  digitalWrite(trig, LOW);          
  delayMicroseconds(2);             
  digitalWrite (trig, HIGH);        
  delayMicroseconds(10);            
  digitalWrite (trig, LOW);         
  
  tempo=pulseIn(echo, HIGH);        
  

  distancia= (tempo/2)*0.0343 ;   
  
  float volumeOcupado = areaCirculo * (alturaSilo - distancia);
  float percentualOcupado = volumeOcupado/volumeTotal * 100; 
  
  

	
	
  	
  	Serial.println(percentualOcupado);
  
  
  

  if (distancia<=distanciaMinima){
    digitalWrite (ver, LOW);
    digitalWrite (ama, LOW);
    
    digitalWrite (verm, HIGH);
    delay(500);
    
    digitalWrite (verm, LOW);
    delay (500);
  }else if(distancia <=distanciaMaxima){
    digitalWrite (ver, HIGH);
    digitalWrite (verm, LOW);
    digitalWrite (ama, LOW);
    delay (500);
  }else{
    digitalWrite (ama, HIGH);
    digitalWrite (ver, LOW);
    digitalWrite (verm, LOW);
    delay (500);

    digitalWrite (ama, LOW);
    delay (500);    
  }
  
  
    
}