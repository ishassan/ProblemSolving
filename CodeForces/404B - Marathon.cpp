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

double fa, fd;
ll n, a, d;
int diry[] = {0, 1, 0, -1};
int dirx[] = {1, 0, -1, 0};
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(0);
    cin >> fa >> fd;
    a = (ll)(fa * 10000.0 + 1e-7), d = (ll)(fd * 10000.0 + 1e-7);
    cin >> n;
    ll x = 0, y = 0;
    int direc = 0;
    ll cpd = d;
    rep(i, n) {
        cpd = cpd % (4 * a);
        while(cpd > 0) {
            x += dirx[direc] * a;
            y += diry[direc] * a;
            cpd -= a;
            direc = (direc + 1) % 4;
        }
        direc = (direc + 1) % 4;
        x += dirx[direc] * (-cpd);
        y += diry[direc] * (-cpd);
        printf("%.5lf %.5lf\n", x / 10000.0, y / 10000.0);

        x += dirx[direc] * cpd;
        y += diry[direc] * cpd;
        cpd += d;
        direc = (direc + 3) % 4;

    }
    return 0;
}