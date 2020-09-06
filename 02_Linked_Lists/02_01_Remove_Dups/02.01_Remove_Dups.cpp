/*
* CtCI 6th Ed | Ch 1: Linked Lists
* 2.1: Remove Dups (pg 94)
*/

#include <iostream>
#include <map>

// Node class
class Node {
public:
    int data;
    Node* next;
    Node() : data{0}, next{nullptr} {}
    Node(int data) : data{data}, next{nullptr} {}
};

// LinkedList class
class LinkedList {
public:
    LinkedList();
    void printLinkedList() const;
    void removeDups();

private:
    Node* _head;
    Node* _n2;
    Node* _n3;
    Node* _n4;
    Node* _n5;
    Node* _n6;
    Node* _n7;
};

// LinkedList constructor
LinkedList::LinkedList() {
    _head = new Node(40);
    _n2 = new Node(20);
    _n3 = new Node(10);
    _n4 = new Node(20);
    _n5 = new Node(50);
    _n6 = new Node(10);
    _n7 = new Node(5);

    _head->next = _n2;
    _n2->next = _n3;
    _n3->next = _n4;
    _n4->next = _n5;
    _n5->next = _n6;
    _n6->next = _n7;
}

// LinkedList class method for printing LinkedList
void LinkedList::printLinkedList() const {
    Node* curr_node = _head;

    while (curr_node) {
        std::cout << curr_node->data << " --> ";
        curr_node = curr_node->next;
    }

    std::cout << "nullptr\n";
}

// remove duplicates in an unsorted linked list
// using temporary buffer- std::map
// which will keep count of occurance of each element
void LinkedList::removeDups() {
    std::map<int, int> node_map;
    Node* curr_node = _head;
    Node* next_node = curr_node->next;

    node_map[curr_node->data]++;

    while (next_node) {
        if (node_map[next_node->data] < 1) {
            node_map[next_node->data]++;
            curr_node = next_node;
            next_node = curr_node->next;
        } else {
            next_node = next_node->next;
            delete curr_node->next;
            curr_node->next = next_node;
        }
    }
}

int main() {
    LinkedList list;
    std::cout << "Initial linked list:       ";
    list.printLinkedList();
    list.removeDups();
    std::cout << "After removing duplicates: ";
    list.printLinkedList();

    return 0;
}