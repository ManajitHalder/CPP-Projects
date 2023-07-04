//
// Created by Manajit Halder
// For Project Singleton on 01/11/22
// Using Swift 5.0 on MacOS 12.4
// 

#include "logger.hpp"
using namespace std;

Logger* Logger::loggerInstance = nullptr;
mutex Logger::mu;

Logger::Logger() {}

Logger* Logger::getInstance() {
    if (loggerInstance == nullptr) {
        mu.lock();
        if (loggerInstance == nullptr) {
            loggerInstance = new Logger();
        }
        mu.unlock();
    }
    return loggerInstance;
}

void Logger::log(string message) {
    cout << message << endl;
}
