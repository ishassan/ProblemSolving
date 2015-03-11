//UVa 146
#include <iostream>
#include <string>
using namespace std;


int main(){

	string s,t;
	int start;
	bool found;

	while(cin>>s>>t){
		start =0;

		for(int i=0; i<s.length(); i++){
				found =0;
			for(int j=start; j<t.length(); j++){
				if(s[i]==t[j]){
					found = 1;
					start = j+1;
					break;
				}
			}

			if(!found){
				cout<<"No\n";
				break;
			}


		}

		if(found)
			cout<<"Yes\n";



	}

	return 0;
}
