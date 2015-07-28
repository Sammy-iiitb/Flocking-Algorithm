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

// Method to update location
void Boid::update(vector<Boid> &boids) {
	//updating the velocity
	vel += acc;
	loc += vel;
	//make acceleration zero after each cycle
	acc = acc * 0;
}

Vec2f normalize(Vec2f vector){
	float _x = vector.x;
	float _y = vector.y;
	float _result = sqrt(_x*_x + _y*_y);
	vector.x = (vector.x)/_result;
	vector.y = (vector.y)/_result;
	return vector;
}

void Boid::seek(Vec2f target,float weight) {
	Vec2f desired = target - loc;
	desired = normalize(desired);
	desired = desired*mmaxSpeed;
	
	Vec2f steer = desired - vel;
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

// Separation
// Method checks for nearby boids and steers away
Vec2f Boid::separate(vector<Boid> &boids) {
    mflockSepWeight = 25.0f;
    Vec2f steer = new Vec2f(0,0,0);
    int count = 0;
    //for eacn boid check if it's too close
    for(int i=0;i<boids.size();i++){
		Boid other = boids[i];
		float d = distance(loc, boids[i]);
		if ((d>0) && (d < mflockSepWeight)){
			//calculating vector pointing away from the neighbor
			Vec2f diff = loc - boids[i];
			diff = normalize(diff);
			diff = diff/d;
			steer. = steer + diff;
			count++;
		}
	}
	if (count > 0){
		steer 
	}
	if (magnitute(steer) > 0){
		steer = normalize(steer);
		steer = steer * mmaxSpeed;
		steer = steer - vel;
		while(steer < mmaxForce){
	}
	return steer;
}

// Alignment
// For every nearby boid in the system, calculate the average velocity
Vec2f Boid::align(vector<Boid> &boids) {
    
}

// Cohesion
// For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
Vec2f Boid::cohesion(vector<Boid> &boids) {
   
}


float Boid::dist(Vec2f v1,Vec2f v2)
{
}

float Boid::clamp(float val, float minval, float maxval)
{
    
}
