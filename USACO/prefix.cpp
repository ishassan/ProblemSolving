/*
 ID: fci_isl1
 LANG: C++
 TASK: prefix
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
string prim[201];
int plen[201];
int psz = 0;
string seq;
int ssz;

int memo[200010];

bool isEqual(string& str1, string& str2, int start1, int end1){
	int ind=0;
	for(int i=start1; i<end1; i++){
		if(str1[i] != str2[ind++])
			return 0;
	}
	return 1;
}

int DP(int start) {

	if (start >= ssz)
		return 0;

	if (memo[start] != -1)
		return memo[start];

	int mx = 0,tmp;
	for (int i = 0; i < psz; i++) {

		if (isEqual(seq,prim[i],start,start+plen[i]))
			if((tmp=plen[i] + DP(start + plen[i])) >mx)
					mx = tmp;
	}

	return memo[start] = mx;

}

int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);


	string tmp;
	while (cin >> tmp) {
		if (tmp == ".")
			break;
		prim[psz] = tmp;
		plen[psz++] = tmp.size();
	}
	while (cin >> tmp) {
		seq += tmp;
		ssz += tmp.size();
	}
	for (int i = 0; i < ssz; i++)
		memo[i] = -1;

	cout << DP(0) << endl;
	return 0;
}
/*
 A AB BA CA BBC
 .
 ABABACABAABC
 *
 */
