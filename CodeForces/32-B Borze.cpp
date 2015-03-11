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

#define SZ(a) (int)a.size()
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define foi(it,s) for(typeof(s.begin()) it=s.begin(); it!=s.end(); it++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;



int main(){

	string str;
	cin>>str;
	int idx=0;
	string res;
	while(idx<str.size()){
		if(str[idx]=='.')
			res+="0",idx++;
		else if(str[idx]=='-'){
			if(str[idx+1]=='.')
				res+="1";
			else
				res+="2";
			idx+=2;
		}
	}

	cout<<res;
	return 0;
}
