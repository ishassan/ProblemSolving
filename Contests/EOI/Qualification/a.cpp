#include <iostream>

using namespace std;

int main(){
	string str;
	char c;
	cin>>str>>c;
	int ret =0;
	for (int i = 0; i < str.size(); ++i) {
		if(str[i]==c)
			ret++;
	}

	cout<<ret<<endl;
	return 0;
}
