#include <bits/stdc++.h>

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

int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    string res;
    int n,m;
    cin >> n >> m;
    if(m > 2*n+2 || n>m+1){
        cout << -1;
        return 0;
    }
    while(m && n){
        if(m > n){
            res += "110";
            m -= 2;
            n-=1;
        }
        else if(m == n){
            res += "10";
            m--,n--;
        }
        else{
            res += "01";
            --n,--m;
        }
    }
    if(n > 0) res += "0", --n;
    if(m > 0) res += "1", --m;
    if(m > 0) res += "1", --m;
    if(n || m) cout << -1;
    else cout << res;
    
    return 0;
}