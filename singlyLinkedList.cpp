/*

Linked List: Singly Linked list

Operations:
Insert at Beginning
Insert at End
Insert at perticular position
Display Linked list

*/
#include <iostream>

using namespace std;

// Self Referential structure / node of linked list
struct node{
    int data;
    struct node* next;
};

// Global variable head, to point at beginning of Linked list
struct node *head = NULL;

// To display the Linked list
void display(struct node* head){
    node *temp = new node();
    temp = head;

    while(temp != NULL){
        cout<<"["<<temp->data<<"]->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// To insert node at End of Linked List
void insertNodeAtEnd(int data){
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;

    if(head != NULL){
        node* temp1 = head;
        while(temp1->next!=NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    else{
        head = temp;
    }
}

// To insert node at Begining of linked list
void insertNodeAtBegining(int data){
    node* temp = new node();

    temp->data = data;

    if(head != NULL){
        temp->next = head;
        head = temp;
    }else{
        head =temp;
        temp->next = NULL;
    }
}

// To insert node in Linked List
// Arguments:
// data - data to be inserted
// pos - position at which it should be inserted
void insertNodeAtPosition(int data, int pos){
    node* temp1 = new node();
    temp1->data = data;

    if(pos==1){
        // If insert is at beggining or if head is null
        temp1->next = head;
        head = temp1;
        return;
    }

    node* temp2 = head;

    for(int i=0; i<pos-2; i++){
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

int main()
{
    int noOfNodes = 0;
    int data = 0;
    cout<<"How many numbers you want to enter?:";
    cin>>noOfNodes;

    for(int i=0; i<noOfNodes; i++){
        cout<<"Enter the number:"<<endl;
        cin>>data;
        insertNodeAtEnd(data);
//        insertNodeAtBegining(data);
    }

    // We are considering existing linked list [ 1 2 3 ] passed below
    insertNodeAtPosition(44,1); // 44 1 2 3
    insertNodeAtPosition(67,2); // 44 67 1 2 3
    insertNodeAtPosition(55,4); // 44 67 1 55 2 3
    insertNodeAtPosition(33,7); // 44 67 1 55 2 3 33

    display(head);

    return 0;
}
