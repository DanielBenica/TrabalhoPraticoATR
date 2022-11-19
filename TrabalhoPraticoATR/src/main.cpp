#include <iostream>
#include<thread>
#include <string>
#include<chrono>
#include <vector>
#include <mutex>
#include <semaphore>
#include "Motor.h"

#define MAX_MOTORS 30
std::mutex s_mutex;
std::counting_semaphore<12> motorSemphore(12);
using binary_semaphore = std::counting_semaphore<1>;

void write_word(std::string word,int i) {
    motorSemphore.acquire();
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    s_mutex.lock();
    std::cout << std::this_thread::get_id() << " - The word is: " << word << std::endl;
    s_mutex.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    motorSemphore.release();
 
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
        //thread_pool.push_back(std::thread(write_word,palavra,i));
    }

    for (int i = 0; i <=MAX_MOTORS; i++) {
        thread_pool[i].join();
    }
    // Motor m1(1);
    // std::thread t1;
    // t1 = std::thread(&Motor::hello,&m1);
    // t1.join();

    std::cout << "Program ended!";
}


