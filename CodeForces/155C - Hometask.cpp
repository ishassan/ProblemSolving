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
#define fnd(v,x) (find(all((v)),(x))!=(v).end())

typedef long long ll;
using namespace std;

char cstr[100003];
string str;
bool seq[300][300];
int main() {

	scanf("%s",cstr);
	str = cstr;
	int k;
	scanf("%d",&k);
	rep(i,k){
		scanf("%s",cstr);
		seq[cstr[0]][cstr[1]]=1;
		seq[cstr[1]][cstr[0]]=1;
	}

	int ret=0;
	rep(i,sz(str)-1){
		if(!seq[str[i]][str[i+1]]) continue;
		int fst=1,sec=1;
		int j = i-1;
		while(j >= 0 && (str[j]==str[i]||str[j]==str[i+1])){
			if(str[j]==str[i])++fst;
			if(str[j]==str[i+1]) ++sec;
			--j;
		}

		j=i+2;
		while(j < sz(str) && (str[j]==str[i]||str[j]==str[i+1])){
			if(str[j]==str[i])++fst;
			if(str[j]==str[i+1]) ++sec;
			++j;
		}


		ret += min(fst,sec);
		i = j-1;
	}
	printf("%d",ret);
	return 0;
}
