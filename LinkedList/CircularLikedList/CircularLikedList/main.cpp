//
// Created by Manajit Halder
// For Project CircularLikedList on 13/10/22
// Using Swift 5.0 on MacOS 12.4
// 

#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    Node* link;
};

class CircularList {
private:
    Node* head;
    
public:
    CircularList(): head(nullptr) {}
    ~CircularList() {}
    
    void addAtBegining(int data);
    void addAtEnd(int data);
    void removeAtBegining();
    void removeAtEnd();
    void display();
};

void CircularList::addAtBegining(int value) {
    Node* newnode = new Node;
    newnode->data = value;

    if (head == nullptr) {
        head = newnode;
        head->link = head;
        newnode->link = head;
    } else {
        if (head->link == head){
            newnode->link = head;
            head->link = newnode;
        } else {
            Node* temp = head;
            while (temp->link != head) {
                temp = temp->link;
            }
            temp->link = newnode;
        }
        newnode->link = head;
        head = newnode;
    }
}

void CircularList::addAtEnd(int value) {
    
}

void CircularList::removeAtBegining() {
    
}

void CircularList::removeAtEnd() {
    
}

void CircularList::display() {
    if (head == nullptr) {
        cout << "Circular List empty (display)" << endl;
    }
    else if (head->link == head) {
        cout << head->data << " -> ";
    }
    else {
        Node* temp = head;
        cout << temp->data << " -> ";
        temp = head->link;
        while (temp != head) {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
    }
    cout << " nullptr" << endl << endl;
}

int main(int argc, const char * argv[]) {
    CircularList* clist = new CircularList();
    clist->display();

    clist->addAtBegining(120);
    clist->display();
    clist->addAtBegining(220);
    clist->display();
    clist->addAtBegining(320);
    clist->display();
    clist->addAtBegining(420);
    clist->display();
    clist->addAtBegining(520);
    clist->display();
    clist->addAtBegining(620);
    clist->display();
    clist->addAtBegining(720);
    clist->display();
    
    return 0;
}
