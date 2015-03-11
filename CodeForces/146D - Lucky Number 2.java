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

void app(string& base, string str, int n){
	while(n--)
		base += str;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
	freopen("out.out", "wt", stdout);
#endif

	int n4,n7,n47,n74;
	while(scanf("%d%d%d%d",&n4,&n7,&n47,&n74) != -1){
		if(abs(n47 - n74) > 1){
			printf("-1\n");
			continue;
		}

		int mx = max(n74, n47);
		if(n4 < mx || n7 < mx){
			printf("-1\n");
			continue;
		}

		n4 -= mx, n7 -=mx;

		string str;
		if(n47 > n74)
			app(str,"47",n47);


		else if (n47 < n74)
			app(str,"74",n74);

		else{
			if(n4 == 0 && n7 == 0){
				printf("-1\n");
				continue;
			}
			if(n4 == 0){
				app(str,"74",n74);;
				str += "7";
				--n7;
			}
			else{
				app(str,"47",n47);
				str += "4";
				n4--;
			}
		}
		int idx=0;
		while(str[idx]!='4')++idx;
		str.insert(idx,n4,'4');
		idx = sz(str)-1;
		while(str[idx]!='7')--idx;
		str.insert(idx,n7,'7');
		printf("%s\n",str.c_str());
	}
	return 0;
}
