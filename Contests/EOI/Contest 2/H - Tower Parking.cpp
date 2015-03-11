#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
using namespace std;

int grid[52][52];
int ptr[52];
int h, w;
pair<int, int> find(int num) {
	fo(i,h)
		fo(j,w)
			if (grid[i][j] == num)
				return mp(i,j);
	return mp(-1,-1);
}

int main() {

	while (cin >> h >> w) {
		int n = 0;
		memset(ptr,0,sizeof ptr);
		fo(i,h)
			fo(j,w) {
				cin >> grid[i][j];
				n = max(n, grid[i][j]);
			}
		int res =0;
		foe(i,1,n){
			pair<int,int> p = find(i);
			res += p.first*20;
			int t1 = abs(ptr[p.first]-p.second);
			int t2 = w - t1;
			res += min(t1,t2)*5;
			ptr[p.first] = p.second;

		}
		cout<<res<<endl;
	}
	return 0;
}
