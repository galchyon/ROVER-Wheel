#include <rover_Rad.h>

Rad::Rad(float x_wert, float y_wert){
	x=x_wert;
	y=y_wert;
};


//input: winkel fuer Rover in grad und y von Drehzentrum
float Rad::get_x_Dreh(float angle, float y_Dreh){
	//grad in radian
	double angle_rad= angle * 3.14159 / 180;
	//bestimmung tangens von winkel fuer rover
	double tan_angle = tan(angle_rad);
	
	//bestimmung x-Drehzentrum
	float x_Dreh=x -(y - y_Dreh)/tan_angle;
	//int x_Dreh_int=int(x_Dreh);
return x_Dreh;};

//input: koordunaten vom drehzentrum
float Rad::get_Rad_angle(float x_Dreh, float y_Dreh, float angle){
	//bestimmung von delta x und delta y (delta x = x vom Rad - x von Drehzentrum....)
	float dx= x - x_Dreh;
	float dy= y - y_Dreh;
	/*Serial.print("dx: ");  
Serial.println(dx);
Serial.print("dy: ");  
Serial.println(dy);*/
	//bestimmung von tanges des rad winkels
	//double for_tan = dy / dx;
	/*Serial.print("for_tan: ");  
Serial.println(for_tan);*/
	//bestimmung von arctangens also des rad winkels in rad
	float angle_r = atan2(dy, dx);
	/*Serial.print("angle_r: ");  
Serial.println(angle_r);*/
	//radian in grad
	float angle_grad = angle_r * 180 / 3.14159;
	/*Serial.print("angle_grad: ");  
Serial.println(angle_grad);*/
	// abrunden des rad winkels in grad
	//double angle_grad_round=round(angle_grad);
	/*Serial.print("angle_grad_round: ");  
Serial.println(angle_grad_round);*/
	// aus float in integer
	//int rad_angle_int = int(angle_grad_round);
	/*if(x<0 and angle>0){
		int rad_angle_int_negativ_x = -1 * rad_angle_int;
	return rad_angle_int_negativ_x;}
	if(y>0 and angle<0){
		int rad_angle_int_negativ_x = -1 * rad_angle_int;
	return rad_angle_int_negativ_x;}*/
	/*Serial.print("rad_angle_int: ");  
Serial.println(rad_angle_int);*/
	/*int rad_angle_grad_schtrich = 60 - rad_angle_int;
	Serial.print("rad_angle_grad_schtrich: ");  
Serial.println(rad_angle_grad_schtrich);*/
return angle_grad;};

float Rad::get_radius(float x_Dreh, float y_Dreh){
	float dx = x - x_Dreh;
	float dy = y - y_Dreh;
	float quadrat_r = dx*dx + dy*dy;
	/*Serial.print("quadrat_r: ");  
Serial.println(quadrat_r);*/
	float radius = sqrt(quadrat_r);
	/*Serial.print("radius: ");  
Serial.println(radius);*/
return radius;}

float Rad::get_velocity(float radius, float winkel_geschw){
	float winkel_geschw_rad = winkel_geschw * 3.14 / 180;
	float velocity = radius * winkel_geschw_rad;
return velocity;}

