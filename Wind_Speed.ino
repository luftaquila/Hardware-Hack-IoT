void Wind_Slow()
{
  Power_Off();
  POWER = true;
  pressButton(3, 1);
  mode = 1;
}

void Wind_Midium()
{
  Power_Off();
  POWER = true;
  pressButton(3, 2);
  mode = 2;
}

void Wind_Fast()
{
  Power_Off();
  POWER = true;
  pressButton(3, 3);
  mode = 3;
}
