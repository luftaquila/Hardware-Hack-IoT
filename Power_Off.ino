void Power_Off()
{
  if(mode == 1)
    pressButton(3, 4);

  else if(mode == 2)
    pressButton(3, 3);
    
  else if(mode == 3)
    pressButton(3, 2);
    
  POWER = false;
  mode = 0;
}
