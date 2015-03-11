#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

vector<pair<int,int> > ob;	//price,weight

const int s1=1001,s2=40;
int memo[s1][s2];

int n1;
int lis(int i , int weight){
	if(i>=n1)
		return 0;

	if(memo[i][weight]!=-1)
		return memo[i][weight];


	int no = lis(i+1,weight);
	int yes =0;
	int w = weight;

	if(ob[i].second<= weight){
		weight -= ob[i].second;
		yes = ob[i].first + lis(i+1,weight);
	}

	return memo[i][w] = max(no,yes);

}

void clearmem(int n1){
	fo(i,n1)
		fo(j,s2)
			memo[i][j]=-1;
}
int main() {

	int tst,n,g,we;
	cin>>tst;
	while(tst--){
		cin>>n;

		ob.erase(ob.begin(),ob.end());
		ob.resize(n);

		fo(i,n){
			cin>>ob[i].first>>ob[i].second;
		}

		cin>>g;

		n1 = n;

		int res=0;
		fo(i,g){
			cin>>we;
			clearmem(n1);
			res += lis(0,we);

		}

		cout<<res<<endl;


	}
	return 0;
}
