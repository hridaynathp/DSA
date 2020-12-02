/*
Program to reverse a string using stack
This program implemented a class to provide feature of stack (not used STL stack)
Reverse function is function which uses this stack class and reverse a string
*/
#include <iostream>
#include <string.h>

using namespace std;

#define MAX_SIZE 100
char str[MAX_SIZE];


// Protoype os stack class, similar to stack in STL
class stack{
    private:
        char str[MAX_SIZE];
        int top;
    public:
        stack();
        void push(char c);
        void pop();
        char pick();
        bool isEmpty();

};

// Initialize top variable to -1 which indiacates stack is empty
stack::stack(){
    top = -1;
}

//  Push element to the stack at top
void stack::push(char c){
    top++;
    str[top]=c;
}

// Delete/Pop latest element of stack
void stack::pop(){
    if(top==-1){
        cout<<"Stack is Empty...Exiting..."<<endl;
    }
    top--;
}

// Fetch the top element of stack
char stack::pick(){
    return str[top];
}

// To check if stack is empty
bool stack::isEmpty(){
    if(top==-1)
        return true;
    return false;
}

// Reversing string using stack
void Reverse(char *str, int len){
    stack obj;
    for(int i=0; i<len; i++){
        obj.push(str[i]);
    }
    for(int i=0; i<len; i++){
        str[i] = obj.pick();
        obj.pop();
    }
}

int main()
{
    char str[MAX_SIZE];
    cout << "Enter a string to reverse:" << endl;
    cin>>str;

    Reverse(str, strlen(str));

    cout<<"Reverse string is: ";
    for(int i=0; i<strlen(str);i++){
        cout<<str[i];
    }
    cout<<endl;

    return 0;
}
