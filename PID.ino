void PID()
{
  error = desPos - curPos;// + Kdd * (avgSum / 10);
  errorDiff = error - errorEcho;

  correction = Kp * error + Kd * errorDiff;
  curPos += correction;
  curPos = constrain(curPos, -70, 70);
  myServo.write(initial + curPos);
}

