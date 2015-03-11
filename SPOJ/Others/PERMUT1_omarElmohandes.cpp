/*
ID:keko_873
PROG:64_PERMUT1
LANG:C++
*/
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <memory.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define REP(i,k,m) for(int i=k;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define oo ((int)1e9)
int arr[13][99];
int main()
{
	int t , N , K;
	arr[0][0] = 1;
	for(int i = 1 ; i <= 12 ; i ++)
	{
		int k = 0;
		for(int j = 0 ; j <= 98 ; j++ )
		{
			if(!j)arr[i][j] = 1;
			else arr[i][j] = arr[i][j-1] + arr[i-1][j];
			if(i <= j)arr[i][j] -= arr[i-1][k++];
		}
	}
	scanf("%d" , &t);
	while(t--)
	{
		scanf("%d%d" , &N , &K);
		cout << max(0 , arr[N][K]) << endl;
	}
	return 0;
}
