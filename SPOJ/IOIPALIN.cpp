/*
 * IOIPALIN
 * Oct 29, 2012,
 * Another buggy code by Khaled Samy;)
 */
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define SZ(v)                                   (int)v.size()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n)                       for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)
#define MOD(a,b) ((((a)%(b))+(b))%(b))
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int OO = (int) 2e9;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;

int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2;
}

int DI[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int DJ[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int dp[2][5001];
char pal[5003];
int n;

int clc()
{
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j <= i; j++)
//             dp[i&1][j&1] = 0;
memset(dp,0,sizeof dp);
    
    for(int i = n-1; i >= 0; i--)
        for(int j = i; j < n; j++) {
            dp[i&1][j] = OO;
            if(pal[i] == pal[j]) dp[i&1][j] = dp[(i + 1)&1][(j - 1)];
            dp[i&1][j] = min(dp[i&1][j], min(dp[(i + 1)&1][j], dp[i&1][(j - 1)]) + 1);
        }
    return dp[0][(n - 1)];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
#endif
    scanf("%d", &n);
    scanf("%s", pal);
    printf("%d\n", clc());
    return 0;
}