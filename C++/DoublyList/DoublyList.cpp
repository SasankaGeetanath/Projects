#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *next;
        Node *prev;
}*head = NULL;

class DoublyList {
    public:
        int isEmpty();
        void insertAsHead( int );
        void insertByPosition( int, int ); 
        void insertAsRear( int );
        void deleteAsHead();
        void deleteByPosition( int );
        void deleteAsRear();
        void display( Node* );
        void displayReverse( Node* );
        int size();
        int LinearSearch( Node*, int );

};

int DoublyList::isEmpty() {
    return head == NULL;
}

void DoublyList::insertAsHead( int value ) {
    Node *item = new Node;
    item -> data = value;
    item -> prev = NULL;
    if ( isEmpty() ) 
        item -> next = NULL;
    else 
        item -> next = head;
    head = item;
}

void DoublyList::insertByPosition( int value, int position ) {
    Node *item = new Node;
    item -> data = value;
    item -> next = NULL;
    item -> prev = NULL;
    int i = 1;
    Node *ptr = head;

    while( i != position ) {
        i++;
        ptr = ptr -> next;
    }

    if( position == 1 ) {
        item ->  next = head;
        item -> prev = NULL;
        head = item;
    }

    else {
        item -> next = ptr;
        item -> prev = ptr -> prev -> next;
    }
}

void DoublyList::insertAsRear( int value ) {
    Node *item = new Node;
    item -> data = value;
    item -> prev = NULL;
    if ( isEmpty() ) {
        item -> next = NULL;
        head = item;
    }
    else {
        Node *ptr = head;
        while ( ptr -> next != NULL ) 
            ptr = ptr -> next;
        ptr -> next = item;
        item -> next = NULL;
    }
}

void DoublyList::deleteAsHead() {
    Node *ptr = head;
    head = head -> next;
    head -> prev = NULL;
    cout << "THE DELETED ELEMENT IS " << ptr -> data;
    free( ptr );
}

void DoublyList::deleteByPosition( int pos ) {
    int i = 1;
    Node *ptr = head;
    while( i != pos ) {
        i++;
        ptr = ptr -> next;
    }
    cout << "THE DELETED ELEMENT IS " << ptr -> data;
    ptr -> prev -> next = ptr -> next;
    free( ptr );
}

void DoublyList::deleteAsRear() {
    Node *ptr = head;
    while( ptr -> next != NULL ) 
        ptr = ptr -> next;
    cout << "THE DELETED ELEMENT IS " << ptr -> data;
    ptr -> prev -> next = NULL;
    free( ptr );
}

void DoublyList::display( Node *ptr ) {
    if( ptr != NULL ){
        cout << "->" << ptr -> data << "\t";
        display( ptr -> next );
    }
}

void DoublyList::displayReverse( Node *ptr ) {
    if( ptr != NULL ){
        displayReverse( ptr -> next );
        cout << "->" << ptr -> data << "\t";
    }
}

int DoublyList::size() {
    Node *ptr = head;
    int count = 0;
    while( ptr != NULL ){
        count++;
        ptr = ptr -> next;
    }
    return count;
}

int DoublyList::LinearSearch( Node *ptr, int value ) {
    if( ptr != NULL ) {
        if( ptr -> data == value ) 
            return 1;
        else 
            return LinearSearch( ptr -> next , value );
    }
}

int main() {
    int input, choice, position;

    DoublyList D;

    while(1) {
        cout << "\n\n\t" << "DOUBLY LINKED LIST" << "\t\n\n" << endl;
        cout << "1.ENTER TO INSERT AS HEAD." << endl;
        cout << "2.ENTER TO INSERT BY POSITION." << endl;
        cout << "3.ENTER TO INSERT AS REAR." << endl;
        cout << "4.ENTER TO DELETE AS HEAD." << endl;
        cout << "5.ENTER TO DELETE BY POSITION." << endl;
        cout << "6.ENTER TO DELETE AS REAR." << endl;
        cout << "7.ENTER TO DISPLAY ALL THE ELEMENTS IN THE LIST." << endl;
        cout << "8.ENTER TO DISPLAY ALL THE ELEMENTS IN REVERSE ORDER." << endl;
        cout << "9.ENTER TO CHECK WHETHER THE LIST IS EMTPY OR NOT." << endl;
        cout << "10.ENTER TO FIND THE SIZE OF THE LINKED LIST." << endl;
        cout << "11.ENTER TO SEARCH FOR AN ELEMENT IN THE LINKED LIST." << endl; 
        cout << "12.QUIT." << endl;
        cout << "\n\nENTER YOUR CHOICE : ";
        cin >> choice;

        switch( choice ) {

            case 1 :    cout << "ENTER THE ELEMENT TO BE INSERTED : ";
                        cin >> input;
                        D.insertAsHead( input );
            break;

            case 2 :    cout << "ENTER THE ELEMENT TO BE INSERTED : ";
                        cin >> input;
                        cout << "ENTER THE POSITION OF THE ELEMENT TO BE INSERTED : ";
                        cin >> position;
                        D.insertByPosition( input, position );
            break;

            case 3 :    cout << "ENTER THE ELEMENT TO BE INSERTED : ";
                        cin >> input;
                        D.insertAsRear( input );
            break;

            case 4 :    if( D.isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else
                            D.deleteAsHead();
            break;

            case 5 :    if( D.isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else {
                            cout << "ENTER THE POSITION OF THE ELEMENT TO BE DELETED : ";
                            cin >> position;
                            D.deleteByPosition( position );
                        }
            break;

            case 6 :    if( D.isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else 
                            D.deleteAsRear();
            break;

            case 7 :    if( D.isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else 
                            D.display( head );
            break;

             case 8 :    if( D.isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else 
                            D.displayReverse( head );
            break;

            case 9 :    if( D.isEmpty() )
                            cout << "THE LIST IS EMPTY.";
                        else 
                            cout << "THE LIST IS NOT EMPTY.";
            break;

            case 10 :    if( D.isEmpty() )
                            cout << "THE LIST IS EMPTY." << endl;
                        else 
                            cout << "THE SIZE OF THE LIKEDLIST IS " << D.size() << endl;
            break;
            
            case 11 :    if( D.isEmpty() )
                            cout << "THE LIST IS EMPTY." << endl;
                        else {
                            cout << "ENTER THE ELEMENT TO BE SEARCHED FOR : ";
                            cin >> input;
                            if( D.LinearSearch( head, input ) ) 
                                cout << "THE ELEMENT IS PRESENT IN THE LINKEDLIST." << endl;
                            else 
                                cout << "THE ELEMENT IS NOT PRESENT IN THE LINKEDLIST." << endl;
                        }
            break;
            
            case 12 :   exit(1);

            default :  cout << "ENTER THE VALID CHOICE!";
        }
    }
    return 0;
}
