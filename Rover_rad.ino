#include <rover_Rad.h>
#include <Servo.h>
//rechts vorne
Rad rad_1(100, 150);
//links vorne
Rad rad_2(-100, 150);
//links unten
Rad rad_3(-100, -150);
//rechts unten
Rad rad_4(100, -150);

int rad_nummer;
float neut_pos = 92.5;

Rad my_rads [] = {rad_1, rad_2, rad_3, rad_4};

//virtuell oder referenz rad, vorne in der Mitte
Rad virt_Rad(0, 150);

// winkel für den Rover
float winkel;
float winkel_geschw = 10;

//x des Drehzentrums
float x_Dreh;
//y des drehzentrums - ist konstant
float y_Dreh = 0;

//winkel des rads rechts vorne
float winkel_r1;
//winkel des rads links vorne
float winkel_r2;
//winkel des rads links unten
float winkel_r3;
//winkel des rads rechts unten
float winkel_r4;

//lineare geschwindigkeit des rads rechts vorne
float r_v_1;
//lineare geschwindigkeit des rads links vorne
float r_v_2;
//lineare geschwindigkeit des rads links unten
float r_v_3;
//lineare geschwindigkeit des rads rechts unten
float r_v_4;

float rad_radius;
float rad_velocity;

float rad_winkels [] = {winkel_r1, winkel_r2, winkel_r3, winkel_r4 };
float rad_velocities [] = {r_v_1, r_v_2, r_v_3, r_v_4};

float my_Rad_wink;
float my_Rad_wink_mit_korrektur;

//drehradius für jeden rad
float radius_r1;
float radius_r2;
float radius_r3;
float radius_r4;

//rechts vorne
Servo ser1;
//links vorne
Servo ser2;
//links unten
Servo ser3;
//rechts unten
Servo ser4;

Servo servos[] = {ser1, ser2, ser3, ser4};


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
neutral();  
calibration();
  
  if(Serial.available()>0)
  {winkel = Serial.parseInt();
  Serial.print("clearing buffer: ");
  Serial.println(Serial.read() - '0');
  
Serial.print("winkel: ");
Serial.println(winkel);
x_Dreh = virt_Rad.get_x_Dreh(winkel, y_Dreh);
Serial.print("x_Dreh: ");
Serial.println(x_Dreh);
for(int r=0; r<4; r++){
rad_nummer = r+1;
Serial.print("Rad Nummer: ");
Serial.println(rad_nummer);

my_Rad_wink = my_rads[r].get_Rad_angle(x_Dreh, y_Dreh, winkel);
rad_winkels[r] = my_Rad_wink;
Serial.print("my_Rad_wink: ");
Serial.println(my_Rad_wink);
my_Rad_wink_mit_korrektur = 90 + my_Rad_wink;
Serial.print("my_Rad_wink mit Korrektur: ");
Serial.println(my_Rad_wink_mit_korrektur);
rad_radius = my_rads[r].get_radius(x_Dreh, y_Dreh);
Serial.print("drehradius: ");
Serial.println(rad_radius);
rad_velocity = my_rads[r].get_velocity(rad_radius, winkel_geschw);
rad_velocities [r] = rad_velocity;
Serial.print("rad_velocity: ");
Serial.println(rad_velocity);}

delay(1000);

}
void servo_in_position();
delay(1500);
void neutral();
}

void neutral()
{for(int i=0; i<4; i++)
  {servos[i].write(neut_pos);
  }
 delay(100);
}

void servo_in_position()
{for(int i=0; i<4;i++)
  {servos[i].write(neut_pos+rad_winkels [i]);
  delay(50);
}
}
void calibration()
{
for(int i=0; i<2; i++)
  {servos[i].write(neut_pos-40);
  }
  for(int i=2; i<4;i++)
  {servos[i].write(neut_pos+40);
  }
  delay(500);
  
  neutral();
  
  for(int i=0; i<2; i++)
  {servos[i].write(neut_pos+40);
  }
  for(int i=2; i<4;i++)
  {servos[i].write(neut_pos-40);
  }
  delay(500);
  
  neutral();
}
