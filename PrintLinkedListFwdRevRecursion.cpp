#include <iostream>
/*
Print Linked list in Forward and Reverse order using recursion
Functionalities
Insert node at end of Linked list
Display function
Print linked list in Forward and Reverse order
*/
using namespace std;

// Self referential structure / node
struct node{
    int data;
    node* next;
};

// Global variable head use to point linked list
node* head = NULL;

// Insert a node at the end of linked list
void insertAtEnd(int data){
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return;
    }

    node* temp1 = head;
    while(temp1->next!= NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

// Display linked list
void display(){
    node* temp = head;
    while(temp!=NULL){
        cout<<"["<<temp->data<<"]->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// Recursive function to display linked list in forward and reverse orcer
void FwdReversePrint(node* p){

    // Exit Condition
    if(p == NULL){
        cout<<endl;
        return;

    }

    cout<<"["<<p->data<<"] "; // Prints in forward order
    FwdReversePrint(p->next); // Recursive call
    cout<<"["<<p->data<<"] "; // Prints in reverse order
}

int main()
{
    for(int i=0; i<5; i++){
        insertAtEnd(i+1);
    }

//    display();
    FwdReversePrint(head);
    return 0;
}
