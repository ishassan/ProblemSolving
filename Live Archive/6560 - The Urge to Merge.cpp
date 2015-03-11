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

int n;
int arr[3][1003];
int memo[1002][3][3][3];
int DP(int idx, int t1, int t2, int t3){
    if(idx == n) return 0;
    int& m = memo[idx][t1][t2][t3];
    if(m != -1) return m;

    m = 0;
    if(t1 == 0){
        if(idx+1 < n){
            int mn = min(t1+2,min(t2,t3));
            m = max(m, DP(idx+mn, t1+2-mn, t2-mn, t3-mn) + (arr[0][idx]*arr[0][idx+1]));
        }
        if(t2 == 0){
            int mn = min(t1+1,min(t2+1,t3));
            m = max(m , DP(idx+mn, t1+1-mn, t2+1-mn, t3-mn) + arr[0][idx]*arr[1][idx]);
        }
        int mn = min(t1+1,min(t2,t3));
        m = max(m, DP(idx+mn, t1+1-mn, t2-mn, t3-mn));
    }
    if(t2 == 0){
        if(idx+1 < n){
            int mn = min(t1,min(t2+2,t3));
            m = max(m, DP(idx+mn, t1-mn, t2+2-mn, t3-mn) + (arr[1][idx]*arr[1][idx+1]));
        }
        if(t3 == 0){
            int mn = min(t1,min(t2+1,t3+1));
            m = max(m, DP(idx+mn, t1-mn, t2+1-mn, t3+1-mn) + (arr[1][idx]*arr[2][idx]));
        }
        int mn = min(t1,min(t2+1,t3));
        m = max(m, DP(idx+mn, t1-mn, t2+1-mn, t3-mn));
    }
    if(t3 == 0){
        if(idx+1 < n){
            int mn = min(t1,min(t2,t3+2));
            m = max(m, DP(idx+mn, t1-mn, t2-mn, t3+2-mn) + (arr[2][idx]*arr[2][idx+1]));
        }

        int mn = min(t1,min(t2,t3+1));
        m = max(m, DP(idx+mn, t1-mn, t2-mn, t3+1-mn));
    }
    return m;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int tst=1;
    while(cin >> n && n){
        rep(i,3) rep(j,n) cin >> arr[i][j];
        mem(memo,-1);
        printf("Case %d: %d\n",tst++,DP(0,0,0,0));

    }



    return 0;
}
