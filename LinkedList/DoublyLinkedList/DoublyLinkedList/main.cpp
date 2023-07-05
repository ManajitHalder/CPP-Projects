//
// Created by Manajit Halder
// For Project DoublyLinkedList on 13/10/22
// Using Swift 5.0 on MacOS 12.4
// 

#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class DoublyList {
private:
    Node* head;
    
public:
    DoublyList() {
        head = nullptr;
    }
    ~DoublyList() {}
    
    void addAtEnd(int val);
    void addAtBegining(int val);
    void removeAtBegining();
    void removeAtEnd();
    void reverseList();
    void display();
};

void DoublyList::addAtBegining(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->prev = nullptr;
    
    if (head == nullptr) {
        newnode->next = nullptr;
        newnode->prev = nullptr;
    } else {
        newnode->next = head;
        head->prev = newnode;
    }
    head = newnode;
}

void DoublyList::addAtEnd(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = nullptr;
    
    if (head == nullptr) {
        newnode->prev = nullptr;
        head = newnode;
    } else if (head->next == nullptr) {
        head->next = newnode;
        newnode->prev = head;
    }else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void DoublyList::removeAtBegining() {
    if (head == nullptr) {
        cout << "Doubly List is empty (removeAtBegining)" << endl;
    } else if (head->next == nullptr) {
        cout << head->data << " is getting deleted (removeAtBegining)" << endl;
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        cout << temp->data << " is getting deleted" << endl;
        delete temp;
    }
}

void DoublyList::removeAtEnd() {
    if (head == nullptr) {
        cout << "Doubly List is empty (removeAtEnd)" << endl;
    } else if (head->next == nullptr) {
        cout << head->data << " is getting deleted (removeAtEnd)" << endl;
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        Node* beforeLast = nullptr;
        while (temp->next != nullptr) {
            beforeLast = temp;
            temp = temp->next;
        }
        cout << temp->data << " is getting deleted (removeAtEnd)" << endl;
        beforeLast->next = nullptr;
        delete temp;
    }
}

void DoublyList::display() {
    if (head == nullptr) {
        cout << "Doubly List is empty (display)" << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl << endl;
    }
}

int main(int argc, char *argv[]) {
    DoublyList* dlist = new DoublyList();
    
    dlist->addAtBegining(1000);
    dlist->addAtBegining(2000);
    dlist->addAtBegining(3000);
    dlist->addAtBegining(4000);
    dlist->display();
    
    dlist->addAtBegining(900);
    dlist->addAtBegining(800);
    dlist->addAtBegining(700);
    dlist->addAtBegining(600);
    dlist->addAtBegining(500);
    dlist->display();
    
    dlist->removeAtBegining();
    dlist->display();

    dlist->removeAtEnd();
    dlist->display();

    delete dlist;
    
    return 0;
}


