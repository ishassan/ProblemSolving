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
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
typedef unsigned short ushort;

using namespace std;

int memo[2][502][502];
int n;
int del[502];
deque<ll> res;
void floyd(){
    repa(k,1,n,1){
        ll sum = 0;
        rep(i,n){
            rep(j,n){
                int ii = del[i], jj = del[j], kk = del[k-1];
                memo[k&1][ii][jj] = min(memo[(k+1)&1][ii][jj], memo[(k+1)&1][ii][kk] + memo[(k+1)&1][kk][jj]);
                if(i < k && j < k)
                sum += memo[k&1][ii][jj];
            }
        }
        res.push_front(sum);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> n){
        res.clear();
        rep(i,n) rep(j,n) cin >> memo[0][i][j];
        repd(i,n-1,0,1) cin >> del[i], --del[i];

        floyd();
        rep(i,sz(res)) cout << res[i] << " \n"[i+1==sz(res)];
    }
    return 0;
}
