#include <iostream>
#include<thread>
#include <string>
#include<chrono>
#include <vector>
#include <mutex>
#include "Motor.h"

#define MAX_MOTORS 30
std::mutex s_mutex;

void write_word(std::string word,int i) {
    s_mutex.lock();
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << std::this_thread::get_id() << " - The word is: " << word << std::endl;
    s_mutex.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}



int main()
{
    std::vector<std::thread> thread_pool;
    std::vector<Motor> motor_pool;
    std::string palavra = "Bom dia";
    std::cout << "Hello World! From main thread\n";

    for (int i = 0; i <= MAX_MOTORS; i++) {
        motor_pool.push_back(i);
    }
    for (int i = 0; i <=MAX_MOTORS; i++) {
        thread_pool.push_back(std::thread(&Motor::hello,&motor_pool[i]));
    }

    for (int i = 0; i <=MAX_MOTORS; i++) {
        thread_pool[i].join();
    }

    std::cout << "Program ended!";
}


