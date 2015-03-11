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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define sz(a) ((int)(a).size())

#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
string a,b;
int main() {
	freopen("aplusb.in","rt",stdin);
	while(cin>>a>>b)
	{
		string s="";
		int cc = 0;
		for(int j = sz(a)-1 ; j >=0 ; j--)
		{
			int k = a[j]-'a';
			int m = b[j]-'a';
			int c = k+m+cc;
			if(c>=26)
				cc=1,c%=26;
			else
				cc=0;
			char l = c+'a';
			s+=l;
		}
		reverse(s.begin(),s.end());
		cout<<s<<endl;

	}
	return 0;
}
