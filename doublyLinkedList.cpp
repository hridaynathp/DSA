/*
Doubly linked list
This program demonstrate doubly linked list whith following operations on it.
1. Insert a node at beginning of linked list
2. Insert a node at end of linked list
3. Constructing a node
4. Print linked list
5. Print linked list in reverse order
*/

#include <iostream>

using namespace std;

// Self referrential structure / node
struct node{
    int data;
    node *next;
    node *prev;
};

// Global node which points to head of linked list
node* head = NULL;

// Constructing new node
node * getNewNode(int data){

    node* newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

}

// Insert at the beginning of linked list
void insertAtBeginning(int data){
    node* newNode = getNewNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data){
    node* newNode = getNewNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Printing linked list
void display(){
    cout<<"--------------Display--------------"<<endl;
    node* temp = head;
    while(temp!=NULL){
        cout<<"["<<temp->data<<"]<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<endl<<endl;
}

// Printing linked list in reverse order
void PrintReverse(){
    cout<<"--------------Reverse--------------"<<endl;
    node* temp = head;

    //Traversing at the end of (doubly) linked list
    while(temp->next!=NULL){
        temp = temp->next;
    }

    //Printing linked list in reverse order
    while(temp!=NULL){
        cout<<"["<<temp->data<<"]<=>";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl<<endl;;
}

int main()
{
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);
    display();
    PrintReverse();
    insertAtEnd(40);
    insertAtEnd(50);
    display();
    PrintReverse();
    return 0;
}
