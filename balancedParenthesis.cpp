/*
    This program check if the given expression is valid one
    by checking the parenthesis entered in expression are balanced
*/

#include <iostream>
#include <stack>
#include<string.h>

using namespace std;

// Find out lenght of input string
int len(char* s){
    int count = 0;
    while(*s!='\0'){
        count++;
        s++;
    }
    return count;
}

// Check if opening brace from stack and
// closing brace from string are matched
bool arePair(char opening, char closing){
    if(opening == '{' && closing == '}')
        return true;

    if(opening == '[' && closing == ']')
        return true;

    if(opening == '(' && closing == ')')
        return true;

    return false;
}

// Logic to evaluate expression for valid expression
bool checkBalancedParenthesis(char* str){
    stack<char> s;

    for(int i=0;i<len(str);i++){

        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
            s.push(str[i]);
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')'){
            if(s.empty() || !arePair(s.top(), str[i]))
                 return false;
            else
                s.pop();
        }
    }
    return s.empty()?true:false;
}

int main()
{
    char exp[]="{()}";
    char expr[50];
    cout<<"Enter expression to check Balance Paranthesis: ";
    cin>>expr;
    if(checkBalancedParenthesis(expr)){
        cout<<"Given expression has Balanced Paranthesis"<<endl;
        }
        else{
            cout<<"Given expression is not Balanced Paranthesis"<<endl;
        }
    return 0;
}
