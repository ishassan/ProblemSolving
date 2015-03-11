#include <iostream>

using namespace std;

int main(){

	int n;
	cin>>n;
	int e=0,o=0,m;
	for (int i = 0; i < n; ++i) {
		cin>>m;
		if(m%2==0)
			e++;
		else
			o++;
	}
	cout<<e<<endl<<o<<endl;
	return 0;
}
