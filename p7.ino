


void setup() {
//Semaforo de los autos
  //rojo
pinMode(2,OUTPUT); 
//verde
pinMode(3,OUTPUT);
//azul
pinMode(4,OUTPUT);

//Semaforo del peaton
//peaton rojo
pinMode(5,OUTPUT);
//peaton verde
pinMode(6,OUTPUT);

//boton de cambio
pinMode(7,INPUT);
}   
//time es un metodo que cambia el tiempo de cambio del semaforo dependiendo del valor en 
//el que se encuentre el potenciometro
int time(int y){
   int valor= analogRead(A0);
  if(valor<=200){
    switch(y){
      case 1: return 5000;
      case 2: return 500;
    }
  }
  else if(valor<=400){
    switch(y){
      case 1: return 4000;
      case 2: return 400;
    }
  }
  else if(valor<=600){
    switch(y){
      case 1: return 3000;
      case 2: return 300;
    }
  }
  else if(valor<=800){
    switch(y){
      case 1: return 2000;
      case 2: return 200;
    }
  }
  else{
    switch(y){
      case 1: return 1000;
      case 2: return 100;
    }
  }
  
}
//el metodo cambios al activarse se produce un ciclo completo de cambio en los semaforos empezando por el cambio
//de luces para los autos hasta llegar al ROJO que es su alto, y darle el paso al peaton con su luz VERDE
void cambios(){
 //cambio
 digitalWrite(3,LOW);
 digitalWrite(4,HIGH);
 
delay(time(1));

 //pase peaton
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);

 digitalWrite(6,HIGH);
 digitalWrite(2,HIGH);
 delay(time(1));
//cambio de luz
digitalWrite(2,LOW);
digitalWrite(4,HIGH);

digitalWrite(6,LOW);
 delay(time(2));
 digitalWrite(6,HIGH);
 delay(time(2));
 digitalWrite(6,LOW);
 delay(time(2));
 digitalWrite(6,HIGH);
 delay(time(2));
 digitalWrite(6,LOW);
 delay(time(2));

//pase auto
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
  
}
//------------------------------------ //Semaforo //------------------------------------

void loop()  
{      
  //ya que hay un boton de cruce, por defecto las luces del peaton estan en rojo
  //y las de los autos en verde, no es sino hasta que se preciosa el boton que comienza
  //el ciclo de cambios de semaforo, eso ocurre cuando
  //ESTE if sea verdadero, (al presionar el boton) de otro modo se mantienen las luces
  
  if(digitalRead(7)){
    cambios();   
  }
  else{
 digitalWrite(3,HIGH);
 digitalWrite(5,HIGH);
  }
 
 
}

