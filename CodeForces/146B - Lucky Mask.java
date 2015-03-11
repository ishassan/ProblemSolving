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

//int len=0;
//int luck[500000];
//void gen(){
//	queue<int> q;
//	q.push(0);
//	while(q.size()){
//		int n =q.front();
//		q.pop();
//		if(n > 100000) continue;
//		q.push(n*10+4);
//		q.push(n*10+7);
//		luck[len++] = n*10+4;
//		luck[len++] = n*10+7;
//	}
//}

int get(int n){
	int pw=1;
	int res=0;
	while(n){
		int dig = n%10;
		n/=10;
		if(dig!= 4 && dig!=7) continue;
		res+=pw*dig;
		pw*=10;
	}
	return res;
}
int main() {

//	freopen("in.in","rt",stdin);
//	freopen("out.out","wt",stdout);

	int a,b;
	while(scanf("%d%d",&a,&b) != -1){
		repe(c,a+1,1<<27){
			if(get(c)==b){
				printf("%d\n",c);
				break;
			}
		}
	}



	return 0;
}
