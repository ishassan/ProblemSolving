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

const int MAXN = (1 << 17); // elsize power of 2
typedef long long bt; // BIT Type
struct BITRANGE{
    bt C[MAXN], M[MAXN];
    BITRANGE(int n){
        n = int(log2(n)) + 1;
        n = 1<<n;
        memset(C, 0, n*sizeof C[0]);
        memset(M, 0, n*sizeof M[0]);
    }
    bt query(int idx) {
        int tmp = idx++;
        bt m = 0, c = 0;
        while (idx) {
            m += M[idx - 1];
            c += C[idx - 1];
            idx -= idx & (-idx);
        }
        return m * tmp + c;
    }
    void updateRange(int st, int ed, bt val) {
        bt t = -((st-1)*val);
        update (st, val, t);
        update (ed+1, -val, -t+val*(ed-st+1));
    }
private:
    void update(int idx, bt m, bt c) {
        idx++;
        while (idx <= MAXN) {
            M[idx - 1] += m;
            C[idx - 1] += c;
            idx += idx & (-idx);
        }
    }
} bit(0);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int tst;
    cin >> tst;
    while(tst--){
        int n,c;
        cin >> n >> c;
        bit = BITRANGE(n);
        while(c--){
            int t,st,en,v;
            cin >> t >> st >> en;
            if(t==0){
                cin >> v;
                bit.updateRange(st,en,v);
            }
            else
                cout <<(bit.query(en) - bit.query(st-1)) << "\n";\
        }
    }

    return 0;
}
