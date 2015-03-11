/*
 ID:tito_911
 PROG:rect1
 LANG:C++
 */
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define siz size()
#define loop(i,m) for(int i=0;i<m;i++)
#define lop(i,k,m) for(int i=k;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair

typedef long long ll;
#define oo ((int)1e9)

#define MAX 100000

struct rect {
	int l, b, r, t, c;
	bool isE() {
		return (r < l || t < b);
	}

	int get_W() {
		return r - l + 1;
	}

	int get_H() {
		return t - b + 1;
	}

	int get_Area() {
		return (get_W() * get_H());
	}

};

int R, C, N;

int col[2501];

int cut(rect &a, rect &b, rect res[4]) {
	int sz = 0;

	rect r1 = { a.l, a.b, min(a.r, b.l - 1), a.t, a.c };
	if (!r1.isE())
		res[sz++] = r1;

	rect r2 = { max(a.l, b.l), max(a.b, b.t + 1), min(a.r, b.r), a.t, a.c };
	if (!r2.isE())
		res[sz++] = r2;

	rect r3 = { max(a.l, b.r + 1), a.b, a.r, a.t, a.c };
	if (!r3.isE())
		res[sz++] = r3;

	rect r4 = { max(a.l, b.l), a.b, min(a.r, b.r), min(a.t, b.b - 1), a.c };
	if (!r4.isE())
		res[sz++] = r4;

	return sz;

}

int main() {

	freopen("rect1.in", "rt", stdin);
	freopen("rect1.out", "wt", stdout);

	scanf("%d%d%d", &R, &C, &N);

	rect r = { 0, 0, R - 1, C - 1, 1 };
	vector<rect> cur, nxt;
	cur.push_back(r);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d%d%d", &r.l, &r.b, &r.r, &r.t, &r.c);
		r.r--, r.t--;
		rect arr[4];
		nxt.clear();
		for (int j = 0; j < cur.size(); ++j) {
			int cnt = cut(cur[j], r, arr);

			for (int k = 0; k < cnt; ++k) {
				nxt.push_back(arr[k]);
			}

		}
		nxt.push_back(r);
		cur = nxt;
	}
	for (int i = 0; i < cur.size(); ++i) {
		col[cur[i].c] += cur[i].get_Area();
	}

	for (int i = 0; i < 2501; ++i) {
		if (col[i])
			printf("%d %d\n", i, col[i]);
	}

	return 0;
}
