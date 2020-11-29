/*
Array Implementation of Stack
This program demonstrate stact data structure using array
Following functionalities are covered in this program:
1. Push
2. Pop
3. Top
4. Check if stack is empty
5. Display stack
*/

#include <iostream>
#define MAX_SIZE 100

using namespace std;

int top = -1;
int stackArray[MAX_SIZE];

// To push new element on stack
void push(int data){
    if(top>=MAX_SIZE)
        return;
    top++;
    stackArray[top] = data;

}

// To remove last element on stack
void pop(){
    if(top<0)
        return;
    top--;

}

// To get last element on stack
int pick(){
    if(top<0)
        return 0;
    return stackArray[top];
}

// Display stack
void display(){
    for(int i = 0; i<=top; i++){
        cout<<stackArray[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    push(2);display();
    push(4);display();
    push(6);display();
    pop();display();
    cout<<pick()<<endl;

    return 0;
}
