#include <Servo.h>
#include <LiquidCrystal.h>

Servo lever;
LiquidCrystal screen(12, 11, 5, 4, 3, 2);

int cooldown = 0, timewriting = 0, cooldown2 = 0, startingpoint = 0;
int lightcal1, lightval1, lightcal2, lightval2, lightcal3, lightval3, resultnumber = -1, expcool = 0;
bool buttonspin, experimentnumber, rotate = false, timered1, timeredcheck1 = false, timered2;
bool  timeredcheck2 = false, timered3, timeredcheck3 = false, experiment = true, rotateonce = false;
float timer = 0.0, finaltime1, finaltime2, finaltime3;

void setup() {
  Serial.begin(115200);
  screen.begin(16, 2);
  pinMode(9,INPUT);
  lever.attach(8);
  lever.write(0);
  screen.setCursor(0,0);
  screen.print(" t1    t2    t3 ");
}

void loop(){
  buttonspin = digitalRead(9);
  if(buttonspin == HIGH){
    if(rotate == false && cooldown == 0){
      rotate = true;
      rotateonce = true;
    }
    else if(rotate == true && cooldown == 500){
      rotate = false;
      rotateonce = true;
    }
  }
  experimentnumber = digitalRead(7);
  if(experimentnumber == HIGH){
    if(experiment == true && cooldown2 == 0){
      experiment = false;
      startingpoint = 1;
    }
    else if(experiment == false && cooldown2 == 2000){
      experiment = true;
      startingpoint = 2;
    }
  }
  
  //////////////////////////////////
  //////////TRIPLA RAMPA////////////
  //////////////////////////////////
  
  if(experiment == true){
    if(cooldown2 > 0 && startingpoint == 2){
      cooldown2--;
    }
    if(rotate == true){
      if(rotateonce == true){
        lightcal1 = analogRead(A0);
        lightcal2 = analogRead(A1);
        lightcal3 = analogRead(A2);
        lever.write(90);
        rotateonce =false;
      }
     timer++;
     if(timeredcheck1 == false){
       timered1 = false;
     }
     else{
       timered1 = true;
     }
     if(timeredcheck2 == false){
       timered2 = false;
     }
     else{
       timered2 = true;
     }
     if(timeredcheck3 == false){
       timered3 = false;
     }
     else{
       timered3 = true;
     }
     if(cooldown < 500){
       cooldown++;
       delay(1);
     }
     else{
       delay(1);
     }
     }
    else{
     screen.setCursor(0,1);
     screen.print("                ");
     if(rotateonce == true){
      lever.write(0);
      rotateonce = false;
     }
     timer = 0;
     timered1 = true;
     timeredcheck1 = false;
     timered2 = true;
     timeredcheck2 = false;
     timered3 = true;
     timeredcheck3 = false;
     if(cooldown > 0){
      cooldown--;
      delay(1);
    }
  }
    lightval2 = analogRead(A1);
    if(lightval2 < (0.75*lightcal2) && timered2 == false){
     finaltime2 = (timer*1.19)/1000;
     screen.setCursor(6,1);
     screen.print(finaltime2);
     timeredcheck2 = true;
    }
   lightval1 = analogRead(A0);
   if(lightval1 < (0.75*lightcal1) && timered1 == false){
    finaltime1 = (timer*1.19)/1000;
    screen.setCursor(0,1);
    screen.print(finaltime1);
    timeredcheck1 = true;
   }
   lightval3 = analogRead(A2);
   if(lightval3 < (0.75*lightcal3) && timered3 == false){
     finaltime3 = (timer*1.19)/1000;
     screen.setCursor(12,1);
     screen.print(finaltime3);
     timeredcheck3 = true;
    }
  }
  
  ///////////////////////
  //TAUTOCRONA///////////
  ///////////////////////
  
  else{
    if(cooldown2 < 2000 && startingpoint == 1){
      cooldown2++;
    }
    if(rotate == true){
       if(rotateonce == true){
         lightcal2 = analogRead(A1);
         lever.write(90);
         rotateonce = false;
       }
    timer++;
    if(timeredcheck2 == false){
      timered2 = false;
    }
    else{
      timered2 = true;
    }
    if(cooldown < 500){
      cooldown++;
      delay(1);
    }
    else{
      delay(1);
    }
    }
    else{
     if(resultnumber == 2){
       screen.setCursor(0,1);
       screen.print("                ");
       resultnumber = -1;
     }
     lever.write(0);
     timer = 0;
     timered2 = true;
     timeredcheck2 = false;
     if(cooldown > 0){
       cooldown--;
       delay(1);
     }
   }
    lightval2 = analogRead(A1);
    if(lightval2 < (0.75*lightcal2) && timered2 == false){
     finaltime2 = (timer)/1000;
     if(resultnumber < 3){
       resultnumber++;
     }
     else{
       resultnumber = 0;
     }
     screen.setCursor((resultnumber*6),1);
     screen.print(finaltime2);
      timeredcheck2 = true;
    }
  }  
}
