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
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
#define itr(A,B) typeof(B) A = B
typedef long long ll;
using namespace std;

pll arr[102];
ll fact[102];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif


    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    rep(i,n){
       cin >> arr[i].second >> arr[i].first;
    }
    int t;
    cin >> t;
    rep(i,t){
        cin >> fact[i];
    }
    fact[t] = 1LL<<62;

    sort(arr,arr+n);

    ll res=0,sum=0;
    int idx=0;
    rep(i,n){
        if(sum + arr[i].second < fact[idx]){
            res += arr[i].second*arr[i].first*(idx+1);
            sum += arr[i].second;
        }
        else{
            res += (fact[idx]-sum)*arr[i].first*(idx+1);
            arr[i].second -= (fact[idx]-sum);
            sum += (fact[idx]-sum);
            ++idx,--i;
        }
    }
    cout << res;
}





