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


int tmp[16] = { 1, 0 }, n, counter = 0;
bool prime[32] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1 };
int chk[17];
vector<vi> res;

void prm(int cur,int cnt)
{
    if (cnt == n)
    {
        if (prime[cur + 1]){
            res.push_back(vector<int>(tmp,tmp+n));
        }
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!chk[i] && prime[i + cur])
        {
            chk[i] = 1;
            tmp[cnt] = i;
            prm(i, cnt + 1);
            chk[i] = 0;
        }
    }
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int t=1;
    char* sp="";
    while (~scanf("%d",&n))
    {
        res.clear();
        printf("%s",sp); sp="\n";
        printf("Case %d:\n",t++);
        prm(1, 1);
        rep(i,sz(res)){
            rep(j,sz(res[i])) printf("%d%c",res[i][j]," \n"[j+1==sz(res[i])]);
        }
    }
}
