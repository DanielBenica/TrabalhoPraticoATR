#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

#define MAX_MOTORS 30
class Motor
{
public:
	Motor(int id);
	void hello();
	double getSpeed(double v);
private:
	//Control variables
	int id;
	bool motorState;
	static bool lista[MAX_MOTORS];
	static int count;


	


	//Motor variables
	const double V = 0;		//armature_voltage
	const double Ra = 3;		//armature_resistance
	const double La = 0.006;		//armature_inductance
	const double Ia = 2;		//armature_current
	const double Km = 0;		// torque_constant
	const double Tl = 0;		// load_torque
	const double Jm = 0.000006;		//inertia
	const double B = 0.0000004;		// viscous_friction
	const double Kb = 0.0;		//eletric_constant
	double 	Wm = 0;				//Speed
	double Tm = 0.1;				//torque
};

