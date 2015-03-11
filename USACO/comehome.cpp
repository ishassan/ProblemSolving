/*
 ID: fci_isl1
 LANG: C++
 TASK: comehome
 */
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
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef stringstream sstr;

int OO = 1000000;
const int MAX = 260;
int adjMax[MAX][MAX];

void floydWarshal() {
	for (int k = 0; k < MAX; ++k) {
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			if (adjMax[i][j] > adjMax[i][k] + adjMax[k][j])
				adjMax[i][j] = adjMax[i][k] + adjMax[k][j];
			}
		}
	}
}

int main(){
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);

	int n;
	scanf("%d",&n);
	char a,b;
	int c;

	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			adjMax[i][j] = OO;

	for (int i = 0; i < n; ++i) {
		scanf("%c",&a);
		scanf("%c %c %d",&a,&b,&c);

		if(a==b)
			continue;

		if(c < adjMax[a][b])
			adjMax[a][b] = adjMax[b][a] = c;
	}

	floydWarshal();

	int mn = OO;
	char res;
	for (char i = 'A'; i < 'Z'; ++i) {
		if(mn > adjMax[i]['Z'])
			mn = adjMax[i]['Z'], res = i;
	}

	cout<<res<<" "<<mn<<endl;
	return 0;
}
