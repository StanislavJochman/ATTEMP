int stovkyF(int temperature)
  {
    int stovkyF;
    stovkyF = (temperature - jednotky(temperature))/100;
    return stovkyF;
  }
int desiatky(int temperature)
  {
    int desiatky;
    desiatky = (temperature - jednotky(temperature))/10;
    return desiatky;
  }
int desiatkyF(int temperature)
  {
    int desiatkyF;
    desiatkyF = (temperature/10)%10;
    return desiatkyF;
  }
int jednotky(int temperature)
  {
    int jednotky;
    jednotky = temperature%10;
    return jednotky;
  }
int jednotkyF(int temperature)
  {
    int jednotkyF;
    jednotkyF = (temperature - (stovkyF(temperature))*100)-(desiatkyF(temperature)*10);
    return jednotkyF;
  }
int desatiny(float temperature)
  {
     int desatiny;
     int teplota;
     teplota = (temperature*10);
     desatiny = teplota - (desiatky(temperature)*100) - (jednotky(temperature)*10);
     return desatiny;
    
  }
void tempC(float temperature)
{
  if (temperature>0 && temperature<86 )
  { 
    cislo(desiatky(temperature));
    delay(500);
    cislo(10);
    delay(200);
    cislo(jednotky(temperature));
    delay(500);
    cislo(14);
    delay(500);
    cislo(desatiny(temperature));
    delay(500);
    cislo(11);
    delay(500);

  }
  else if(temperature==0)
  {
    cislo(0);
    delay(500);
    cislo(10);
    delay(500);
    cislo(11);
    delay(500);
    cislo(10);
    delay(500);
    cislo(10);
  }
  else if (temperature>-100 && temperature<0)
  {
    
    
  }
  else
  {
    cislo(12);
    delay(500);
    cislo(10);
    delay(500);
  }
}

void tempF(float temperature)
{
  if (temperature>0 && temperature<186 )
  { 
    if (temperature>99){
      cislo(stovkyF(temperature));
      delay(500);
      cislo(10);
      delay(200);
      cislo(desiatkyF(temperature));
      delay(500);
      cislo(10);
      delay(200);
      cislo(jednotkyF(temperature));
      delay(500);
      cislo(15);
      delay(500);
    }
    else
    {
      cislo(desiatky(temperature));
      delay(500);
      cislo(10);
      delay(200);
      cislo(jednotky(temperature));
      delay(500);
      cislo(15);
      delay(500);
    }

  }
  else if(temperature==0)
  {
    cislo(0);
    delay(500);
    cislo(10);
    delay(500);
    cislo(11);
    delay(500);
    cislo(10);
  }
  else
  {
    cislo(12);
    delay(500);
    cislo(10);
    delay(500);
  }
}
void cislo(int x)
{

digitalWrite(latch, LOW);
for (int i = 7; i>=0; i--)
{
digitalWrite(clock, LOW);
digitalWrite(data, znaky[x][i] );
digitalWrite(clock, HIGH);
}
digitalWrite(latch, HIGH);
}
int BTN()
{ 
  int state = digitalRead(button);
  delay(100);
  return state;
}
void menu()
{ 
  state = 11;
  while (1==1)
  {
    if(counter>21){break;}
    else
    {
      cislo(state);
      
      if (BTN()==0)
      {
        
         counter+=1;
         if (state==11)
           {
              state=15;
           }
         else if (state=15)
           {
              state=11;
           }
         delay(50);
        
      }
      else
      {
        counter = 0;
      }
    }
  }
}
