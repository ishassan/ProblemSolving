#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>

#define fo(i,n) for(int i=0; i<n; ++i)
#define foo(i,m,n) for(int i=m; i<n; ++i)
#define foe(i,m,n) for(int i=m; i<=n; ++i)
#define SZ(a) a.size()
#define  mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream

typedef long long ll;
using namespace std;

int arr[20000];
int res,n;

void QS(int start, int end){
	if(start==end)
		return;

	int idx =start;
	foo(i,idx+1,end){
		if(arr[i] > arr[idx])
			continue;

		int tmp = i, cnt = i-idx;
		while(cnt--){
			swap(arr[tmp], arr[tmp-1]);
			++res;
			tmp = tmp-1;
		}
		++idx;
	}

	QS(start,idx);
	QS(idx+1,n);
}
int main() {

	freopen("sir.in", "r", stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		res =0;
		scanf("%d",&n);
		fo(i,n)
			scanf("%d",arr+i);

		QS(0,n);
		printf("%d\n",res);
	}

	return 0;
}
