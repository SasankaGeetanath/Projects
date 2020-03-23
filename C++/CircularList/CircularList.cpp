#include<iostream>
using namespace std;

class Node {
    public : 
        int data;
        Node *next;
}*head = NULL;

class CircularList {
    public:
        int isEmpty ();
        void insertAsHead ( int );
        void insertByPosition ( int, int ); 
        void insertAsTail ( int );
        void deleteAsHead ();
        void deleteByPosition ( int );
        void deleteAsTail ();
        void display ( Node* );
        void displayReverse ( Node* );
        int length (); 
        bool LinearSearch ( int );
        void Merge ( int*, int*, int*, int, int, int );
        void MergeSort ( int*, int );
};

int size = 0;

int CircularList :: isEmpty () {
    return head == NULL;
}

int CircularList :: length () {
    int length = 0;
    Node *ptr = head;
    while( ptr != NULL ) {
        length++;
        ptr = ptr -> next;
    }
    return length;
}

void CircularList :: insertAsHead ( int value ) {
    Node *item = new Node;
    item -> data = value;
    if ( isEmpty() ) 
        item -> next = item;
    else {
        Node *ptr = head;
        item -> next = head;
        while( ptr -> next != head )
            ptr = ptr -> next;
        ptr -> next =item;
    }
    size++;
    head = item;
}

void CircularList :: insertByPosition ( int value, int position ) {
    Node *item = new Node;
    item -> data = value;
    int i = 1;
    Node *ptr = head, *pre_ptr = NULL;

    while ( i != position ) {
        i++;
        pre_ptr = ptr;
        ptr = ptr -> next;
    }

    if ( position == 1 ) {
        item ->  next = head;
        head = item;
        while( ptr -> next != head )
            ptr = ptr -> next;
        ptr -> next = item;
    }

    else {
        item -> next = ptr;
        pre_ptr -> next = item;
    }
    size++;
}

void CircularList :: insertAsTail ( int value ) {
    Node *item = new Node;
    item -> data = value;
    if ( isEmpty() ) {
        item -> next = item;
        head = item;
    }
    else {
        Node *ptr = head;
        while ( ptr -> next != head ) 
            ptr = ptr -> next;
        ptr -> next = item;
        item -> next = head;
    }
    size++;
}

void CircularList :: deleteAsHead () {
    Node *ptr = head;
    head = head -> next;
    cout << "THE DELETED ELEMENT IS " << ptr -> data;
    free( ptr );
    size--;
}

void CircularList :: deleteByPosition ( int position ) {
    int i = 1;
    Node *ptr = head, *pre_ptr = NULL;
    while( i != position ) {
        i++;
        pre_ptr = ptr;
        ptr = ptr -> next;
    }
    if( position == 1 ) {
        cout << "THE DELETED ELEMENT IS " << ptr -> data << endl;
        Node *temp = ptr;
        head = head -> next;
        free( temp );
    }
    else {
        cout << "THE DELETED ELEMENT IS " << ptr -> data << endl;
        pre_ptr -> next = ptr -> next;
        free( ptr );
    }
    size--;
}

void CircularList :: deleteAsTail () {
    Node *ptr = head, *pre_ptr = NULL;
    while( ptr -> next != head ) {
        pre_ptr = ptr;
        ptr = ptr -> next;
    }
    cout << "THE DELETED ELEMENT IS " << ptr -> data;
    pre_ptr -> next = head;
    free( ptr );
    size--;
}

void CircularList :: display ( Node *ptr ) {
    while( size-- ) {
        cout << "->" << ptr -> data << "\t";
        ptr = ptr -> next;
    }
}

void CircularList :: displayReverse ( Node *ptr ) {
    int N = size;
    int i = 0;
    int *temp = new int[N];
    while( size-- ) {
        temp[i] = ptr -> data;
        ptr = ptr -> next;
        i++;
    }
    for( int i = N; i > 0; --i ) 
        cout << "->" << temp[i] << "\t";

}

bool CircularList :: LinearSearch ( int value ) {
    bool search_var = false;
    Node *ptr = head;
    while( size-- ){
        if( ptr -> data == value ){
            search_var = true;
            break;
        }
        else
            ptr = ptr -> next;
    }
    return search_var;
}

void CircularList :: Merge ( int *arr, int *left, int *right, int N, int TotalLeft, int TotalRight ){
    int i = 0 , j = 0, k = 0;
    while( i < TotalLeft && j < TotalRight ){
        if( left[i] < right[j] )
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }
    while( i < TotalLeft )
        arr[k++] = left[i++];
    while( j < TotalRight )
        arr[k++] = right[j++];    
}

void CircularList :: MergeSort ( int *arr, int N ){
    int mid;
    
    if( N < 2)
        return;

    if( N % 2 == 0)
    mid = N/2;
    else 
        mid = ( N + 1 ) / 2;
    
    int *left = (int*)malloc( mid*sizeof(int));
    int *right = (int*)malloc((N - mid)* sizeof(int));

    for( int i = 0; i < mid; i++)
        left[i] = arr[i];
    for( int i = mid; i < N; i++)
        right[ i - mid ] = arr[i];
    MergeSort( left, mid );
    MergeSort( right, N - mid );
    Merge( arr, left, right, N, mid, N - mid );
    free( left );
    free( right );
}



int main() {
    int choice, input, position;

    CircularList C;

    while( true ) {
        cout << "\n\n\t" << "SINGLY LINKED LIST" << "\t\n\n" << endl;
        cout << "1.ENTER TO INSERT AS HEAD." << endl;
        cout << "2.ENTER TO INSERT BY POSITION." << endl;
        cout << "3.ENTER TO INSERT AS TAIL." << endl;
        cout << "4.ENTER TO DELETE AS HEAD." << endl;
        cout << "5.ENTER TO DELETE BY POSITION." << endl;
        cout << "6.ENTER TO DELETE AS TAIL." << endl;
        cout << "7.ENTER TO DISPLAY ALL THE ELEMENTS." << endl;
        cout << "8.ENTER TO DISPLAY ALL THE ELEMENTS IN THE REVERSE ORDER." << endl;
        cout << "9.ENTER TO CHECK WHETHER THE LIST IS EMPTY OR NOT." << endl;
        cout << "10.ENTER TO CHECK THE SIZE OF THE LIST." << endl;
        cout << "11.ENTER TO SEARCH FOR AN ELEMENT IN THE LIST." << endl;
        cout << "12.ENTET TO SORT ALL THE ELEMENTS IN THE LIST." << endl;
        cout << "13.QUIT" << endl;
        cout << "\n\n" << "ENTER YOUR CHOICE : ";
        cin >> choice;

        switch ( choice ) {
            
            case 1 :    cout << "ENTER THE ELEMENT O BE INSERTED : ";
                        cin >> input;
                        C.insertAsHead( input );
            break;

            case 2 :    cout << "ENTER THE ELEMENT TO BE INSERTED :";
                        cin >> input;
                        cout << "ENTER THE POSITION TO BE INSERTED : ";
                        cin >> position;
                        C.insertByPosition( input, position );
            break;


            case 3 :    cout << "ENTER THE ELEMENT O BE INSERTED : ";
                        cin >> input;
                        C.insertAsTail ( input );
            break;

            case 4 :    if( C.isEmpty() )
                            cout << "\n\tTHE LIST IS EMPTY.";
                        else
                            C.deleteAsHead();
            break;

            case 5 :    if( C.isEmpty() )
                            cout << "\n\tTHE LIST IS EMPTY.";
                        else {
                            cout << "ENTER THE POSITION OF THE ELEMENT TO BE DELETED : ";
                            cin >> position;
                            C.deleteByPosition( position );
                        }
            break;


            case 6 :    if( C.isEmpty() )
                            cout << "\n\tTHE LIST IS EMPTY.";
                        else 
                            C.deleteAsTail();
            break;

            case 7 :    if( C.isEmpty() )
                            cout << "THE LIST IS EMPTY." << endl;
                        else 
                            C.display( head );
            break;
            
            case 8 :    if( C.isEmpty() )
                            cout << "THE LIST IS EMPTY." << endl;
                        else 
                            C.displayReverse( head );
            break;

            case 9 :    if( C.isEmpty() )
                            cout << "THE LIST IS EMPTY." << endl;
                        else 
                            cout << "THE LIST IS NOT EMPTY." << endl;
            break;

            case 10 :    cout << "THE SIZE OF THE LIST IS " << size << endl;
            break; 

            case 11 :    if ( C.isEmpty() ) 
                            cout << "THE LIST IS EMPTY." << endl;
                        else {
                            cout << "ENTER THE ELEMENT TO BE SEARCHED : ";
                            cin >> input;
                            if( C.LinearSearch( input ) ) 
                                cout << "THE ELEMENT IS PRESENT IN THE LIST." << endl;
                            else
                                cout << "THE ELEMENT IS NOT PRESENT IN THE LIST." << endl;
                        }
            break;

            case 12 :    if( C.isEmpty() )
                            cout << "THE LIST IS EMPTY." << endl;
                        else {
                            int N = size;
                            int *arr = new int[N];

                            for( int i = 0; i < N; ++i ) {
                                arr[i] = head -> data;
                                head = head -> next;
                            }

                            C.MergeSort( arr, N );

                            for( int i = 0; i < N; ++i )
                                cout << "->" << arr[i] << "\t";
                            
                            free( arr );
                        }
            break;

            case 13 :    exit(1);

            default :   cout << "ENTER THE VALID CHOICE!" << endl;
        }
    }
}