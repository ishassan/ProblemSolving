#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,j,n) for(int i=j; i<n; i++)

pair<int, int> centerSide[1001];
pair<float, float> startEnd[1001];

int main() {/*
 #ifndef ONLINE_JUDGE
 freopen("in.txt", "r", stdin);
 freopen("out.txt", "w", stdout);
 #endif*/

	int n, t;
	scanf("%d%d", &n, &t);
	int res = 2;
	fo(i,n)
		scanf("%d%d", &centerSide[i].first, &centerSide[i].second);

	sort(centerSide, centerSide + n);

	fo(i,n) {
		startEnd[i].first = centerSide[i].first - centerSide[i].second / 2.0;
		startEnd[i].second = startEnd[i].first + centerSide[i].second;
	}

	fo(i,n-1) {
		if (startEnd[i + 1].first - startEnd[i].second > t)
			res += 2;
		else if (startEnd[i + 1].first - startEnd[i].second == t)
			res++;
	}
	printf("%d", res);
	return 0;

}
