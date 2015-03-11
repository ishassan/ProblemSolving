#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

struct tank{
	int capacity,full;
};

tank arr[110];
int main() {

	memset(arr,0,sizeof arr);

	int n,c;
	cin>>n;
	foe(i,1,n)
		cin>>arr[i].capacity;

	cin>>c;
	string str;
	int cap;

	getline(cin,str);

	fo(i,c){
		getline(cin,str);
		stringstream ss;
		ss<<str;
		str.clear();
		ss>>str;
		if(str=="Count"){
			int ret =0;
			foe(t,1,n)
				if(arr[t].full==0)
					ret++;
			cout<<ret<<endl;
		}
		else if(str=="Add"){
			ss>>cap;
			bool yes=0;
			foe(t,1,n){
				if(arr[t].capacity - arr[t].full >= cap){
					arr[t].full+= cap;
					cout<<t<<endl;
					yes=1;
					break;
				}
			}
			if(yes==0)
				cout<<-1<<endl;
		}
		else if(str=="Empty"){
			ss>>cap;
			arr[cap].full=0;
		}
		else if(str=="Check"){
			ss>>cap;
			cout<<arr[cap].capacity - arr[cap].full<<endl;
		}
	}

	return 0;
}
