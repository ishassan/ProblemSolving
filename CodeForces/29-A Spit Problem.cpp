/*
 * code.cpp
 *
 *  Created on: Sep 20, 2010
 *      Author: islam
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;


pii arr[110];
int n;
int find(int x){
	fo(i,n)
			if(arr[i].first==x)
				return i;
	return -1;
}
int main(){

	scanf("%d",&n);
	fo(i,n)
		scanf("%d%d",&arr[i].first,&arr[i].second);


	bool b=0;
	fo(i,n){
		int pos = find(arr[i].first+arr[i].second);
		if(pos==-1)
			continue;
		if(arr[pos].first + arr[pos].second == arr[i].first){
			b=1;
			break;
		}
	}

	printf((b)?"YES\n":"NO\n");
	return 0;
}
