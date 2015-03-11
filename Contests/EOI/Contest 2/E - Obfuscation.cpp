#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

string dic[10011], str;
vector<string> word;
int n;

int memo[1011];
bool isEqual(string a, string b, int idx) {
	if(b[idx] != a[0])
		return 0;

	int end = idx + a.size();
	if (end > b.size())
		return 0;

	if(b[end-1] != a[a.size()-1])
		return 0;

	int pos;
	foo(i,idx,end) {
		if ((pos = a.find(b[i])) == a.npos)
			return 0;
		a[pos] = '1'; //clear
	}
	return 1;
}
int DP(int idx) {
	if (idx == str.size())
		return 1;

	int& m = memo[idx];
	if (m != -1)
		return m;

	m = 0;
	fo(i,n) {
		if (isEqual(dic[i], str, idx))
			m += DP(idx + dic[i].length());
	}

	return m;
}

void build(int idx) {
	if (idx == (int) str.size())
		return;

	int ans = DP(idx);

	fo(i,n) {
		if (isEqual(dic[i], str, idx)) {
			int c = DP(idx + dic[i].length());
			if (ans == c) {
				word.push_back(dic[i]);
				build(idx + dic[i].length());
			}
		}
	}

}
int main() {

	while (cin >> str >> n) {
		fo(i,n)
			cin >> dic[i];

		memset(memo, -1, sizeof memo);
		word.clear();
		int res = DP(0);
		if (res < 1) {
			cout << "impossible\n";
			continue;
		}
		if (res > 1) {
			cout << "ambiguous\n";
			continue;
		}

		build(0);
		int sz = word.size() - 1;
		fo(i,sz)
			cout << word[i] << " ";
		cout << word[sz] << endl;
	}
	return 0;
}
