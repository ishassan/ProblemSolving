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

int n,area[20];
char memo[102][(1<<15)+9];
int sum_area[(1<<15)+9];
char DP(int w, int h, int msk)
{
     int idx = int(log2(msk)+1e-7);
     if ((1 << idx) == msk && area[n-1-idx] == w*h) return 1;
     if (w == 0 || h == 0) return 0;
     char& m = memo[h][msk];
     if (m != -1) return m;
     m = 0;
     for (int submsk = (msk-1)&msk; submsk; submsk = (submsk-1)&msk) {
          int submsk2 = msk^submsk;
          int ar=sum_area[submsk],ar2=sum_area[submsk2];
          
          if (ar%h == 0 && ar/h <= w) {
               int nw = ar/h, nw2 = w-nw;
               int nh = h;
               if (nw*nh == ar && nw2 * nh == ar2) {
                    m |= (DP(nw,nh,submsk) && DP(nw2, nh, submsk2));
                    if(m) return m;
               }
          }
          if (ar%w == 0 && ar/w <= h) {
               int nh = ar/w, nh2 = h-nh;
               int nw = w;
               if (nw * nh == ar && nw * nh2 == ar2) {
                    m |= (DP(nw, nh, submsk) && DP(nw,nh2,submsk2));
                    if(m) return m;
               }
          }
     }
     return m;
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     int t=1;
     while (cin >> n && n) {
          int h,w;
          cin >> h >> w;
          rep(i,n) cin >> area[i];
          mem(memo,-1);
          rep(msk,(1<<n)) {
               int sum = 0;
               rep(i,n){
                    if ((msk>>i)&1) sum += area[n-1-i];
               }
               sum_area[msk] = sum;
          }
          printf("Case %d: %s\n", t++, DP(w,h,(1<<n)-1)?"Yes":"No");
     }

     return 0;
}
