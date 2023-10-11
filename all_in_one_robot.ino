 long lecture_echo; 
long cm;
int RightIR = 9; // connect ir sensor to arduino pin 2
int LeftIR = 8; // connect ir sensor to arduino pin 1

void setup() {
Serial.begin(9600);//sets the baud rate
//ALCOHOL SENSOR
pinMode(A2,INPUT);  // Alcohol_Sensor



//IR SENSOR
pinMode (RightIR, INPUT); // sensor pin INPUT
pinMode (LeftIR, INPUT); // sensor pin INPUT



//ULTRASONIC SENSOR
pinMode(11,OUTPUT);//TO TRIG1
digitalWrite(11, LOW);
  pinMode(12,INPUT);//TO ECHO1



//ROBO CAR MODULE
  pinMode(2,OUTPUT);//motor 1 forward `  
  pinMode(3,OUTPUT);// motor 1 back
  pinMode(4,OUTPUT);//motor 2 forward
  pinMode(5,OUTPUT);// motor 2 back


  pinMode(A0,OUTPUT);//ENA
  pinMode(A1,OUTPUT);//ENB

   

}

void loop()
{
int ss = analogRead(A2);      //Alcohol_Sensor
//Serial.println("Alcohol Value : ");  
//Serial.println(ss);

  //delay(1000);
  if(Serial.available())
{

  
      char ch=Serial.read();
    Serial.println(ch);
      if(ch=='f') // forward robo car
      {
         
         analogWrite(A0, 200);// motor1 speed
          analogWrite(A1, 200);// motor2 speed
         
          digitalWrite(2,HIGH);
          digitalWrite(3,LOW);
          digitalWrite(4,HIGH);
          digitalWrite(5,LOW);
      }
      else if(ch=='b') // backward robo car
      {
       
          digitalWrite(2,LOW);
          digitalWrite(3,HIGH);
          digitalWrite(4,LOW);
          digitalWrite(5,HIGH);  
      }

      else if(ch=='r')// right robo car
      {
         
        digitalWrite(2,LOW);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
      }      
     
      else if(ch=='l')// left robo car
      {
        
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
      }else if(ch=='s')
      {
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
      }
 
}


////ULTRASONIC HAND FOLLOW MODE
//digitalWrite(11, HIGH); 
//  delayMicroseconds(10); 
//  digitalWrite(11, LOW); 
//  lecture_echo = pulseIn(12, HIGH); 
//  cm = lecture_echo / 58; 
// // Serial.print("Distance in cm : "); 
// // Serial.println(cm);
//
//  if(cm<20 && cm>10)
//  {
//     
//          digitalWrite(2,HIGH);
//        digitalWrite(3,LOW);
//        digitalWrite(4,HIGH);
//        digitalWrite(5,LOW);
//  
//           
//  }else if(cm<10 && cm>5)
//  {
//     
//    digitalWrite(2,LOW);
//        digitalWrite(3,HIGH);
//        digitalWrite(4,LOW);
//        digitalWrite(5,HIGH);
//  }

//  //IRSENSOE LINE FOLLOW MODE
//  int LeftSensor = digitalRead (LeftIR);
//  int RightSensor = digitalRead (RightIR);
//
//
//if (LeftSensor == 0 && RightSensor==0){
//
//    digitalWrite(2,HIGH);
//        digitalWrite(3,LOW);
//        digitalWrite(4,HIGH);
//        digitalWrite(5,LOW);
//    Serial.println(" detected");
//  }else if(LeftSensor == 1 && RightSensor==0)
//  {
//  
//    digitalWrite(2,HIGH);
//        digitalWrite(3,LOW);
//        digitalWrite(4,LOW);
//        digitalWrite(5,HIGH);
//  }else if(LeftSensor == 0 && RightSensor==1)
//  {
// 
//    digitalWrite(2,LOW);
//        digitalWrite(3,HIGH);
//        digitalWrite(4,HIGH);
//        digitalWrite(5,LOW);
//  }
  
}
