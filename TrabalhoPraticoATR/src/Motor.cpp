#include "Motor.h"
#include <iostream>
#include <thread>
#include <mutex>
#include<math.h>

std::mutex M;
Motor::Motor(int id) {
	this->id = id;
	this->motorState = false;
}

//this function simulates the block diagram, given by the professor
double Motor::getSpeed(double v) {
	return 2.0;
}


void Motor::hello() {

	while (true) {
	
		// int after = id -1;
		// int before = id +1;
		// // if(after < 0){ before=0;}
		// // if(after > 29){ after=0;}

		// // if(before || after){
		// // 	M.unlock();
		// // 	break;
		// // }
		M.lock();
		if(!lista[id -1] && !lista[id +1]){
		lista[id]=1;
		std::cout << "My id is:" << id <<" My state: "<< lista[id] <<std::endl;
		M.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		lista[id]=0;
		}
		else{M.unlock();}
		
	}
}
bool Motor::lista[MAX_MOTORS] = {0};
int Motor::count = 0;
