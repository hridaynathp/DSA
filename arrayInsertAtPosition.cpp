#include <iostream>
using namespace std;

/*
* inserting an element in an array at specific position
*/

// Display array
void display(int* arr, int size){
    cout<<"Your array is : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

// Logic to insert an element elmnt at position pos
void insertAnElement(int arr[], int size, int elmnt, int pos) {

    size++;
    int i=0;
    for(i=size; i>=pos; i--){
        arr[i]=arr[i-1];
    }
    arr[i]=elmnt;
    display(arr,size); //Your array is : 1	42	2	3	4	5
}

void deleteAnElement(int arr[], int size, int pos){
    for(int i=pos-1; i<size; i++){
        arr[i]=arr[i+1];
    }
    display(arr, size-1);
}


int main() {
	// your code goes here.

	int size = 5;
	int arr[10]={0};

	// Taking input for array from user
	for(int i=0; i<size; i++){
	    cin>>arr[i];
	}

	//Display original array
	display(arr,5); //Your array is : 1	2	3	4	5

	// Adding element 42 to array
	insertAnElement(arr,size,42,2);

	deleteAnElement(arr, size+1, 2);

	return 0;
}
