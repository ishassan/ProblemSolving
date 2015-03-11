#include <iostream>
#include <string>
using namespace std;
int main() {

	int tst;
	cin >> tst;
	string str[]={"Aayush","Akash"};
	while(tst--){
		int n;
		cin >> n;
		int turn=1;
		while(n){
			turn^=1;
			if(n%2)
				--n;
			else
				n/=2;
		}
		cout << str[turn]<<endl;
	}

	return 0;
}

