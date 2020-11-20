/*
A Little Elephant and his friends from the Zoo of Lviv like candies very much.

There are N elephants in the Zoo. The elephant with number K (1 ≤ K ≤ N) will be happy if he receives at least AK candies. 
There are C candies in all in the Zoo.

The Zoo staff is interested in knowing whether it is possible to make all the N elephants happy by giving each elephant 
at least as many candies as he wants, that is, the Kth elephant should receive at least AK candies. 
Each candy can be given to only one elephant. Print Yes if it is possible and No otherwise.
*/
#include <iostream>
using namespace std;

int main() {
    int noOfTestCases;
    int elecand[2]={0};
    cin>>noOfTestCases;

    for(int i=0; i<noOfTestCases; i++){
        cin>>elecand[0];
        cin>>elecand[1];
        int noOfCandies = 0;
        int ReqCandies = 0;
        for(int j=0; j<elecand[0]; j++){
            cin>>noOfCandies;
            ReqCandies = ReqCandies + noOfCandies;
        }
        if(elecand[1]>=ReqCandies)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
