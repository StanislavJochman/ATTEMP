#include <DallasTemperature.h>
#include <OneWire.h>
#define ONE_WIRE_BUS 4

int data = 0;//pin 14
int latch = 2;
int clock = 1;
int button = A3;
int state;
int counter;
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
float temperature;

int znaky [16][8]{
{0,1,1,1,0,1,1,1},//0
{0,0,0,1,0,1,0,0},//1
{1,0,1,1,0,0,1,1},//2
{1,0,1,1,0,1,0,1},//3
{1,1,0,1,0,1,0,0},//4
{1,1,1,0,0,1,0,1},//5
{1,1,1,0,0,1,1,1},//6
{0,0,1,1,0,1,0,0},//7
{1,1,1,1,0,1,1,1},//8
{1,1,1,1,0,1,0,0},//9
//-------------------
{0,0,0,0,0,0,0,0},//clear
{0,1,1,0,0,0,1,1},//celzia
{1,1,1,0,0,0,1,1},//error
{1,0,0,0,0,0,0,0}, // -
{0,0,0,0,1,0,0,0}, //dot
{1,1,1,0,0,0,1,0}//fahrenheit
};



void setup()
{

pinMode(data,OUTPUT);
pinMode(clock,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(button,INPUT_PULLUP);
sensors.begin(); 
sensors.requestTemperatures();
delay(500);
menu();
}
void loop()
{
 
  if(BTN()==0)
  { 
    delay(100);
    sensors.requestTemperatures();
    if (state == 15)
    {
      temperature = round(sensors.getTempFByIndex(0));
      delay(100);
      tempF(temperature);
    }
    else if (state == 11)
    {
      temperature = sensors.getTempCByIndex(0);
      delay(100);
      tempC(temperature);
    }
  }
  else{cislo(10);}
  
}

