/*
 * Feb 4, 2011
 * ANARC05H.cpp
 * E-Mail : khaled.samy@fci-cu.edu.eg
 * TopCoder Handle : Khaled91
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
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define SZ(v)                   (int)v.size()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n)               for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)

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
const double PI = 2 * acos(0);
const double EPS = 1e-9;

int dcmp(double a, double b) {
    return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2;
}

int DI[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int DJ[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

string in;

int dp[26][9 * 25 + 10];

int clc(int idx, int sum) {
    if (idx >= SZ(in))
        return 1;

    int &ref = dp[idx][sum];
    if (ref != -1)
        return ref;

    ref = 0;
    int curS = 0;

    for (int i = idx; i < SZ(in); i++) {
        curS += in[i] - '0';
        if (curS >= sum)
            ref += clc(i + 1, curS);
    }
    return ref;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "rt", stdin);
#endif
    int id = 1;
    while (cin >> in && in != "bye") {
        CLR(dp,-1);
        printf("%d. %d\n", id++, clc(0, 0));
    }
    return 0;
}
