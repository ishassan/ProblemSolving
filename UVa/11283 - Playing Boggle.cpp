#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

string graph[4];

const int dirr[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int dirc[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
bool vis[4][4]={0};

int score(int n) {
	if (n == 3 || n == 4)
		return 1;

	if (n == 5)
		return 2;

	if (n == 6)
		return 3;

	if (n == 7)
		return 5;

	else
		return 11;
}
bool DFS(string str, int i, int j) {

	str.erase(0, 1);
	string aaa = str;

	if (str.size() == 0)
		return 1;

	vis[i][j]=1;

	fo(d,8) {
		int newr = i + dirr[d];
		int newc = j + dirc[d];

		if (newr == 4 || newc == 4 || newr < 0 || newc < 0)
			continue;

		if(vis[newr][newc])
			continue;

		char tmp = graph[newr][newc];
		tmp = str[0];

		if (graph[newr][newc] == str[0] && DFS(str, newr, newc))
			return 1;

	}
	vis[i][j]=0;
	return 0;
}
int main() {


	int tst;
	string word;
	cin >> tst;
	fo(t,tst) {

		fo(i,4)
			cin >> graph[i];

		int m;
		cin >> m;

		int res = 0;
		fo(i,m) {
			cin >> word;

			fo(i,4)
				fo(j,4)
					if (graph[i][j] == word[0] && DFS(word, i, j)) {
						res += score(word.size());
						memset(vis,0,sizeof vis);
						goto end;
					}

			end: ;
		}
		printf("Score for Boggle game #%d: %d\n", t + 1, res);


	}

	return 0;
}
