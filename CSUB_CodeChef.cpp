/*
*** Find substring which starts and ends with 1
*** Given a string S consisting of only 1s and 0s, find the number of substrings which start and end both in 1.
*** In this problem, a substring is defined as a sequence of continuous characters Si, Si+1, ..., Sj where 1 ≤ i ≤ j ≤ N.
*** Input:
    2
    4
    1111
    5
    10001
    
*** Output:
    10
    3
*/


#include <iostream>
using namespace std;

int main()
{
    long noOfTests = 0;
    long noOfDigits;
    long count;
    string input;
    cin>>noOfTests;
    for(int i=0; i<noOfTests; i++){
        count = 0;
        cin>>noOfDigits;
        cin>>input;
        for(char c: input)
            if(c=='1')
                count++;
        cout<<(count*(count+1))/2<<endl;
    }
    return 0;
}
