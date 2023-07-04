//
// Created by Manajit Halder
// For Project Singleton on 01/11/22
// Using Swift 5.0 on MacOS 12.4
// 

#ifndef logger_hpp
#define logger_hpp

#include <iostream>
#include <mutex>

class Logger {
private:
    Logger();
    Logger(const Logger& log);
    const Logger& operator=(const Logger& log);
    static Logger* loggerInstance;
    static std::mutex mu;
    
public:
    static Logger* getInstance();
    void log(std::string message);
};

#endif /* logger_hpp */
