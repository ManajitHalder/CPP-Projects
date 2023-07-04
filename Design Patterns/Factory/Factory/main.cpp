//
// Created by Manajit Halder
// For Project Factory on 01/11/22
// Using Swift 5.0 on MacOS 12.4
// 

#include "LanguageFactory.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    string langType;
    cout << "Enter language type: " << endl;
    cin >> langType;
    Language* lang = LanguageFactory::getLanguage(langType);
    if (lang != nullptr) {
        lang->speak();
    }
    
    return 0;
}
