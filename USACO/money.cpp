/*
 ID: fci_isl1
 LANG: C++
 TASK: money
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <cstring>
using namespace std;

typedef long long ll;
int v, n;
int money[26];
ll memo[26][10001];

ll DP(int i,int res) {
	if (res > n)
		return 0;

	ll &m = memo[i][res];

	if (res == n)
		return m = 1;

	if(i==v)
		return m =0;

	if (m != -1)
		return m;

	ll count = 0;

	for (int j = i; j < v; j++)
		count += DP(j,res + money[j]);

	return m = count;
}
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	cin>>v>>n;

	for(int i=0; i<v; i++)
		cin>>money[i];

	ll res =0;
	for (int i = 0; i < v; ++i){
		memset(memo,-1, sizeof memo);
		res += DP(i,money[i]);
	}
	cout<<res<<endl;

	return 0;
}
