#include<iostream>
using namespace std;

class Operations {

    protected :  
        int N, top, *stack;

    public :
        Operations( int value ) {
            top = -1;
            N = value;
            stack = new int[N];
        }

        bool isEmpty() {
            return top == -1;
        } 

        bool isFull() {
            return top == N - 1;
        }

        void push( int value ) {
            top++;
            stack[top] = value;
        }

        void pop() {
            cout << "THE DELETED ELEMENT IS " << stack[top] << endl;
            top--;
        } 
        void display() {
            for( int i = 0; i <= top; ++i )
                cout << "->" << stack[i] << "\t";
        }
};

int main() { 
    int N, choice, input;

    cout << "ENTER THE MAXIMUM SIZE OF THE ARRAY : ";
    cin >> N;
    
    Operations Stack(N);

    while(1) {
        cout << "\n\n\t" << "STACK" << "\t\n\n" << endl;
        cout << "1.ENTER TO PUSH INTO THE STACK." << endl;
        cout << "2.ENTER TO DELETE FROM THE STACK." << endl;
        cout << "3.ENTER TO DISPLAY ALL THE ELEMENTS IN THE STACK." << endl;
        cout << "4.ENTER TO CHECK WHETHER THE STACK IS EMPTY OR NOT." << endl;
        cout << "5.ENTER TO CHECK WHETHER THE STACK IS FULL OR NOT." << endl;
        cout << "6.EXIT." << endl;
        cout << "\n\nENTER THE VALUE : ";
        cin >> choice;

        switch( choice ) {
            case 1 :    if( Stack.isFull() )
                            cout << "STACK OVERFLOW!" << endl;
                        else {
                            cout << "ENTER THE ELEMENT TO BE INSERTED : ";
                            cin >> input;
                            Stack.push(input);
                        }
            break;

            case 2 :    if( Stack.isEmpty() )
                            cout << "STACK UNDERFLOW!" << endl;
                        else 
                            Stack.pop();
            break;

            case 3 :    if( Stack.isEmpty() )
                            cout << "STACK UNDERFLOW!" << endl;
                        else 
                            Stack.display();
            break;

            case 4 :    if( Stack.isEmpty() )
                            cout << "THE STACK IS EMPTY." << endl;
                        else 
                            cout << "THE STACK IS NOT EMPTY." << endl;
            break;

            case 5 :    if( Stack.isFull() )
                            cout << "THE STACK IS FULL." << endl;
                        else 
                            cout << "THE STACK IS NOT FULL." << endl;
            break;

            case 6 :    exit(1);

            default :   cout << "ENTER VALID CHOICE!" << endl;
        }
    }
    

    return 0;
}