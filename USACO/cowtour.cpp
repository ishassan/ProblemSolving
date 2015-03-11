/*
 ID: fci_isl1
 LANG: C++
 TASK: cowtour
 */
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;

pair<double, double> points[160];
string adjMax[160];
double dist[160][160];
const double OO = 10000000;

void floydWarshal(int n) {
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

double longest(int p,int n,int vis) {
	double maxi = 0;
	for (int i = 0; i < n; ++i) {
		if (p == i || fabs(dist[i][p]-OO) <1e-6||i==vis)
			continue;
		maxi = max(maxi, dist[p][i]);
	}

	return maxi;
}
int main() {
	freopen("cowtour.in","rt",stdin);
	freopen("cowtour.out","wt",stdout);

	int n;
	scanf("%d", &n);
	int x, y;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		points[i].first = x;
		points[i].second = y;
	}

	fo(i,n)
		cin >> adjMax[i];

	if(n==2){
		dist[0][1] = hypot(points[0].first - points[1].first , points[0].second - points[1].second);
		printf("%.6lf\n",dist[0][1]);
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			dist[i][j] = OO;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j)
		if (adjMax[i][j]=='1')
			dist[i][j] = dist[j][i] = hypot(points[i].first
					- points[j].first, points[i].second - points[j].second);
	}

	floydWarshal(n);

	double mini = OO, d=0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {

			if (dist[i][j] >= OO || fabs(dist[i][j] - OO) < 1e-6) {
				dist[i][j] = dist[j][i] = hypot(points[i].first
						- points[j].first, points[i].second - points[j].second);

				d = longest(i,n,j) + dist[i][j] + longest(j,n,i);
				mini = min(mini,d);
				dist[i][j] = dist[j][i] = OO;
			}
		}
	}

	double maxi=0;
	fo(i,n)
		maxi = max(maxi,longest(i,n,-1));

	maxi = max(mini,maxi);
	printf("%.6lf\n",maxi);

	return 0;
}
