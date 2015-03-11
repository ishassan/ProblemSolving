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

double p[103];
int n;

/*
 * score = mul(1-pi) * sum(pi/(1-pi))
 * assume M = mul(1-pi), S = sum(pi/(1-pi))
 * new M after adding pj = M*(1-pj)
 * new S after adding pj = (S + (pj/ 1-pj))
 */
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> n){
        rep(i,n) cin >> p[i];
        sort(p,p+n);
        if(p[n-1] == 1){printf("%.10lf\n",1.0); continue;}
        double M=1,S=0, mx=0;
        repd(i,n-1,0,1){
            M*=(1-p[i]);
            S += (p[i] / (1-p[i]));
            mx = max(mx, M*S);
        }
        printf("%.10lf\n",mx);
    }

    return 0;
}

