/*
 ID: tito_911
 PROG: contact
 LANG: C++
 */

#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include<cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define loop(i,m) for(int i=0;i<m;i++)
#define lop(i,k,m) for(int i=k;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair

typedef long long ll;
#define oo ((int)2e9)

#define MAX 100000
using namespace std;

char arr[200010];
int ga[4096][13];
int main() {
	freopen("contact.in", "rt", stdin);
	freopen("contact.out", "wt", stdout);
	int m, M, res;
	scanf("%d %d %d", &m, &M, &res);
	char *s = arr;
	while (scanf("%s", s) != EOF)
		s += strlen(s);
	int len = s - arr;
	map<int, set<pair<int, int> > > resarr;
	for (int i = 0; i < len; ++i) {
		int x = 0;
		for (int j = 0; j < M && i + j < len; ++j) {
			x <<= 1;
			x |= arr[i + j] == '1';
			ga[x][j + 1]++;
		}
	}
	for (int l = m; l <= M; ++l) {
		for (int x = 0; x < (1 << l); ++x) {
			if (ga[x][l])
				resarr[ga[x][l]].insert(make_pair(l, x));
		}
	}
	map<int, set<pair<int, int> > >::reverse_iterator it;
	for (it = resarr.rbegin(); it != resarr.rend() && res--; it++) {
		printf("%d", it->first);
		set<pair<int, int> >::iterator is;
		int cnt = 0;
		for (is = it->second.begin(); is != it->second.end(); ++is) {
			if (cnt++ % 6 == 0)
				s = "\n";
			else
				s = " ";
			printf(s);
			for (int ay = is->first - 1; ay >= 0; --ay) {
				printf("%d", ((is->second) >> ay) & 1);
			}
		}
		printf("\n");
	}
	return 0;
}
