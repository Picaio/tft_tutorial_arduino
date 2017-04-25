#include <stdint.h>
#include <TFTv2.h>
#include <SPI.h>
#include <SeeedTouchScreen.h>

int sensorPin = A7; 
int sensorValue = 0;
int OldsensorValue = 0;
int pos=0;

TouchScreen ts = TouchScreen(XP, YP, XM, YM); //init TouchScreen port pins

void setup()
{
   TFT_BL_ON;      // encender el backlight
   Tft.TFTinit();  // inicializar libreria
   Tft.fillRectangle(40, 130, 150,70,0x5D0B03);
   Tft.drawString("PUSH",65,150,4,WHITE);
   Tft.drawRectangle(40, 130, 150,70,0x951509);


}

void loop()
{ 

  Point p = ts.getPoint();

    //map the ADC value read to into pixel co-ordinates

    p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);

    if(p.x>50 && p.x<170 && p.y>130 && p.y<180)
    
    {
       Tft.fillRectangle(0, 0, 240,320,BLACK);
      Tft.drawString("OK!",65,250,3,WHITE);
      Tft.fillRectangle(180, 130, 5,75,WHITE);
        Tft.fillRectangle(140, 145, 45,5,WHITE);
        Tft.fillRectangle(140, 165, 45,5,WHITE);
        Tft.fillRectangle(140, 185, 45,5,WHITE);
        
        Tft.fillRectangle(139, 123, 40,5,WHITE);
        Tft.fillRectangle(114, 207, 65,5,WHITE); 
        Tft.fillRectangle(132, 90, 5,30,WHITE);
        Tft.fillRectangle(115, 75, 15,5,WHITE);
        Tft.fillRectangle(110, 75, 5,45,WHITE);
        Tft.fillRectangle(90, 200, 25,5,WHITE);
        Tft.fillRectangle(90, 130, 25,5,WHITE);
        
        Tft.fillRectangle(40, 120, 40,90,BLUE);
        Tft.fillRectangle(50, 190, 10,10,WHITE);
      
    }


    

}



