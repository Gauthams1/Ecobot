void T_Chk()
{
  if (sensorNum > 3 && tCount == 0) 
  {
    tChk += 1;
  }
  if(tChk >= 7)
  {
    T_Function(); 
  }
}

void T_Function()
{
  while (sensorNum == 0)
  {
    myServo.write(initial + 70);
    movAvgs();
    
    deviationEcho = deviation;
    deviationLeftEcho = deviationLeft;
    deviation = 0;
    sensorNum = 0;

    colourInputPulse();

    deviationCal();

    tCount = 1;    
  }
}


