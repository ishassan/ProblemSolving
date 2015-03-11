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

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
	freopen("out.out", "wt", stdout);
#endif

	string a, b;
	while (cin >> a >> b) {
		int res = 0;
		int f4 = 0, f7 = 0;
		rep(i,sz(a)) {
			if (a[i] == b[i])
				continue;
			if (a[i] == '4') {
				if(f4 >= sz(a)){
					a[i]='7';
					++res;
					continue;
				}
				int nf4 = f4;
				bool in=0;
				reps(j,f4,sz(a)) {
					if (a[j] == '7' && b[j] == '4') {
						swap(a[i],a[j]);
						++res;
						in=1;
						break;
					}
					++nf4;
				}
				f4 = nf4;
				if(!in){
					++res;
					f4 = sz(a);
				}
			}

			else if(a[i]=='7'){
				if(f7 >= sz(a)){
					a[i]='4';
					++res;
					continue;
				}
				int nf7 = f7;
				bool in=0;
				reps(j,f7,sz(a)) {
					if (a[j] == '4' && b[j] == '7') {
						swap(a[i],a[j]);
						++res;
						in=1;
						break;
					}
					++nf7;
				}
				f7 = nf7;
				if(!in){
					++res;
					f7=sz(a);
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
