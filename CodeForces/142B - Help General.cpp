#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    int n,m;
    cin >> n >> m;
    if(n > m) swap(n,m);
    if(n == 1){
        cout << m;
        return 0;
    }
    if(n==2){
        //**..**..**
        //**..**..**
        int n1 = 2*(m/4) + min(2,m%4);
        cout << 2*n1;
        return 0;
    }
    //*.*.*.*.
    //.*.*.*.*
    //*.*.*.*.
    int n1 = (m+1)/2, n2 = m/2;
    int res = n1*((n+1)/2) + n2*(n/2);
    cout << res;


    return 0;
}
