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

int n,M,k;

pii memo[10003][2];
pii DP(int rem, bool turn){
    if(rem == 0) return mp(0,0);
    pii&m = memo[rem][turn];
    if(m != mp(-1,-1)) return m;
    int arr[2];
    arr[turn]=-1<<27, arr[!turn]=1<<27;
    m = mp(arr[0],arr[1]);
    bool b=0;
    repa(i,1,k,1){
        if(b) break;
        pii p;
        int arr[2]={0,0};
        if(i > rem){
            arr[turn] = M;
            p = mp(arr[0],arr[1]);
            b=1;
        }
        else{
            arr[turn] = i;
            p = DP(rem-i,!turn);
            p.first += arr[0];
            p.second += arr[1];
        }
        if(turn==0){
            if(m.first < p.first || (m.first == p.first && m.second > p.second))
                m = p;
        }
        if(turn==1){
            if(m.second < p.second || (m.second == p.second && m.first > p.first))
                m = p;
        }
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

    cin >> n >> M >> k;
    mem(memo,-1);
    pii p = DP(n,0);
    cout << p.first << " " << p.second << "\n";

    return 0;
}

