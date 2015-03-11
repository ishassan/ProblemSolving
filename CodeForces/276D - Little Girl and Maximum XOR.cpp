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

ll a,b;
ll memo[70][2][2][2][2][2];
ll DP(int idx, bool isgreata1, bool islessb1, bool isgreata2, bool islessb2, bool islessdp){
    if(idx < 0) return 0;
    ll& m = memo[idx][isgreata1][islessb1][isgreata2][islessb2][islessdp];
    if(m != -1) return m;
    bool abit = (a>>idx)&1;
    bool bbit = (b>>idx)&1;
    m = 0;
    if(abit && bbit){
        //0 1
        if(isgreata1){
            m = max(m,(1LL<<idx)+DP(idx-1,isgreata1,1,isgreata2,islessb2, 1));
        }
        //1 0
        if(isgreata2 && islessdp){
            m = max(m, (1LL<<idx) + DP(idx-1,isgreata1,islessb1,isgreata2,1, islessdp));
        }
        //0 0
        if(isgreata1 && isgreata2){
            m = max(m, DP(idx-1, isgreata1,1,isgreata2,1,islessdp));
        }
        //1 1
        m = max(m, DP(idx-1,isgreata1,islessb1,isgreata2, islessb2, islessdp));
    }
    else if(!abit && !bbit){
        //0 1
        if(islessb2){
            m = max(m, (1LL<<idx) + DP(idx-1, isgreata1, islessb1, 1, islessb2, 1));
        }
        //1 0
        if(islessb1 && islessdp){
            m = max(m , (1LL<<idx) + DP(idx-1, 1,islessb1, isgreata2, islessb2, islessdp));
        }
        // 1 1
        if(islessb1 && islessb2){
            m = max(m , DP(idx-1, 1, islessb1, 1, islessb2, islessdp));
        }
        //0 0
        m = max(m, DP(idx-1, isgreata1, islessb1, isgreata2, islessb2, islessdp));
    }
    else if(!abit && bbit){
        //0 1
        m = max(m, (1LL<<idx)+DP(idx-1,isgreata1,1, 1, islessb2, 1));
        //1 0
        if(islessdp){
            m = max(m, (1LL<<idx) + DP(idx-1, 1, islessb1, isgreata2, 1, islessdp));
        }
        //0 0
        m = max(m, DP(idx-1,isgreata1,1, isgreata2, 1, islessdp));
        //1 1
        m = max(m, DP(idx-1,1,islessb1, 1, islessb2, islessdp));
    }
    else{ //abit & !bbit
        //0 0
        if(isgreata1 && isgreata2){
            m = max(m, DP(idx-1,isgreata1,islessb1, isgreata1,islessb2, islessdp));
        }
        //0 1
        if(isgreata1 && islessb2){
            m = max(m, (1LL<<idx) + DP(idx-1, isgreata1, islessb1, isgreata2, islessb2, 1));
        }
        //1 0
        if(islessdp && islessb1 && isgreata2){
            m = max(m , (1LL<<idx) + DP(idx-1, isgreata1, islessb1, isgreata2, islessb2,islessdp));
        }
        //1 1
        if(islessb1 && islessb2){
            m = max(m, DP(idx-1, isgreata1, islessb1, isgreata2, islessb2, islessdp));
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


    while(cin >> a >> b){
        mem(memo,-1);
        int lenb = log2(b)+1+1e-9;
        cout << DP(lenb-1,0,0,0,0,0) << "\n";
    }

    return 0;
}

