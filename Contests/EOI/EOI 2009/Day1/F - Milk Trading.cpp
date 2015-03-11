#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

typedef long long ll;

using namespace std;

pii pos[1000002];
pii neg[1000002];

int npos=0,nneg=0;

int main(){
	
    int n,x;
	cin>>n;
	fo(i,n){
		cin>>x;
		if(x<0)
			neg[nneg++] = mp(x,i);
		else if(x>0)
			pos[npos++] = mp(x,i);
	}
	

	int ipos=0,ineg=0;
	ll res =0;

	while(ipos < npos && ineg < nneg){
		
		if( abs( neg[ineg].first ) >= pos[ipos].first ){
			res += abs(pos[ipos].second - neg[ineg].second)* pos[ipos].first;
            neg[ineg].first += pos[ipos].first;
			pos[ipos].first=0;
			ipos++;
		}
		
		else{
            res += abs(pos[ipos].second - neg[ineg].second) * (-1*neg[ineg].first);
			pos[ipos].first += neg[ineg].first;
			neg[ineg].first=0;
			ineg++;
		}
		
	}
	
	cout<<res<<endl; 

    //system("pause");
	return 0;
}
