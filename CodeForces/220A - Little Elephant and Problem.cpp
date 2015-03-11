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
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define find(v,x) (find(all((v)),(x))-(v).begin())
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;

int arr[100002],sor[100002];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif

    ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n){
        rep(i,n) cin >> arr[i], sor[i]=arr[i];
        sort(sor,sor+n);
        int cnt=0,idx1=-1,idx2=-1;
        rep(i,n)
        {
            if(sor[i] != arr[i]){
                if(cnt == 0)
                    idx1 = i;
                else idx2=i;
                ++cnt;
            }
        }
        if(cnt == 0){
            cout <<"YES\n";
            continue;
        }
        if(cnt != 2){
            cout <<"NO\n";
            continue;
        }
        if(sor[idx1] == arr[idx2] && sor[idx2] == arr[idx1])
            cout <<"YES\n";
        else cout <<"NO\n";
    }
}
