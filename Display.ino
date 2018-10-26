void Display(){
  Serial.print("            ");
   for (int i = 0; i < 5; i++) {
      Serial.print(sum[i]/10);
      Serial.print("   ");
    }
    Serial.print((sumLeft+sumRight)/5);Serial.print(" ");
    Serial.print(sumLeft/5);Serial.print(" ");
    Serial.print(sumLeft/5);
}

void displayAll()
{
  analogWrite(s_2, 0);        // 0,0 red    0,1 blue    1,0 gray    1,1 green
  analogWrite(s_3, 0);
   for (int i = 0; i < 5; i++) {
    Serial.print(pulseIn(sensorPin[i], HIGH));
    Serial.print("   ");
  }
  
  Serial.print("    ");

  analogWrite(s_2, 255);        // 0,0 red    0,1 blue    1,0 gray    1,1 green
  analogWrite(s_3, 255);
   for (int i = 0; i < 5; i++) {
    Serial.print(pulseIn(sensorPin[i], HIGH));
    Serial.print("   ");
  }

  Serial.print("    ");

  analogWrite(s_2, 0);        // 0,0 red    0,1 blue    1,0 gray    1,1 green
  analogWrite(s_3, 255);
   for (int i = 0; i < 5; i++) {
    Serial.print(pulseIn(sensorPin[i], HIGH));
    Serial.print("   ");
  }
  Serial.print("    ");

  analogWrite(s_2, 255);        // 0,0 red    0,1 blue    1,0 gray    1,1 green
  analogWrite(s_3, 0);
   for (int i = 0; i < 5; i++) {
    Serial.print(pulseIn(sensorPin[i], HIGH));
    Serial.print("   ");
  }
  Serial.println(" ");
}

