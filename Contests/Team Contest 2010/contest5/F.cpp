#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <sstream>
#include <map>
#include <memory.h>
using namespace std;

int n;
char g[12][12];
bool vis[12];
map<string,int> m;

int calc(int cnt, int e){
	return (128 * ((e%2)?-1:1))/(1<<(cnt-1));
}

int res =0;
int dist;
void DFS(int src, int cnt, int e){
	if(src==dist){

		res += calc(cnt,e);
		return;
	}

	vis[src]=1;
	for (int i = 0; i < n; ++i) {
		if(vis[i] ||g[src][i]=='N')
			continue;

		if(g[src][i]=='E')
			DFS(i,cnt+1,e+1);
		else
			DFS(i,cnt+1,e);
	}
	vis[src]=0;
}
int main(){

	freopen("F.in","r",stdin);

	int tst;
	cin>>tst;
	for (int t = 1; t <= tst; ++t) {

		cin>>n;
		memset(g,0,sizeof g);
		memset(vis,0,sizeof vis);
		m.clear();

		string name;
		for (int i = 0; i < n; ++i) {
			cin>>name;
			m[name] = i;
			for (int j = 0; j < n; ++j) {
				char c;
				cin>>c;
				g[i][j]=c;
			}
		}

		cin>>name;
		int src = m[name];
		cout<<"Data Set #"<<t<<endl;

		for (int i = 0; i < n; ++i) {
			if(i==src){
				if(i) cout<<" ";
				cout<<0;

				continue;
			}

			res=0,dist=i;
			DFS(src,0,0);

			if(i) cout<<" ";
			cout<<res;

		}


		cout<<endl;
	}
	return 0;
}
