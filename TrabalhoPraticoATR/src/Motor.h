#pragma once
#include <iostream>
#include <thread>
#include <mutex>
class Motor
{
public:
	Motor(int id);
	void hello();
	double getSpeed();
private:
	//Control variables
	int id;
	bool motorState;


	//Motor variables
	static double V;		//armature_voltage
	static double Ra;		//armature_resistance
	static double La;		//armature_inductance
	static double Ia;		//armature_current
	static double Km;		// torque_constant
	static double Tl;		// load_torque
	static double Jm;		//inertia
	static double B;		// viscous_friction
	static double Wm;		//Speed
	static double Kb;		//eletric_constant
};

