#include<iostream>
using namespace std;

int main(){
    int begin, end, flag;
    cout << "ENTER THE STARTING AND ENDING INDEX OF THE NUMBERS :";
    cin >> begin >> end;
    while( begin > end ){
        flag = 0;
        for( int i = 2; i < end; ++i ){
            if( begin % i == 0 )
                i++;
        }
        if( flag == 0)
            cout << begin << " ";
        ++begin;
    }
    return 0;
}