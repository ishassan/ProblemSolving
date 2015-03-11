#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int v, mn = 1 << 27;
int arr[10];
int memo[1000002];

int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    cin >> v;
    repa(i, 1, 9, 1) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    if(v < mn) {printf("-1"); return 0;}
    rep(i, mn) memo[i] = 0;
    repa(rem, mn, v, 1) {
        repd(i, 9, 1, 1) {
            if(rem < arr[i]) continue;
            memo[rem] = max(memo[rem], memo[rem - arr[i]] + 1);
        }
    }
    int rem=v;
    while(rem >= mn) {
        repd(i, 9, 1, 1) {
            if(rem < arr[i]) continue;
            if(memo[rem] == memo[rem - arr[i]] + 1){
                printf("%d",i);
                rem -= arr[i];
                break;
            }
        }
    }
    return 0;
}