void refreshSpectrum() {
  digitalWrite(RESET_PIN , HIGH);
  digitalWrite(RESET_PIN , LOW);

  for (int i = 0; i < N  ; i++)  {  // Change it to reverse
    myOctaves[(N-1)-i].refreshBuffer();
    digitalWrite(STROBE_PIN , LOW);
    myOctaves[(N-1)-i].readVal();
    digitalWrite(STROBE_PIN , HIGH);
    delay(0);
  }
  delay(numOfDelay);
  // DEBUGGING("");

  for (int i = 0; i < N  ; i++)  {
    myOctaves[i].CalcLedsVal();
    myOctaves[i].drawLeds();
    delay(0);
  }
  strip.show();
}

void setSchemeType(int type) {
  if (type==1) {
    RGB clr1, clr2, clr3;
    rainbowFlag = false;
    clr1 = RGB(0, 255, 0);
    clr2 = RGB(255, 255, 0);
    clr3 = RGB(255, 0, 0);
    for (int i = 0; i < N; i++) myOctaves[i].changeColorScheme(1, clr1, clr2, clr3, 0.5, 1);
    for (int i = 0; i < N; i++) myOctaves[i].changeColorScheme(3, clr3, clr2, clr3, 0.5, 1);
  }
  if (type==2) {
    RGB clr;
    rainbowFlag = false;
    int red=random(20,100);
    int green=random(20,100);
    int blue=random(20,100);
    for(int i=0; i<N; i++){
      clr = RGB(red,green,blue);
      red+=20;
      green+=20;
      blue+=20;
      myOctaves[i].changeColorScheme(1, clr, clr, clr, 0.5, 1);
      myOctaves[i].changeColorScheme(3, RGB(250,250,250), clr, clr, 0.5, 1);
    }
  }
  if (type==3) { //rainbow  
    rainbowFlag = true;
  }
}


