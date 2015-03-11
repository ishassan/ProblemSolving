#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(aukito it = (stl).begin(); (it)!=stl.end(); ++(it))
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

// char memo[1 << 30];
// char DP(int msk)
// {
//     if(msk == 0) return 0;
//     char &m = memo[msk];
//     if(m != -1) return m;
//     set<char> s;
//     repa(i, 1, 29, 1) {
//         if(!((msk >> (i-1)) & 1)) continue; //-1 to map bit 1 to bit 0
//         int newmsk = msk;
//         repa(k, i, 29, i) { // a^i removes a^i, a^2i, a^3i. i.e a^k
//             if((newmsk>>(k-1))&1) newmsk = newmsk^(1<<(k-1)); //turns off bit k
//         }
//         s.insert(DP(newmsk));
//     }
//     m = 1;
//     while(s.count(m)) ++m;
//     return m;
// }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif

//     cout << "int arr[]={";
//     mem(memo,-1);
//     rep(i,30) cout << (int)DP((1<<i)-1)<<",";
//     cout<<"};";

    int grundy[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
    int n;
    scanf("%d", &n);
    int res = 0, rem = n;
    set<ll> vis;
    for(ll i = 1; i *i <= n; i++) {
        if(vis.count(i)) continue;
        int cnt = 0;
        for(ll j = i; j <= n; j *= i) {
            cnt++;
            --rem;
            vis.insert(j);
            if(i==1) break;
        }
        res ^= grundy[cnt];
    }
    if(rem & 1) res ^= 1;
    printf("%s", res ? "Vasya" : "Petya");

    return 0;
}