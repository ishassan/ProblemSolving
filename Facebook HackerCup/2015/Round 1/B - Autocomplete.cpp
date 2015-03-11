#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mt make_tuple
#define tii tuple<int,int>
#define at(t,idx) std::get<(idx)>((t))
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

const int mod = 1000000007;

int memo1[2002][2002];
int memo2[2002][2002];
int vis1[2002][2002], visid1;
int vis2[2002][2002], visid2;
int a,b;
int stressfree(int s1, int s2)
{
     if (s1 == a || s2 == b) return 1;
     if (vis1[s1][s2] == visid1) return memo1[s1][s2];
     int res = stressfree(s1+1,s2);
     if (s2+1 < s1)
          res = (0LL + res + stressfree(s1,s2+1))%mod;

     vis1[s1][s2] = visid1;
     memo1[s1][s2] = res;
     return res;
}
int stressful(int s1, int s2)
{
     if (s2 == b) return 1;
     if (vis2[s1][s2] == visid2) return memo2[s1][s2];
     int res = stressful(s1,s2+1);
     if (s1+1 <= s2)
          res = (0LL + res + stressful(s1+1,s2))%mod;

     vis2[s1][s2] = visid2;
     memo2[s1][s2] = res;
     return res;
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     freopen("out.txt", "wt", stdout);
#endif


     int tst;
     scanf("%d",&tst);
     repa(tt,1,tst,1) {
          scanf("%d-%d",&a,&b);
          visid1++;
          visid2++;
          int res1 = stressfree(0,0);
          int res2 = stressful(0,0);
          printf("Case #%d: %d %d\n",tt,res1,res2);
     }
     return 0;
}
