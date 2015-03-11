//UVa 484
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
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define	foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

const int MAX = 10000000;
const int half = 5000000;
int vis[MAX] ={0};

int main(){

	int n;
	vi v;
	while(cin>>n){
		if(vis[n+half]==0)
			v.push_back(n);

		vis[n+half]++;

	}

	fo(i,v.size())
		cout<<v[i]<<" "<<vis[v[i]+half]<<endl;

	return 0;
}
