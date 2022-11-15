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
double Motor::getSpeed() {
	double block1;
	return 2.0;
}


void Motor::hello() {

	while (true) {
		M.lock();
		std::cout << "My id is:" << id << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		M.unlock();
	}
}