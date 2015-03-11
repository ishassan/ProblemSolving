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

int in[42][42][42];

void floyd(int n, int idx) {
	fo(k,n)
		fo(i,n)
			fo(j,n)
				if (in[i][j][idx] > in[i][k][idx] + in[k][j][idx])
					in[i][j][idx] = in[i][k][idx] + in[k][j][idx];
}

int main() {

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int n, m, k;
	int s, d;
	cin >> n >> m >> k;

	fo(i,n){
		fo(j,n)
			fill(in[i][j], in[i][j] + 42, 1e9);
		memset(in[i][i],0,sizeof in[i][i]);
	}
	int var;
	fo(mm,m){
		cin >> s >> d;
		fo(i,k){
			cin >> var;
			in[s-1][d-1][i]=min(var,in[s-1][d-1][i]);
	}}

	fo(i,k)
		floyd(n, i);

	fo(i,n)
		fo(j,n) {
			printf("%d %d", i+1, j+1);
			if (in[i][j][0] >= 1e9) {
				printf(" forget it\n");
				continue;
			}

			fo(kk,k)
				printf(" %d", in[i][j][kk]);
			printf("\n");
		}

	return 0;
}
