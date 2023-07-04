//
// Created by Manajit Halder
// For Project Observer on 01/11/22
// Using Swift 5.0 on MacOS 12.4
// 

#include <iostream>
#include <list>
using namespace std;

class Messanger {
public:
    virtual void notify(string msg) = 0;
};

class User: public Messanger {
private:
    int id;
public:
    User(int id):id(id) {}
    void notify(string msg) {
        cout << "Message: " << msg << " for User: " << id << endl;
    }
};

class Group {
    list<Messanger*> userList;
    
public:
    Group() {}
    
    void subscribe(Messanger* user) {
        userList.push_back(user);
    }
    
    void unsubscribe(Messanger* user) {
        userList.remove(user);
    }
    
    void notify(string msg) {
        for (auto user: userList) {
            user->notify(msg);
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Group* group = new Group();
    
    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);
    
    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);
    
    group->notify("message 1");
    
    group->unsubscribe(user2);
    
    group->notify("message 2");
    
    return 0;
}
