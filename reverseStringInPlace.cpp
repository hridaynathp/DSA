
/*
Reversing string In place

This program reverse a string In place, Following functionalities are covered:
1. Reverse string
2. Find length of string
3. Display string
*/

#include <iostream>

using namespace std;

// Find length of string
int len(char *str){
    char* c = str;
    int len = 0;
    while(*c!='\0'){
        len++;
        c++;
    }
    return len;
}

// Reversing a string in place
char * reverse(char *str){
    int length = len(str);
    int j=length-1;
    for(int i=0; i<j; i++){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return str;
}

// Display string
void display(char* c){
    char* temp = c;
    while(*temp!='\0'){
        cout<<*temp;
        temp++;
    }
    cout<<endl;
}

int main()
{
    char str[] = "Hello";
    display(str);
    reverse(str);
    display(str);

    return 0;
}
