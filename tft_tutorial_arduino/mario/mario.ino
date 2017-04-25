#include <stdint.h>
#include <TFTv2.h>
#include <SPI.h>

int sensorPin = A7; 
int sensorValue = 0;
int OldsensorValue = 0;
int pos=0;

void setup()
{
    TFT_BL_ON;      // encender el backlight
    Tft.TFTinit();  // inicializar libreria
    Serial.begin(9600);  

}

void loop()
{ 
  OldsensorValue = sensorValue;// se guarda el estado del anterior loop
  sensorValue = analogRead(sensorPin);
  //pos = map(sensorValue,0,1023,-60,80);
  pos=0;
  mario(pos,0); //pocision del dibujo
  cuerda(pos,0);//pocision de la cuerda completa
  delay(300);
  no_cuerda(pos,0);//sensacion de animacion
  delay(300);
  
  if(OldsensorValue != sensorValue ) // si el valor del potenciometro cambia entonces se borra pantalla
  {//clear_pantalla(pos,0);
  }
}

void clear_pantalla(int y, int x)
{
 Tft.fillRectangle(y+60, x+100, 200,100,BLACK);  
}
void mario(int y, int x)
{
  
  //////////////////////////////////GORRA////////////////
    Tft.fillRectangle(y+180, x+150, 10,17,RED);
    Tft.fillRectangle(y+175, x+140, 10,13,RED);
    Tft.fillRectangle(y+170, x+135, 10,10,RED);
    Tft.fillRectangle(y+165, x+130, 10,10,RED);
//////////////////////////////////CARA/////////////////////    
    Tft.fillRectangle(y+163, x+150, 5,17,0xFED4CB);
    Tft.fillRectangle(y+155, x+147, 9,10,0xFED4CB);
    Tft.fillRectangle(y+155, x+162, 9,5,0xFED4CB);
    Tft.fillRectangle(y+149, x+150, 5,30,0xFED4CB);
    Tft.fillRectangle(y+144, x+160, 5,20,0xFED4CB);
    Tft.fillRectangle(y+139, x+163, 5,15,0xFED4CB);
    Tft.fillRectangle(y+144, x+128, 15,8,0xFED4CB);
    Tft.fillRectangle(y+144, x+133, 5,7,0xFED4CB);
    Tft.fillRectangle(y+144, x+147, 5,6,0xFED4CB);
    Tft.fillRectangle(y+139, x+133, 5,16,0xFED4CB);
///////////////////////////////BOTA///////////////////////
    Tft.fillRectangle(y+128, x+128, 5,45,GREEN);
    Tft.fillRectangle(y+119, x+123, 8,55,GREEN);
    Tft.fillRectangle(y+113, x+128, 5,50,GREEN);
    Tft.fillRectangle(y+100, x+133, 8,40,GREEN);
    Tft.fillRectangle(y+94, x+138, 5,15,GREEN);
    Tft.fillRectangle(y+89, x+133, 5,15,GREEN);
    Tft.fillRectangle(y+89, x+153, 5,25,GREEN);
    Tft.fillRectangle(y+80, x+133, 8,55,GREEN);
    Tft.fillRectangle(y+75, x+128, 5,60,GREEN);
    Tft.fillRectangle(y+70, x+123, 5,65,GREEN);
    Tft.fillRectangle(y+65, x+128, 5,50,GREEN);

  
}

void cuerda(int y ,int x)
{
  //////////////////////////////CUERDA//////////////////////
    Tft.fillRectangle(y+100, x+110, 10,10,WHITE);
    Tft.fillRectangle(y+75, x+110, 10,10,WHITE);
    Tft.fillRectangle(y+85, x+110, 14,5,WHITE);
    Tft.fillRectangle(y+92, x+110, 2,20,WHITE);

 ///////////////////////////////////////////////////   
  
}
void no_cuerda(int y ,int x)
{
  Tft.fillRectangle(y+70, x+110, 60,10,BLACK);
  Tft.fillRectangle(y+92, x+110, 2,15,WHITE); 
  ////////////////////////////////////////////  
  
  
  }
