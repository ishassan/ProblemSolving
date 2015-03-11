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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

int main() {
	string frm[5] = { "8", "w8", "gr8", "4", "b4" };
	string to[5] = { "ate", "wait", "great", "for", "before" };
	int tst;
	scanf("%d", &tst);
	string str;
	getline(cin, str);
	while (tst--) {
		getline(cin, str);
		rep(i,5)
			if (str == frm[i]) {
				cout << to[i] << endl;
				goto end;
			}
		rep(i,5) {
			int pos;
			if (sz(str) <= sz(frm[i]))
				continue;
			if (str.substr(0, sz(frm[i]) + 1) == frm[i] + " ")
				str.replace(0, sz(frm[i]) + 1, to[i] + " ");
			if (str.substr(sz(str) - sz(frm[i]) - 1, sz(frm[i]) + 1) == " "
					+ frm[i])
				str.replace(sz(str) - sz(frm[i]) - 1, sz(frm[i]) + 1, " "
						+ to[i]);

			string midf = " "+frm[i]+" ",midt=" "+to[i]+" ";
			while ((pos = str.find(midf)) != -1)
				str.replace(pos, sz(midf), midt);
		}
		cout << str << endl;
		end:;
	}
	return 0;
}
