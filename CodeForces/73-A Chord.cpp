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
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

string arr[] =
		{ "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H" };

int find(string s) {
	rep(i,12)
		if (arr[i] == s)
			return i;
}
bool valid(string a, string b, string c) {
	int aa = find(a), bb = find(b), cc = find(c);
	if ((bb - aa + 12) % 12 == 4 && (cc - bb + 12) % 12 == 3) {
		cout << "major\n";
		return 1;
	}
	if ((bb - aa + 12) % 12 == 3 && (cc - bb + 12) % 12 == 4) {
		cout << "minor\n";
		return 1;
	}
	return 0;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
	freopen("out.out", "wt", stdout);
#endif

	string a, b, c;
	while (cin >> a >> b >> c) {
		vs v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		sort(all(v));
		do {

			if (valid(v[0], v[1], v[2]))
				goto end;
		} while (next_permutation(all(v)));

		cout << "strange\n";
		end: ;
	}

	return 0;

}
