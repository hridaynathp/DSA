/*
This program demonstates Reversing a Linked list by using Stack Explicitly
Here Stack is user defined and not STL's stack

This two classes are defined as follows
1.Linked list
    Linked List class is implemented with few basic operations
2.Stack
    Stack class with its basic operations
*/

#include <iostream>

using namespace std;

// Node of linked list
struct node{
    int data;
    node* next;
};

// Class Linked list with various operations
class LinkedList{
    private:
        node* head;
    public:
        LinkedList();
        node* getNode(int);
        node* getHead();
        void setHead(node*);
        void insertAtBeginning(int);
        void insertAtEnd(int);
        void insertAtPos(int, int);
        void display();

        void deleteAtEnd();
        void deleteAtBeg();
        void deleteAtPos(int);
};

// Get head of Linked list
node* LinkedList::getHead(){
    return head;
}

// Set / Modify head of Linked list
void LinkedList::setHead(node* head){
    this->head = head;
}

// Delete node at specific position of Linked list
void LinkedList::deleteAtPos(int pos){
    node* temp1 = head;
    if(pos == 1){
        head = head->next;
        free(temp1);
        return;
    }
    node* temp2 = head;
    for(int i=0; i<pos-2; i++){
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

// Delete first node of Linked list
void LinkedList::deleteAtBeg(){
    node* temp = head;
    head = head->next;
    free(temp);
}

// Delete end node of Linked list
void LinkedList::deleteAtEnd(){
    if(head ==NULL){
        cout<<"Linked list is empty, Exiting..."<<endl;
    }
    node* temp = head;
    node* prev;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Constructor of Linked list
LinkedList::LinkedList(){
    head = NULL;
}

// Get Node of Linked list
node* LinkedList::getNode(int data){
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;

    return temp;
}

// Insert at specific position of Linked list
void LinkedList::insertAtPos(int data, int pos){
    node* temp1 = new node();
    temp1->data = data;

    if(pos == 1){
        head = temp1;
        temp1->next = NULL;
        return;
    }
    node* temp2 = head;
    for(int i = 0; i<pos-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

// Insert at the end of Linked list
void LinkedList::insertAtEnd(int data){
    node* temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;

    if(head ==NULL){
        head = temp1;
        return;
    }
    node* temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

// Insert at Beginning of Linked list
void LinkedList::insertAtBeginning(int data){
    node* temp = new node();
    temp->data = data;

    if(head == NULL){
        head= temp;
        temp->next = NULL;
        return;
    }
    temp->next = head;
    head = temp;
}

// Display Linked list
void LinkedList::display(){
    node* temp = head;
    while(temp!=NULL){
        cout<<"["<<temp->data<<"]->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl<<endl;
}

// Node of stack (For linked list implementation of stack)
struct stackNode{
    node* data;
    stackNode* next;
};

// Class stack which holds address of node of a linked list
class stak{
    private:
        stackNode* top;
        node* data;

    public:
        stak();
        void push(node *);
        void pop();
        node* pick();
        bool isEmpty();
        void display();
        stackNode* getTop();
};

// Constructor of stack
stak::stak(){
    top = NULL;
    data = NULL;
}

// Get pointer which points to top of stack
stackNode* stak::getTop(){
    return top;
}

// Display stack
void stak::display(){

    if(top == NULL){
        cout<<"stack is empty!!"<<endl;
        return;
    }
    stackNode* temp = top;
    while(temp!=NULL){
        cout<<(temp->data)->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Check if stack is empty
bool stak::isEmpty(){
    if(top==NULL)
        return true;
    return false;
}

// Get top element of stack
node* stak::pick(){
    return top->data;
}

// Pop/Delete top element of stack
void stak::pop(){

    if(top == NULL){
        cout<<"Empty stack!,Exiting..."<<endl;
        return;
    }
    stackNode* temp = top;
    top = temp->next;
    free(temp);
}

// Push node to stack
void stak::push(node* data){
    stackNode* temp = new stackNode();
    temp->data = data;
    if(top == NULL){
        top = temp;
        temp->next = NULL;
        return;
    }
    temp->next = top;
    top = temp;
}

// Reverse Linked list using explicit stack
void reverseLinkedList(LinkedList* myList){

    cout<<"Reverse Linked List:"<<endl;
    node* temp = myList->getHead();

    stak* stkNd = new stak();
    while(temp!=NULL){
        stkNd->push(temp);
        temp = temp->next;
    }

    temp = stkNd->pick();
    myList->setHead(temp);

    stkNd->pop();

    while(!stkNd->isEmpty()){
        temp->next = stkNd->pick();
        stkNd->pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    LinkedList *first = new LinkedList();

    first->insertAtBeginning(4);
    first->insertAtBeginning(2);

    first->insertAtEnd(6);
    first->insertAtPos(8,3);

    first->deleteAtPos(3);

    first->display();
    reverseLinkedList(first);
    first->display();

    return 0;
}
