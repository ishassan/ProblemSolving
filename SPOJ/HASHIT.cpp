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
#define pdi pair<double,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define mit map<int, string>::iterator
typedef long long ll;
using namespace std;

map<string, int> stoi;
map<int, string> itos;
int hash(string& key) {
	int h = 0;
	rep(i,sz(key))
		h += key[i] * (i + 1);
	h *= 19;

	return h % 101;

}

bool add(string key) {
	if(stoi.find(key)!=stoi.end())
		return 0;

	int h = hash(key);
	rep(j,20) {
		int pos = (h + j * j + 23 * j)%101;
		if (itos.find(pos) == itos.end()) {
			itos[pos] = key;
			stoi[key] = pos;
			return 1;
		}
	}
	return 0;
}

bool del(string key) {
	if (stoi.find(key) == stoi.end())
		return 0;
	int h = stoi[key];
	stoi.erase(key);
	itos.erase(h);
	return 1;
}
int main() {

	int tst;
	scanf("%d", &tst);
	while (tst--) {
		stoi.clear();
		itos.clear();
		int n;
		scanf("%d", &n);
		rep(i,n) {
			string str;
			cin >> str;
			if (str[0] == 'A')
				add(str.substr(str.find(":", 0) + 1));
			else
				del(str.substr(str.find(":", 0) + 1));
		}

		printf("%d\n", itos.size());
		repi(it,itos)
		cout<<it->first<<":"<<it->second<<endl;

	}
	return 0;
}
