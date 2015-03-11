/*
 TASK: msquare
 LANG: C++
 ID: fci_isl1
 */

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
#define foi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define SZ(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

char moves[3][9]={"87654321","41236785","17245368"};


struct state{
	int cur,par;
	char move;
};

void print(vector<state>&q,int c)
{
	if(q[c].move)
	{
		print(q,q[c].par);
		printf("%c",q[c].move);
	}
}

bitset<1<<24> vis;
void BFS(){
	vector<state> q;
	int st=0,gl=0;
	for(int i=0;i<8;i++)
	{
		int x;
		cin>>x;
		x--;
		gl|=x<<(3*i);
		st|=i<<(3*i);
	}
	if(st==gl)
	{
		cout<<0<<endl<<endl;
		return;
	}
	state s={st,-1,0};
	q.push_back(s);

	vis[st]=1;
	//fo(cur,SZ(q))
	int l=1,cur=0;
	while(cur<SZ(q))
	{
		int sz=SZ(q);
		for(;cur<sz;cur++)
		{
		state s=q[cur];
		fo(i,3)
		{
			int nxt=0;
			fo(j,8)
			{
				int x=moves[i][j]-'1';
				int y=(s.cur>>(3*x))&7;
				nxt|=y<<(3*j);
			}
			if(vis[nxt])continue;
			vis[nxt]=1;
			state ns={nxt,cur,'A'+i};
			q.push_back(ns);
			if(nxt==gl)
				goto bara;
		}
		}
		l++;
	}
	bara:
	printf("%d\n",l);
	print(q,SZ(q)-1);

	printf("\n");
}
int main() {

	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
	 BFS();


	return 0;
}
