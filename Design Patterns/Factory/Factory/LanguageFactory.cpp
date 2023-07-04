//
// Created by Manajit Halder
// For Project Factory on 01/11/22
// Using Swift 5.0 on MacOS 12.4
// 

#include "LanguageFactory.hpp"
using namespace std;

Language* LanguageFactory::getLanguage(string langType) {
    Language* lang;
    
    if (langType == "human") {
        lang = new HumanLanguage();
    } else if (langType == "animal") {
        lang = new AnimalLanguage();
    } else if (langType == "programming") {
        lang = new ProgrammingLanguage();
    } else {
        lang = nullptr;
    }
    
    return lang;
}
