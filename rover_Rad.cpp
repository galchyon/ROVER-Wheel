#include <rover_Rad.h>

Rad::Rad(float x_wert, float y_wert){
	x=x_wert;
	y=y_wert;
};


//input: angle for ROVER in degrees and y-rotation centre
float Rad::get_x_Dreh(float angle, float y_Dreh){
	//degr to rad
	double angle_rad= angle * 3.14159 / 180;
	//finding tan of the angle
	double tan_angle = tan(angle_rad);
	
	//finding x-rotation centre
	float x_Dreh=x -(y - y_Dreh)/tan_angle;
	//int x_Dreh_int=int(x_Dreh);
return x_Dreh;};

//input: coordinates of the rotation centre
float Rad::get_Rad_angle(float x_Dreh, float y_Dreh, float angle){
	//finding deltas
	float dx= x - x_Dreh;
	float dy= y - y_Dreh;
	/*Serial.print("dx: ");  
Serial.println(dx);
Serial.print("dy: ");  
Serial.println(dy);*/
	//finding tangens
	//double for_tan = dy / dx;
	/*Serial.print("for_tan: ");  
Serial.println(for_tan);*/
	//finding arctangens - in rad
	float angle_r = atan2(dy, dx);
	/*Serial.print("angle_r: ");  
Serial.println(angle_r);*/
	//rad to degr
	float angle_grad = angle_r * 180 / 3.14159;
	
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

