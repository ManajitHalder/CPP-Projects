//
// Created by Manajit Halder
// For Project Singleton on 01/11/22
// Using Swift 5.0 on MacOS 12.4
// 

#include <iostream>
#include "logger.hpp"
#include <thread>
using namespace std;

void logger1() {
    Logger* logger1 = Logger::getInstance();
    logger1->log("log from user 1");
}

void logger2() {
    Logger* logger2 = Logger::getInstance();
    logger2->log("log from user 2");
}

int main(int argc, const char * argv[]) {
    thread th1(logger1);
    thread th2(logger2);
    
    th1.join();
    th2.join();
    
    return 0;
}
