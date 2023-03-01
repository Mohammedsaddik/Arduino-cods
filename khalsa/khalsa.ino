#include <PS2X_lib.h>  //مكتبة الدراع
int vSpeed; //متغير للتحكم في سرعة الروبوت بالبلوتوث
int state; //متغير لتخزين قراءة البلوتوث
int motora1=3; //الاشارة الاولى للموتور الاول
int motora2=5; //الاشارة الثانية للموتور الاول
int motorb1=9; //الاشارة الاولى للموتور الثاني
int motorb2=10; //الاشارة الثانية للموتور الثاني
#define PS2_DAT        13  //تعريف الداتا للدراع    
#define PS2_CMD        12  //تعريف الكوماند للدراع    
#define PS2_SEL        11  //تعريف السيليكشن للدراع
#define PS2_CLK        8  //تعريف الكلوك للدراع 

#define pressures   false  //تعريف للدراع
#define rumble      false //تعريف للدراع

PS2X ps2x; //عمل اوبجكت من مكتبة للدراع

int error = 0; //تعريف للخطأ في الدراع
byte type = 0; //تعريف التايب للدراع
byte vibrate = 0; //تعريف الفايبريشن للدراع

void setup(){
  Serial.begin(9600); //تفعيل السيريال كوميونيكيشن شيب
  delay(300); //استرخاء لمدة 300 ميللي ثانية
  //تعريف المواتير كخرج للاوردوينو
  pinMode(motora1,OUTPUT);
  pinMode(motora2,OUTPUT);
  pinMode(motorb1,OUTPUT);
  pinMode(motorb2,OUTPUT);
  //تعريف للمكتبة
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  
  if(error == 0){
  
  type = ps2x.readType(); 
}
}

void loop() {
  // أخذ قراءة البلوتوث و تسجيلها في المتغير state
if(Serial.available() >0)
  {
    state = Serial.read();
  }
   //التحكم في السرعات باستخدام الشريط في البرنامج وتسجيلها في متغير vSpeed
   if (state == '0'){
      vSpeed=0; }
    else if (state == '1'){
      vSpeed=25;}
    else if (state == '2'){
      vSpeed=50;}
    else if (state == '3'){
      vSpeed=75;}
    else if (state == '4'){
      vSpeed=100;}
    else if (state == '5'){
      vSpeed=125;}
    else if (state == '6'){
      vSpeed=150;}
    else if (state == '7'){
      vSpeed=175;}
    else if (state == '8'){
      vSpeed=200;}
    else if (state == '9'){
      vSpeed=225;}
    else if (state == 'q'){
      vSpeed=255;}

//تحريك الروبوت للأمام بالبلوتوث
if(state=='F')
{
  analogWrite(motora1, vSpeed);
  analogWrite(motorb1, vSpeed);
  analogWrite(motora2, 0);
  analogWrite(motorb2, 0);
}
//تحريك الروبوت للخلف بالبلوتوث
else if(state=='B')
{
  analogWrite(motora1, 0);
  analogWrite(motorb1, 0);
  analogWrite(motora2, vSpeed);
  analogWrite(motorb2, vSpeed);
}
//تحريك الروبوت لليمين بالبلوتوث
else if(state=='R')
{
  analogWrite(motora1, 0);
  analogWrite(motorb1, vSpeed);
  analogWrite(motora2, vSpeed);
  analogWrite(motorb2, 0);  
}
//تحريك الروبوت للشمال باستخدام البلوتوث
else if(state=='L')
{
  analogWrite(motora1, vSpeed);
  analogWrite(motorb1, 0);
  analogWrite(motora2, 0);
  analogWrite(motorb2, vSpeed);  
}
//ايقاف الروبوت بالبلوتوث
else if(state == 'S')
{
  analogWrite(motora1, 0);
  analogWrite(motorb1, 0);
  analogWrite(motora2, 0);
  analogWrite(motorb2, 0);  
}  
//تشغيل الدراع
    ps2x.read_gamepad(false, vibrate);
    //تحريك الروبوت للأمام باستخدام الدراع
    if (ps2x.Button(PSB_PAD_UP)) {    
      digitalWrite(motora1,HIGH);
      digitalWrite(motorb1,HIGH);
      digitalWrite(motora2,LOW);
      digitalWrite(motorb2,LOW);
    }
    //تحريك الروبوت لليمين باستخدام الدراع
  else  if(ps2x.Button(PSB_PAD_RIGHT)){
      digitalWrite(motora1,LOW);
      digitalWrite(motorb1,HIGH);
      digitalWrite(motora2,HIGH);
      digitalWrite(motorb2,LOW);
    }
    //تحريك الروبوت للشمال باستخدام الدراع
   else if(ps2x.Button(PSB_PAD_LEFT)){
      digitalWrite(motora1,HIGH);
      digitalWrite(motorb1,LOW);
      digitalWrite(motora2,LOW);
      digitalWrite(motorb2,HIGH);
    }
    //تحريك الروبوت للخلف باستخدام الدراع
   else if(ps2x.Button(PSB_PAD_DOWN)){
      digitalWrite(motora1,LOW);
      digitalWrite(motorb1,LOW);
      digitalWrite(motora2,HIGH);
      digitalWrite(motorb2,HIGH);
    }
    //ايقاف الروبوت باستخدام X بالدراع
   else if(ps2x.Button(PSB_CROSS)){
      digitalWrite(motora1,LOW);
      digitalWrite(motorb1,LOW);
      digitalWrite(motora2,LOW);
      digitalWrite(motorb2,LOW);
    }
    //ايقاف الروبوت تلقائي بالدراع
    else{
      digitalWrite(motora1,LOW);
      digitalWrite(motorb1,LOW);
      digitalWrite(motora2,LOW);
      digitalWrite(motorb2,LOW);
    }
    
  delay(30); //استرخاء
}
