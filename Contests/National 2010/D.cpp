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
#define OO 1e9
typedef long long ll;
using namespace std;

int main() {

	freopen("acm.in", "r", stdin);
	int T, n, p, c, x, y, z;
	cin >> T;
	vector<vector<int> > res;
	vector<int> t(3);
	while (T--) {
		cin >> p >> c >> x >> y >> z;
		int i, j, k;
		res.clear();
		int mI = OO, mJ = OO, mK = OO;
		for (i = 1; i <= p; i++) {
			if (y == z)
				j = 1;
			else
				j = (c - (i * (x - z)) - (z * p)) / (y - z);
			k = p - i - j;
			//	cout<<i<<" "<<j<<" "<<k<<endl;
			if (j < 1 || k < 1)
				continue;
			if ((i + j + k) == p && (i * x + j * y + z * k) == c) {
				if (i < mI || (i == mI && j < mJ) || ((i == mI && j == mJ && k
						< mK))) {
					mI = i, mJ = j, mK = k;
				}
			}
		}
		if (mI == OO) {
			cout << "Crap!" << endl;
		} else {
			cout << mI << " " << mJ << " " << mK << endl;
		}
	}
	return 0;
}
