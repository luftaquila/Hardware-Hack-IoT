#include <SoftwareSerial.h>
SoftwareSerial BT(6, 7);

boolean ROT = false;
boolean POWER = false;
int mode = 0;
int timer = 0;

String cmd = "";

void setup()
{
  BT.begin(9600);
  pinMode(2, OUTPUT); // rotation
  pinMode(3, OUTPUT); // power/mode
  pinMode(4, OUTPUT); // timer
}

void loop()
{
  while(BT.available())
  {
    char RCV = (char)BT.read();
    cmd += RCV;
    delay(5);
  }
  if(!cmd.equals(""))
  {
    if(cmd == "power" && POWER == false)
    {
      pressButton(3, 1);
      POWER = true;
      mode = 1;
    }
    else if(cmd == "power" && POWER == true)
      Power_Off();
      
    if(cmd == "slow" && POWER == true)
      Wind_Slow();
    if(cmd == "mid" && POWER == true)
      Wind_Midium();
    if(cmd == "fast" && POWER == true)
      Wind_Fast();

    if(cmd == "rot" && POWER == true)
    {
        pressButton(2, 1);
        ROT = !ROT;
    }

    if(cmd == "timerReset" && POWER == true)
      Timer_Reset();
    if(cmd == "1h" && POWER == true)
      Timer_1h();
    if(cmd == "2h" && POWER == true)
      Timer_2h();
    if(cmd == "4h" && POWER == true)
      Timer_4h();
  }
  cmd = "";
  delay(50);
}

void pressButton(int buttonNum, int pressTime)
{
  for(int i = 1; i <= pressTime; i++)
  {
    digitalWrite(buttonNum, HIGH);
    delay(100);
    digitalWrite(buttonNum, LOW);
    delay(100);
  }
}
