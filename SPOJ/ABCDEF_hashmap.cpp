#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<set>
#include<cmath>
#include<fstream>
#include<memory.h>
#include<map>
#include<sstream>
#include <hash_map>
#define OO 10e8
using namespace std;
using namespace __gnu_cxx;
#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define reps(i,x,n) for((i)=(x);(i)<(int)(n);(i)++)
#define repi(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define SZ(v) (int)v.size()
#define mp(x,y) make_pair(x,y)

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "rt", stdin);
#endif
    int n;
    scanf("%d", &n);
    int st[101];
    int i, j, k, ans = 0;
    rep(i,n) {
        scanf("%d", &st[i]);
    }
    hash_map<int,int> mp1;
    rep(i,n) {
        reps(j,i,n) {
            rep(k,n) {
                if(j > i)
                    mp1[st[i] * st[j] + st[k]]+=2;
                else
                    mp1[st[i] * st[j] + st[k]]++;
            }
        }
    }
    rep(i,n) {
        if(st[i] == 0) continue;
        rep(j,n) {
            reps(k,j,n) {
                if(k > j)
                    ans += mp1[st[i] * (st[j] + st[k])]*2;
                else
                    ans += mp1[st[i] * (st[j] + st[k])];
            }
        }
    }
    cout << ans << endl;
    return 0;
}

