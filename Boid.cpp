#include "Boid.h"
#define M_PI   3.1415926535897323846

/* Define the functions below */

Boid::Boid(int x, int y, int xbound, int ybound,
        int     mboundaryPadding    ,
        float   mmaxSpeed           ,
        float   mmaxForce           ,
        float   mflockSepWeight     ,
        float   mflockAliWeight     ,
        float   mflockCohWeight     ,
        float   mflockSepRadius     ,
        float   mflockAliRadius     ,
        float   mflockCohRadius     )
{
	acc = new Vec2f(0,0);
	orient = (rand()%1)*M_PI;
	vel = new Vec2f(cos(angle), sin(angle));
	loc = new Vec2f(x,y);
	r = 2.0;
	mmaxSpeed = 2;
	mmaxForce = 0.03;
}

Vec2f addition(Vec2f vector_1, Vec2f vector_2){
	Vec2f vector_3;
	float _x_1 = vector_1.x;
	float _y_1 = vector_1.y;
	float _x_2 = vector_2.x;
	float _y_2 = vector_2.y;
	float vector_3.x = vector_1.x + vector_2.x;
	float vector_3.y = vector_1.y + vector_2.y;
	return vector_3;
}

Vec2f sub(Vec2f vector_1, Vec2f vector_2){
	Vec2f vector_3;
	float _x_1 = vector_1.x;
	float _y_1 = vector_1.y;
	float _x_2 = vector_2.x;
	float _y_2 = vector_2.y;
	float vector_3.x = vector_1.x - vector_2.x;
	float vector_3.y = vector_1.y - vector_2.y;
	return vector_3;
}
	
// Method to update location
void Boid::update(vector<Boid> &boids) {
	//updating the velocity
	vel = addition(vel,acc);
	loc = addition(loc,vel);
	//make acceleration zero after each cycle
	acc = acc * 0;
}

Vec2f normalize(Vec2f vector_1){
	float _x = vector_1.x;
	float _y = vector_1.y;
	float _result = sqrt(_x*_x + _y*_y);
	vector.x = (vector_1.x)/_result;
	vector.y = (vector_1.y)/_result;
	return vector;
}

void Boid::seek(Vec2f target,float weight) {
	Vec2f desired = sub(target,loc);
	desired = normalize(desired);
	desired = desired*mmaxSpeed;
	
	Vec2f steer = sub(desired,vel);
	while(steer < mmaxForce){
		return steer;
	}
}

void Boid::avoid(Vec2f target,float weight) {
}

void Boid::boundCheck(int padding) {

  


}


// A method that calculates a steering vector towards a target
/*Vec2f Boid::steer(Vec2f target) {
   
}*/


void Boid::flock(vector<Boid> &boids) {
	
	
}

bool Boid::isHit(int x, int y, int radius) {
    
}

float distance(Vec2f vector_1, Vec2f vector_2){
	float _1_x = vector_1.x;
	float _1_y = vector_1.y;
	float _2_x = vector_2.x;
	float _2_y = vector_2.y;
	float _x_dif = (_2_x - _1_x);
	float _y_dif = (_2_y - _1_y);
	float _result = sqrt((_x_dif)*(_x_dif) + (_y_dif)*(_y_dif));
	return _result;
}

float magnitute(Vec2f vector_1){
	return sqrt((vector_1.x)*(vector_1.x) + (vector_1.y)*(vector_1.y)); 
}

Vec2f divide(Vec2f vector_1, int val){
	vector_1.x = vector_1.x / val;
	vector_1.y = vector_1.y / val;
	return vector_1;
}

// Separation
// Method checks for nearby boids and steers away
Vec2f Boid::separate(vector<Boid> &boids) {
    mflockSepWeight = 25.0f;
    Vec2f steer = new Vec2f(0,0,0);
    int count = 0;
    //for each boid check if it's too close
    for(int i=0;i<boids.size();i++){
		Boid other = boids[i];
		float d = distance(loc, other.loc);
		if ((d>0) && (d < mflockSepWeight)){
			//calculating vector pointing away from the neighbor
			Vec2f diff = sub(loc, boids[i]);
			diff = normalize(diff);
			diff = diff/d;
			steer = addition(steer, diff);
			count++;
		}
	}
	if (count > 0){
		steer = divide(steer,count);
	}
	if (magnitute(steer) > 0){
		steer = normalize(steer);
		steer = steer * mmaxSpeed;
		steer = steer - vel;
		while(steer < mmaxForce){
		}	
	}
	return steer;
}

// Alignment
// For every nearby boid in the system, calculate the average velocity
Vec2f Boid::align(vector<Boid> &boids) {
    float neighordistance = 50;
    Vec2f sum = new Vec2f(0,0);
    int count = 0;
    for(int i=0;i<boids.size();i++){
		Boid other = boids[i];
		float d = distance(loc, other.loc);
		if((d>0) && (d < neighordistance)){
			//need to figure out this
			sum = addition(sum, other);
			count++;
		}
	}
	if(count > 0){
		sum = divide(sum, count);
		sum = normalize(sum);
		sum = sum*mmaxSpeed;
		Vec2f steer = sub(sum , vel);
		if(steer < mmaxForce){
			return steer;
		}
		else{
			return new Vec2f(0,0);
		}    
	}
}

// Cohesion
// For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
Vec2f Boid::cohesion(vector<Boid> &boids) {
   float neighbordist = 50;
   Vec2f sum = new Vec2f(0,0);
   int count = 0;
   for(int i=0;i<boids.size();i++){
		Boid other = boids[i];
		float d = distance(loc, other.loc);
		if((d>0) && (d < neighbordist)){
			//need to figure out
			sum = addition(sum, other);
			count++
		}
	}
	if (count > 0){
		sum = divide(sum, count);
		return seek(sum,1);
	}
	else{
		return new Vec2f(0,0);
	}
}


float Boid::dist(Vec2f v1,Vec2f v2)
{
}

float Boid::clamp(float val, float minval, float maxval)
{
    
}
