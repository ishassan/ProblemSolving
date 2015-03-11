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
using namespace std;

int n[2],k[2];
const int mod = 100000000;
int memo[102][102][2][12];
int DP(int idx1, int idx2, bool other, int cntk){
    if(idx1+idx2 == n[0]+n[1]) return 1;
    int& m = memo[idx1][idx2][other][cntk];
    if(m != -1) return m;
    m = 0;
    int aidx[2]={idx1,idx2};
    if(aidx[other]+1 <= n[other] && cntk+1 <= k[other]){
        aidx[other]++;
        m += DP(aidx[0],aidx[1], other, cntk+1);
        aidx[other]--;
    }
    if(aidx[!other]+1 <= n[!other]){
        aidx[!other]++;
        m += DP(aidx[0],aidx[1], !other, 1);
        aidx[!other]--;
    }
    m%= mod;
    return m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> n[0] >> n[1] >>k[0] >> k[1]){
        mem(memo,-1);
        cout << DP(0,0,0,0) << "\n";
    }

    return 0;
}

