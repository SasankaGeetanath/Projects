#include<iostream>
using namespace std;

int main(){
	int input, sum = 0;
	cout << "ENTER THE NUMBER :";
	cin >> input;
	int temp = input;
	while( temp/10 != 0 ){
		temp = temp/10;
		temp = temp*temp*temp;
		sum = temp;
	}
	if( sum == input )
		cout << "ARMSTRONG NUMBER.";
	else
		cout << "NOT ARMSTRONG NUMBER.";
	return 0;
}
