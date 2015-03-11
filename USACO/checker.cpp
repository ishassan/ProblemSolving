/*
 ID: fci_isl1
 LANG: C++
 TASK: checker
 */

#include <iostream>
#include <cstdio>
using namespace std;

int adjMat[15][15]={0};
int parent[15], path[15];
int N, nPath = 0, nValid = 0;

void print(int c);


void markCell(int r,int c, int bit){
	adjMat[r][c] += bit;
	int end = N - r, newr;

	for(int i=1; i<end; i++){
		newr = r+i;

		adjMat[newr][c] += bit;
		if(c+i < N)
			adjMat[newr][c+i] += bit;

		if(c-i > -1)
			adjMat[newr][c-i]+= bit;

	}
}

void DFS( int r, int c) {
	int newr = r+1;
	if (newr == N) {
		nValid++;
		if (nPath < 3)
			print(c), nPath++;
		return;
	}

	markCell(r,c,1);

	for (int i = 0; i < N; i++) {
		if (!adjMat[newr][i]) {
			parent[i] = c;
			DFS(newr, i);
		}
	}

	markCell(r,c,-1);
	parent[c] = -1;
}

int main() {
	freopen("checker.in", "r", stdin);
	freopen("checker.out", "w", stdout);

	scanf("%d",&N);
	int lim = (N % 2 == 0) ? N / 2 : (N / 2) + 1;
	int res = 0;

	for (int i = 0; i < lim || nPath < 3; i++) {
		parent[i] = -1, nValid = 0 ;
		DFS(0, i);
		if (i < lim)
			res += nValid;
	}

	res *= 2;
	if(N%2==1)
		res -= nValid;

	printf("%d\n",res);

	return 0;
}

void print(int c) {
	int size = 0;

	int val = c;
	while (val != -1) {
		path[size++] = val + 1;
		val = parent[val];
	}

	for (int i = size - 1; i > 0; i--)
		printf("%d ",path[i]);
	printf("%d\n",path[0]);
}
