
#include <iostream>
#include <string.h>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)


bool find(char c[],int sz,char t){

	fo(i,sz)
		if(c[i]==t)
			return 1;
	return 0;
}
int main() {

	char c[30];
	char index[10000][21];
	int ind=0,indc=0;

	while(cin>>index[ind]){
		if(!strcmp(index[ind],"#")){
			ind--;
			break;
		}

		ind++;
	}

	fo(j,21)
		fo(i,ind){
			if(index[i][j]=='\0')
				continue;

			if(!find(c,indc,index[i][j]))
				c[indc++]=index[i][j];

		}


	fo(i,indc)
		cout<<c[i];
	cout<<endl;
	return 0;
}
