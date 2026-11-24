#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node {
    int value;
    Node* next; //points to the next node

    Node(int val) : value(val), next(nullptr){} //constructor for creating a new node 

};

class LinkedList {
    private:
        Node* head; //points to the first node

    public:

        LinkedList(){
            head = nullptr;
        }

        void add(int value){
            Node* newNode = new Node(value); //new node to be added

            //case 1: the list is empty 
            if (head == nullptr){
                head = newNode;
                return;
            }

            //case 2: traverse the linked list until we reach the last node
            Node* current = head; //first node in linked list
            while (current ->next != nullptr){ //goes through until the point is null
                current = current -> next; //sets current to the pointer in the Node, which 
                //the original pointer was pointing too
            }
            
            current ->next = newNode; //attach the new node to the end (whichever pointer was null)
                
        }



};


#endif
