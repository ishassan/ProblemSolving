#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct dis_set {
	vector<int> rank;
	vector<int> par;
	dis_set(int n) {
		rank.resize(n, 0);
		par.resize(n);
		for (int i = 0; i < n; i++)
			par[i] = i;
	}
	int find(int idx) {
		if (par[idx] == idx)
			return idx;
		return par[idx] = find(par[idx]);
	}
	bool join(int x, int y) {
		int f1 = find(x);
		int f2 = find(y);
		if (f1 == f2)
			return false;
		if (rank[f1] < rank[f2])
			swap(f1, f2);
		par[f2] = f1;

		if (rank[f1] == rank[f2])
			rank[f1]++;
		return true;
	}
};

struct pr {
	double cst;
	int x, y;
	pr(double c, int i, int j) {
		x = i;
		y = j;
		cst = c;
	}
};

bool cmp(pr p1, pr p2) {
	return p1.cst < p2.cst;
}

int n;
vector<pr> edg;
map<pair<double, double> , int> m;
vector<pair<double, double> > pts;
int cnt;
int main() {
	int t;
	int st = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		edg.clear();
		m.clear();
		pts.clear();
		cnt = 0;
		if (st)
			cout << endl;
		st = 1;
		double x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			if (m.find(make_pair(x, y)) == m.end()) {
				pts.push_back(make_pair(x, y));
				m[make_pair(x, y)] = cnt++;
			}
		}

		for (int i = 0; i < (int) pts.size(); i++)
			for (int j = i + 1; j < (int) pts.size(); j++) {
				double res = hypot(pts[i].first - pts[j].first, pts[i].second
						- pts[j].second);
				pair<double, double> from, to;
				from = make_pair(pts[i].first, pts[i].second);
				to = make_pair(pts[j].first, pts[j].second);
				edg .push_back(pr(res, m[from], m[to]));
			}

		sort(edg.begin(), edg.end(), cmp);

		dis_set S(edg.size());
		double r = 0.0;
		for (int i = 0; i < (int) edg.size(); i++) {
			if (S.join(edg[i].x, edg[i].y))
				r += edg[i].cst;
		}
		printf("%0.2f\n", r);
	}
	return 0;
}
