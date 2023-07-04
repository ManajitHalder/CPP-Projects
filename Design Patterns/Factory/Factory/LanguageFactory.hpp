//
// Created by Manajit Halder
// For Project Factory on 01/11/22
// Using Swift 5.0 on MacOS 12.4
// 

#ifndef LanguageFactory_hpp
#define LanguageFactory_hpp

#include <iostream>
#include "Language.hpp"
#include "HumanLanguage.hpp"
#include "AnimalLanguage.hpp"
#include "ProgrammingLanguage.hpp"

class LanguageFactory {
public:
    static Language* getLanguage(std::string langType);
};

#endif /* LanguageFactory_hpp */
