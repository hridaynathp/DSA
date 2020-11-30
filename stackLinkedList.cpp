/*
Linked list implementation of stack
Following operation can be performed
1. Push at the top of stack, time complexity O(1)
2. Pop/remove last element from stack, time complexity O(1)
3. Pick last pushed element from stack, time complexity O(1)
4. Check if stack is empty, time complexity O(1)
5. Display the stack, time complexity O(n)
*/

#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

// Global pointer head pointing to head of linked list
node* top = NULL;

// Pushing on stack at the beginning
void push(int data){
    node* newNode = new node();
    newNode->data = data;
    if(top == NULL){
        top = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->next = top;
    top = newNode;
}

// To delete last element in stack
void pop(){
    if(top == NULL){
        cout<<"emtpy stack, exiting..."<<endl;
    }
    node* temp = top;
    top = temp->next;
    free(temp);
}

// To pick last pushed element from stack
int pick(){
    return top->data;
}

// To display the stack
void display(){
    node* temp = top;
    while(temp!=NULL){
        cout<<"["<<temp->data<<"] ";
        temp = temp->next;
    }
    cout<<endl;
}

// To check whether stack is empty or not
bool isEmpty(){
    if(top == NULL)
        return true;
    return false;
}

int main()
{
    cout << "Hello world!" << endl;
    cout << "Is stack empty?: "<<isEmpty()<<endl;
    push(10);display();
    push(20);display();
    push(30);display();
    push(40);display();
    pop();display();
    cout<<"Picked "<<pick()<<" from stack"<<endl;
    cout << "Is stack empty?: "<<isEmpty()<<endl;
    return 0;
}
