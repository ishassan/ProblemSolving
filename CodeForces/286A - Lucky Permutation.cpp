#include <bits/stdc++.h>
#include <omp.h>

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

int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    int n;
    scanf("%d", &n);
    if(n % 4 > 1) {
        printf("-1\n");
        return 0;
    }
    vi v(n);
    int val = 2;
    for(int i = 0, j = n - 1; i < j; i += 2, j -= 2) {
        v[i] = val;
        v[j] = n + 1 - val;
        val += 2;
    }

    val = n;
    for(int i = 1, j = n - 2; i < j; i += 2, j -= 2) {
        v[i] = val;
        v[j] = n + 1 - val;
        val -= 2;
    }
    if(n%4) v[n/2] = (n+1)/2;
    rep(i, n) {
        printf("%d ", v[i]);
    }
    return 0;
}