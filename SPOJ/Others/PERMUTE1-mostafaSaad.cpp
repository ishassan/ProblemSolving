/*
 * 64_PERMUT1.cpp
 * Another buggy code by mostafa_saad
 *
 *  Created on: May 23, 2009
 */


#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include <cstring>
using namespace std;

#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define repi(i, j, n)       for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n)       for(int i=(j);i>=(int)(n);--i)
#define repa(v)             repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)           repi(i, 0, sz(v))
#define lp(i, cnt)          repi(i, 0, cnt)
#define lpi(i, s, cnt)      repi(i, s, cnt)
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
#define pb                  push_back
#define MP                  make_pair

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef long long         ll;
typedef long double       ld;

const int OO = (int)1e8;    //Small -> WRONG, Large -> OVERFLOW

const double PI  = acos(-1.0);
const double EPS = (1e-7);

int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;   }

int n, k;


int cntBits(int msk) {
    int c = 0;
    while(msk)
        c += (msk&1), msk = msk >>1;
    return c;
}

int memo[1<<12][100];

int cnt(int msk, int inversions) {
    if(inversions < 0)  return 0;

    int &ret = memo[msk][inversions];

    if(ret != -1)   return ret;

    if( msk == ((1<<n)-1) && inversions == 0)   return ret = 1;
    if( msk == ((1<<n)-1) ) return ret = 0;

    ret = 0;
    for (int i = 0; i < n; ++i) if( ((msk>>i)&1) == 0)
        ret += cnt( msk|1<<i, inversions - cntBits(msk>>i) );

    return ret;
}

int main()
{/*
#ifndef ONLINE_JUDGE
    freopen("c.in", "rt", stdin);
#endif
*/

    int cases;
    cin>>cases;

    while(cases--) {
        cin>>n>>k;

        clr(memo, -1);

        cout<<cnt(0, k)<<"\n";
    }


    return 0;
}
