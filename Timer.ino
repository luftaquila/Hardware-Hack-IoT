void Timer_Reset()
{
  if(timer == 1)
    pressButton(4, 7);
  else if(timer == 2)
    pressButton(4, 6);
  else if(timer == 4)
    pressButton(4, 4);
  timer = 0;
}

void Timer_1h()
{
  Timer_Reset();
  pressButton(4, 1);
  timer = 1;
}

void Timer_2h()
{
  Timer_Reset();
  pressButton(4, 2);
  timer = 2;
}

void Timer_4h()
{
  Timer_Reset();
  pressButton(4, 4);
  timer = 4;
}
