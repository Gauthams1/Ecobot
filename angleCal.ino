void deviationCal()
{
  for (int i = 0; i < 5; i++) 
  {
    if (sum[i] / 10 < ThresholdRed[i]) 
    {
      deviation -= 2 * i - 4;
      sensorNum++;
    }
  }
  deviationLeft = (sumLeft/5 <leftThresh ? 1:0);
  deviationRight = (sumLeft/5 <leftThresh ? 1:0);

   if (sensorNum != 0)
   {
    deviation = deviation / sensorNum;
   }
   
   if(deviation == 0 && sensorNum == 0)
   {
    deviation = deviationEcho;
   }  
}

void movAvgs()
{
  sum[0] += -cored[b][0] + colorRedData[0];
  sum[1] += -cored[b][1] + colorRedData[1];
  sum[2] += -cored[b][2] + colorRedData[2];
  sum[3] += -cored[b][3] + colorRedData[3];
  sum[4] += -cored[b][4] + colorRedData[4];

  sumLeft += -coleft[d] + leftData;
  sumRight += -coright[d] + rightData;
  
  cored[b][0] = colorRedData[0];
  cored[b][1] = colorRedData[1];
  cored[b][2] = colorRedData[2];
  cored[b][3] = colorRedData[3];
  cored[b][4] = colorRedData[4];
  
  coleft[d] = leftData;
  coright[d] = rightData;

  b++; b = b % 10;
  d++; d %= 10;
}

void angleCal()
{
  desPos = constrain(desPos, -50, 50);
    
  if (deviationEcho == 4 && sensorNum == 0 && desPos <= 45) {
    desPos += 2;
  }
  else if (deviationEcho == -4 && sensorNum == 0 && desPos >= -45) {
    desPos += -2;
  }
  else if (deviation == -4) {
    desPos = -20;
  }
  else if (deviation == -3) {
    desPos = -12;
  }
  else if (deviation == -2) {
    desPos = -8;
  }
  else if (deviation == -1) {
    desPos = -4;
  }
  else if (deviation == 0) {
    desPos = 0;
  }
  else if (deviation == 1) {
    desPos = 4;
  }
  else if (deviation == 2) {
    desPos = 8;
  }
  else if (deviation == 3) {
    desPos = 12;
  }
  else if (deviation == 4) {
    desPos = 20;
  }
}  

void angleCalBlue()
{
  desPos = constrain(desPos, -40, 40);
  
  if(sensorNum > 2 && deviation > 0) {
    deviation = 4;
  }
  else if (sensorNum > 2 && deviation < 0) {
    deviation = -4; 
  }

  if (deviationEcho >= 1 && sensorNum == 0 && desPos <= 40) {
    desPos += 5;
  }
  else if (deviationEcho <= -1 && sensorNum == 0 && desPos >= -40) {
    desPos += -5;
  }

  if (deviation == -4) {
    desPos = -34;
  }
  else if (deviation == -3) {
    desPos = -12;
  }
  else if (deviation == -2) {
    desPos = -4;
  }
  else if (deviation == -1) {
    desPos = -2;
  }
  else if (deviation == 0) {
    desPos = 0;
  }
  else if (deviation == 1) {
    desPos = 2;
  }
  else if (deviation == 2) {
    desPos = 4;
  }
  else if (deviation == 3) {
    desPos = 12;
  }
  else if (deviation == 4) {
    desPos = 34;
  }  
}

