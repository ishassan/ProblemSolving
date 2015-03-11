/*
 *	E-Mail : khaled.samy@fci-cu.edu.eg
 *	TopCoder Handle : Khaled91
 *	Another buggy code by Khaled Samy ;)
 */
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n) 		        for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int OO = (int) 1e9;
const double PI = 2 * acos(0);
const double EPS = 1e-9;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2;
}

int DI[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int DJ[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int main() {
	int tst;
	scanf("%d", &tst);
	loop2(k,1,tst+1) {
		pii route, best;
		int size;
		scanf("%d", &size);
		vector<long long> arr(size - 1);
		route.first = 0;
		route.second = size - 1;
		long long sum = 0;
		long long max_sum = -OO;
		loop(i,size-1)
			scanf("%lld", &arr[i]);

		best.first = best.second = 0;
		loop (i,size-1) {
			long long elem = arr[i];
			if (sum < 0) {
				sum = arr[i];
				route.first = i;
				route.second = i + 1;
			} else {
				sum = sum + arr[i];
				route.second = i+1;

			}
			if (sum > max_sum) {
				max_sum = sum;
				best.first = route.first;
				best.second = route.second;

			} else if (sum == max_sum) {
				int nz = route.second - route.first;
				int oz = best.second - best.first;
				if (nz > oz)
					best = route;
			}

		}
		if (max_sum <= 0)
			printf("Route %d has no nice parts\n", k);

		else
			printf("The nicest part of route %d is between stops %d and %d\n",
					k, best.first + 1, best.second + 1);
	}
	return 0;
}
