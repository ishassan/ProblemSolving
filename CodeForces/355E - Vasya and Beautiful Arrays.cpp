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

int n,k;
int arr[300002];
int cntless[2000003];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);
    int mx = 0;
    cin >> n >> k;
    rep(i,n) {cin >> arr[i]; mx = max(mx, arr[i]);};
    sort(arr,arr+n);
    int idx = 0;
    repa(i,0,2000001,1){
        if(idx==n || i <= arr[idx]) cntless[i]=idx;
        else {
            while(idx < n && i>arr[idx])++idx;
            cntless[i]=idx;
        }
    }
    repd(g,mx,1,1){
        int sum = 0;
        int idx=0;
        for(ll i=1; i*g <= mx; i++){
            sum += cntless[i*g+k+1]-max(idx,cntless[i*g]);
            idx = cntless[i*g+k+1];
        }
        if(sum == n) {cout << g; return 0;}
    }
    return 0;
}
