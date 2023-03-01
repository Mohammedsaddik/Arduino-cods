#include <PS2X_lib.h>  
#define PS2_DAT        12      
#define PS2_CMD        11  
#define PS2_SEL        10  
#define PS2_CLK        13
int mr1= 6;
int mr2= 8;
int ml1= 4;
int ml2= 5;
int en1;
int en2;  
PS2X ps2x;
int error = 0;
byte type = 0;
byte vibrate = 0;
void setup(){
  pinMode(mr1,OUTPUT);
  pinMode(mr2,OUTPUT);
  pinMode(ml1,OUTPUT);
  pinMode(ml2,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  digitalWrite(en1,HIGH); 
  digitalWrite(en2,HIGH);    
  Serial.begin(9600);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  if(error == 0){
  type = ps2x.readType(); 
}
}
void loop() {
    ps2x.read_gamepad(false, vibrate);    
    if (ps2x.Button(PSB_PAD_UP)) {
      analogWrite(mr1,180);
      analogWrite(mr2,0);
      analogWrite(ml1,180);
      analogWrite(ml2,0);                  }
    if(ps2x.Button(PSB_PAD_RIGHT)){
      analogWrite(mr1,0);
      analogWrite(mr2,180);
      analogWrite(ml1,180);
      analogWrite(ml2,0);                  }
    if(ps2x.Button(PSB_PAD_LEFT)){
      analogWrite(mr1,180);
      analogWrite(mr2,0);
      analogWrite(ml1,0);
      analogWrite(ml2,180);                  }
    if(ps2x.Button(PSB_PAD_DOWN)){
      analogWrite(mr1,0);
      analogWrite(mr2,180);
      analogWrite(ml1,0);
      analogWrite(ml2,180);                    }    
  delay(15);
}
