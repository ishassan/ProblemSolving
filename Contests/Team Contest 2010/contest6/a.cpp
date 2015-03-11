#include <map>
#include <set>
#include <math.h>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,s,m) for(int i=s;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define PI = (2.0 * acos(0.0));
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define OO ((int)1e9)

int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[] = { -1, 0, 1, 0, 1, -1, -1, 1 };

int main() {

	freopen("a.in", "rt", stdin);
	vector<string> v;
	int n;
	string x;
	set<string> s;
	while (cin >> n && n) {
		v.clear();
		int maxS = 0, mnS = 1000;
		while (n--) {
			cin >> x;
			v.push_back(x);
			mnS = min(mnS, (int) x.size());
		}
		maxS = mnS-1;
		for (int j = 0; j < mnS; j++) {
			s.clear();
			for (int i = 0; i < v.size(); i++) {
				v[i] = v[i].substr(1);
				if (s.find(v[i]) != s.end()) {
					maxS = min(maxS , j);
					break;
				}
				s.insert(v[i]);
			}
		}
		cout << maxS << endl;
	}

	return 0;
}
