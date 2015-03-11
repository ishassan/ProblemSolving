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
#include <list>
#include <climits>
#include <assert.h>
#include <map>

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
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

int n;
int res=0;
int vis[10];

bool isvalid(int num){
	bool v[10]={0};
	int cnt=0;
	while(num){
		++cnt;
		if(v[num%10] || vis[num%10])
			return 0;
		v[num%10]=1;
		num /=10;
	}

	return (cnt==5 || (cnt==4 && !v[0] && !vis[0]));
}

string tostr(int num){
	sstr ss;
	ss<<num;
	string str;
	ss>>str;
	while(sz(str)<5)
		str = "0" + str;
	return str;
}
void calc(int num, int idx){

	if(idx==5){
		if(num%n==0 && isvalid(num/n)){
			string str1 = tostr(num);
			string str2 = tostr(num/n);
			printf("%s / %s = %d\n",str1.c_str(),str2.c_str(),n), ++res;
		}
		return;
	}

	for (int i = 0; i < 10; ++i) {
		if(vis[i])
			continue;
		vis[i]=1;
		calc(num*10+i, idx+1);
		vis[i]=0;
	}
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	char* endl="";
	while(scanf("%d",&n) && n){
		printf("%s",endl), endl="\n";
		res=0;
		calc(0,0);
		if(res==0)
			printf("There are no solutions for %d.\n",n);
	}
	return 0;
}
