#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;
#define vis(s) v[s.x][s.y][s.c][s.d]
struct state
{
	int x,y,c,d;
	bool operator == (const state &a )const
		{
			return x==a.x&&y==a.y&&c==a.c;
		}
};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

string g[26];
pair<int, int> src, dist;
int v[27][27][6][5];
int n, m;

bool valid(state s)
{
	if(s.x<0 || s.x>= n || s.y<0 || s.y>=m || g[s.x][s.y]=='#')
		return 0;
	return true;
}

int bfs()
{


	memset(v,0,sizeof v);
	queue<state> q;
	state s={src.first,src.second,0,3};
	state gl={dist.first,dist.second,0,3};
	if(s == gl)return 0;
	q.push(s);
	vis(s)=1;
	int lvl = 0;
	while(!q.empty())
	{
		int siz=q.size();
		for (int i = 0; i < siz; ++i)
		{
			state cur=q.front();
			q.pop();
			state temp=cur;
			temp.x+=dx[temp.d];
			temp.y+=dy[temp.d];
			temp.c++;
			temp.c%=5;
			if(valid(temp)&&!vis(temp)){
				vis(temp)=1;
				if(temp==gl)return lvl+1;
				q.push(temp);
			}
			for (int d = 1; d < 4; d+=2)
			{
				temp=cur;
				temp.d+=d;
				temp.d%=4;
				if(!vis(temp))
				{
					vis(temp)=1;
					q.push(temp);
				}
			}
		}
		lvl++;
	}
	return -1;
}
int main()
{
	int t = 1;
	bool sta = 0;
	while (cin >> n >> m && (n || m))
	{
		if(sta)
			cout<<endl;
		sta = 1;
		for (int i = 0; i < n; i++)
			cin >> g[i];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (g[i][j] == 'S')
				{
					src.first = i;
					src.second = j;
				}
				if (g[i][j] == 'T')
				{
					dist.first = i;
					dist.second = j;
				}
			}
		}
		int ret = bfs();
		cout<<"Case #"<<t++<<endl;
		if(ret==-1)
			cout<<"destination not reachable\n";
		else
			cout<<"minimum time = "<<ret<<" sec\n";
	}
	return 0;
}
