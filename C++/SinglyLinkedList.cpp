#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head = NULL;

typedef struct Node* node;

int isEmpty(){
    return head == NULL;
}
void insertAsHead ( int value ) {
    if( isEmpty() ) {
        node newnode = (node)malloc(sizeof(node));
        newnode -> data = value;
        newnode -> next = NULL;
        head = newnode;
    }
    else {
        node newnode = (node)malloc(sizeof(node));
        newnode -> data = value;
        newnode -> next = head;
        head = newnode;
    }
}

void insertAsRear ( int value ) {
    if( isEmpty() ) {
        node newnode = (node)malloc(sizeof(node));
        newnode -> data = value;
        newnode -> next = NULL;
        head = newnode;
    }
    else {
        node newnode = (node)malloc(sizeof(node));
        newnode -> data = value;
        newnode -> next = NULL;
        node ptr = head;
        while( ptr -> next != NULL )
            ptr = ptr -> next;
        ptr -> next = newnode;
    }
}

void deleteAsHead () {
    node ptr = head;
    cout << "THE DELETED ELEMENT IS " << ptr;
    free( ptr );
    head = head -> next;
}

void deleteAsRear() {
    node ptr = head;
    while( ptr -> next != NULL )
        ptr = ptr -> next;
    cout << "THE DELETED ELEMENT IS " << ptr;
    free( ptr );
}

void display() {
    node ptr = head;
    while( ptr != NULL ) {
        cout << "->" << ptr -> data << "\t";
        ptr = ptr -> next;
    }
}

int main() {
    int input, choice;
    while(1) {
        cout << "\n\n\t" << "SINGLY LINKED LIST" << "\t\n\n" << endl;
        cout << "1.ENTER TO INSERT AS HEAD." << endl;
        cout << "2.ENTER TO INSERT AS REAR." << endl;
        cout << "3.ENTER TO DELETE AS HEAD." << endl;
        cout << "4.ENTER TO DELETE AS REAR." << endl;
        cout << "5.ENTER TO DISPLAY ALL THE ELEMENTS IN THE LIST." << endl;
        cout << "6.ENTER TO CHECK WHETHER THE LIST IS EMTPY OR NOT." << endl;
        cout << "\n\nENTER YOUR CHOICE : ";
        cin >> choice;

        switch( choice ) {

            case 1 :    cout << "ENTER THE ELEMENT TO BE INSERTED : ";
                        cin >> input;
                        insertAsHead( input );
            break;

            case 2 :    cout << "ENTER THE ELEMENT TO BE INSERTED : ";
                        cin >> input;
                        insertAsRear( input );
            break;

            case 3 :    if( isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else
                            deleteAsHead();
            break;

            case 4 :    if( isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else 
                            deleteAsRear();
            break;

            case 5 :    if( isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else 
                            display();
            break;

            case 6 :    if( isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else 
                            cout << "THE LIST IS NOT EMPTY.";
            break;

            case 7 : exit(1);

            default :  cout << "ENTER THE VALI CHOICE!";
        }
    }
    return 0;
}