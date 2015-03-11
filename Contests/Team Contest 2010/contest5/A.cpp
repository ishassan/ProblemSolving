#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
#define MAX 150

int OO = 1000000; //just big number
int adjMax[MAX][MAX];
int flood[MAX];

int Dijkstra(int n, int src, int dest) {
	vector<int> vis(n, 0), dist(n, OO);
	dist[src] = 0; // we can reach source in no cost

	for (int t = 0; t < n; ++t) {
		int val = OO, idx = -1;
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && dist[i] < val && dist[i] <= flood[i] )
				val = dist[i], idx = i;
		}
		//cout<<idx<<endl;
		if (idx == -1)
			return OO;
		//if(idx == dest)return dist[dest];
		vis[idx] = 1; // 2) MARK as visited
		for (int i = 0; i < n; ++i){
			if (dist[i] > (val = dist[idx] + adjMax[idx][i]) && flood[i] >= val && flood[idx] >=val)
				dist[i] = val;
		}
	}
	return (dist[dest] <=flood[dest])?dist[dest]:OO;
}

int main() {
	freopen("A.in", "r", stdin);

	int N, L, S, R;
	cin >> N;
	while (N--) {
		cin >> L >> S >> R;
		for (int i = 0; i < L; i++) {
			cin >> flood[i];
			if (!flood[i])
				flood[i] = OO;
			for (int j = 0; j < L; j++) {
				cin >> adjMax[i][j];
				if (adjMax[i][j] == 0)
					adjMax[i][j] = OO;
			}
		}
		int sol = Dijkstra(L,S-1,R-1);
		if(sol >= OO)cout<<"GENE HACKMAN"<<endl;
		else cout<<sol<<endl;
	}
}
