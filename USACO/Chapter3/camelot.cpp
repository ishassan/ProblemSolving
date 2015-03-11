/*
 TASK: camelot
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
#include <valarray>
#include <iostream>
#include <cassert>
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

int ni[8]={1,-1,2,-2,-1, 1,-2, 2};
int nj[8]={2, 2,1, 1,-2,-2,-1,-1};

int ki[8]={1,0,-1, 0,1,-1,-1, 1};
int kj[8]={0,1, 0,-1,1, 1,-1,-1};
int r,c;
void bfs(int si,int sj,int di[],int dj[],valarray<int> &res)
{
	int s=si*c+sj;
	queue<int> q;
	q.push(s);
	valarray<bool> vis(SZ(res));
	vis[s]=1;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		int i=x/c;
		int j=x%c;
		fo(k,8)
		{
			int ii=i+di[k];
			int jj=j+dj[k];
			if(ii<0 || ii>=r || jj<0 || jj>=c)
				continue;
			int xx=ii*c+jj;

			if(res[x]+1<res[xx])
				res[xx]=res[x]+1;
			if(vis[xx])continue;
			vis[xx]=1;
			q.push(xx);
		}
	}
}

int main() {
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);
	cin>>r>>c;
	char j;
	int i;
	cin>>j>>i;
	j-='A';
	i--;
	valarray<int> kng(r*c),sum(r*c),kght(r*c),bestKing(r*c);
	kng=1e6;
	kng[i*c+j]=0;
	bfs(i,j,ki,kj,kng);
	bestKing=kng;
	while(cin>>j>>i)
	{
		j-='A';
		i--;
		kght=1e6;
		kght[i*c+j]=0;
		bfs(i,j,ni,nj,kght);
		sum+=kght;
		valarray<int> kngAndknght=kght+kng;
		int mn=kngAndknght.min();
		fo(i,SZ(kght))
			if(mn==kngAndknght[i])
			{
				bfs(i/c,i%c,ni,nj,kngAndknght);
				break;
			}
		kngAndknght-=kght;
		valarray<bool> better=kngAndknght<bestKing;
		bestKing[better]=kngAndknght[better];
	}
	cout<<(sum+bestKing).min()<<endl;
	return 0;
}
