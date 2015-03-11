#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,j,n) for(int i=j; i<n; i++)

pair<int,int> matchBox[25];
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
*/
	int n, m;
	scanf("%d%d", &n, &m);

	fo(i,m)
		scanf("%d%d",&matchBox[i].second,&matchBox[i].first);

	sort(matchBox,matchBox+m);
	reverse(matchBox,matchBox+m);

	int i=0;
	long long res=0;
	while(n>0 && i<m){
		if(n>=matchBox[i].second){
			res += matchBox[i].first * matchBox[i].second;
			n-= matchBox[i].second;
			i++;
		}
		else{
			res += matchBox[i].first * n;
			break;
		}
	}
	cout<<res;

	return 0;

}
