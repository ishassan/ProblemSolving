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

char str[100003];
int cum[100003], res[100003];
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    int n, k, w;
    scanf("%d%d%d%s", &n, &k, &w, str + 1);
    cum[0] = 0, str[0] = '0';
    repa(i, 0, n, 1) {
        cum[i] = cum[i - 1] + (str[i] == '1');
        if(i < k) continue;
        res[i] = cum[i - 1] - cum[i - k] + (str[i] == '0');
        res[i] += res[i-k];
    }

    while(w--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n",res[r]-res[l-1]);
    }
    return 0;
}