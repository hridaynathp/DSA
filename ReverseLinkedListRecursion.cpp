/*
Reverse a linked list using Recursion
Functionalities covered:
1. Reverse Linked list using Recursion
2. Insert node at the end of Linked list
3. display linked list
*/
#include <iostream>

using namespace std;

// Self Referential structure / node
struct node{
    int data;
    node* next;
};

node * head = NULL;

// Insert node at the end of Linked list
void InsertAtEnd(int data){

    node * temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;

    if(head == NULL){
        head = temp1;
        return;
    }

    node *temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

void display(){
    node * temp = head;
    while(temp!=NULL){
        cout<<"["<<temp->data<<"]->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//Reverse Linked list using recursion
void reverseLinkedList(node* p){

    if(p->next==NULL){
        head = p;
        return;
    }
    reverseLinkedList(p->next);
    node *q = p->next;
    q->next = p;
    p->next = NULL;
}

int main()
{
    // Creating linked list
    // by adding node at end
    InsertAtEnd(1);
    InsertAtEnd(2);
    InsertAtEnd(3);
    InsertAtEnd(4);
    InsertAtEnd(5);

    display(); //  1 2 3 4 5

    reverseLinkedLi st(head);

    display(); // 5 4 3 2 1

    return 0;
}
