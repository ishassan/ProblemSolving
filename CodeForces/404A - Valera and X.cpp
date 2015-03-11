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

char g[444][444];
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    int n;
    scanf("%d",&n);
    rep(i,n){
        scanf("%s",g[i]);
    }
    char c1=g[0][0], c2=g[0][1];
    bool yes=1;
    rep(i,n){
        rep(j,n){
            if(i==j || i+j==n-1){
                if(g[i][j]!=c1){
                    yes=0;
                    goto end;
                }
            }
            else{
                if(g[i][j]!=c2){
                    yes=0;
                    goto end;
                }
            }
        }
    }
    end:;
    if(yes && c1 != c2) printf("YES\n");
    else printf("NO\n");
    return 0;
}