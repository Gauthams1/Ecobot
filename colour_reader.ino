void colourInputPulse()
{
  for (int i = 0; i < 5; i++) {
    colorRedData[i] = pulseIn(sensorPin[i], HIGH);
  }
  leftData = pulseIn(Left, HIGH);
  rightData = pulseIn(Right, HIGH);
}

