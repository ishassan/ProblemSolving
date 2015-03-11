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
#define repe(i,m,n) for(int i=(m); i<=(n); i++)
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

string word;
vs stat;

int memo[152][152][152];

int DP(int idx, int sti, int stj) {
	if (idx == sz(word) && sti == sz(stat) - 1 && stj)
		return 1;

	if (idx == sz(word) || sti == sz(stat))
		return 0;

	if (stj >= sz(stat[sti]))
		return DP(idx, sti + 1, 0);

	int& m = memo[idx][sti][stj];
	if (m != -1)
		return m;

	m = 0;
	reps(i,stj,sz(stat[sti])) {
		if (stat[sti][i] == word[idx])
			m += DP(idx + 1, sti, i + 1);
	}

	if (stj)
		m += DP(idx, sti + 1, 0);
	return m;
}

int main() {

	int n;
	string str;
	while (scanf("%d", &n) && n) {
		set<string> s;

		rep(i,n) {
			cin >> str;
			s.insert(str);
		}

		getline(cin, str);
		string orig;
		while (getline(cin, str)) {
			if (str == "LAST CASE")
				break;

			stat.clear();
			sstr ss(str);
			ss >> word;
			orig = word;
			rep(i,sz(word))
				word[i] = tolower(word[i]);

			while (ss >> str) {
				if (s.find(str) == s.end())
					stat.push_back(str);
			}

			rep(i,sz(word))
				rep(j,sz(stat))
					rep(k,sz(stat[j]))
						memo[i][j][k] = -1;

			int res = DP(0, 0, 0);

			if (res)
				printf("%s can be formed in %d ways\n", orig.c_str(), res);

			else
				printf("%s is not a valid abbreviation\n", orig.c_str());

		}
	}

	return 0;
}
