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

int lis_nlogn(vector<int>& v)
{
    vector<int> len(v.size() + 1, 1e9);
    len[0] = -1e9;
    int mx = 0;
    for(int i = 0; i < (int)v.size(); i++) {
        int l = lower_bound(len.begin(), len.end(), v[i]) - len.begin(); //strictly increasing, if u want non-decreasing use upper_bound
        mx = max(mx, l);
        len[l] = v[i];
    }
    return mx;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    int n, m;
    double d;
    scanf("%d%d", &n, &m);
    vi v(n);
    rep(i, n) {
        scanf("%d%lf", &v[i], &d);
    }
    printf("%d", n - lis_nlogn(v));

    return 0;
}