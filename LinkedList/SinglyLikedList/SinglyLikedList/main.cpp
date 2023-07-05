//
// Created by Manajit Halder
// For Project SinglyLikedList on 12/10/22
// Using Swift 5.0 on MacOS 12.4
// 

#include <iostream>
#include <memory>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class SinglyList {
private:
    Node* head;
    
public:
    SinglyList() {
        head = nullptr;
    }
    ~SinglyList() {}
    
    void addAtEnd(int val);
    void addAtBegining(int val);
    void removeAtBegining();
    void removeAtEnd();
    void reverseList();
    void display();
};

void SinglyList::addAtEnd(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void SinglyList::addAtBegining(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void SinglyList::removeAtBegining() {
    if (head == nullptr) {
        cout << "List is empty (removeAtBegining)" << endl;
    } else {
        cout << "Removing node " << head->data << endl;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void SinglyList::removeAtEnd() {
    if (head == nullptr) {
        cout << "List is empty (removeAtEnd)" << endl;
    } else if (head->next == nullptr) {
        cout << "Removing node " << head->data << endl;
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        cout << "Removing node " << temp->data << endl;
        delete temp;
    }
}

//void SinglyList::reverseList() {
//    Node* temp = head;
//    Node* nextNode = nullptr;
//    Node* reverseNode = nullptr;
//    while (temp != nullptr) {
//        head = temp;
//        nextNode = temp->next;
//        temp->next = reverseNode;
//        reverseNode = temp;
//        temp = nextNode;
//
//    }
//}

void SinglyList::reverseList() {
    Node* temp = head;
    Node* curr = nullptr;
    Node* rev = nullptr;
    while (temp != nullptr) {
        curr = temp;
        curr->next = rev;
        rev = curr;
        temp = temp->next;
    }
    head = rev;
}

void SinglyList::display() {
    if (head == nullptr) {
        cout << "List is empty (display)" << endl;
    } else {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
}

enum Month {
    Jan,
    Feb,
    Mar,
    Apr
};

enum class Book {
    Small,
    Medium,
    Large
};


enum class Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main(int argc, char *argv[]) {
    SinglyList* list = new SinglyList();
    list->addAtEnd(100);
    list->addAtEnd(200);
    list->addAtEnd(300);
    list->addAtBegining(90);
    list->addAtBegining(80);
    
    list->display();
    list->reverseList();
    list->display();
    
    list->removeAtBegining();
    list->display();

    list->removeAtEnd();
    list->display();
    
    return 0;
}




