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

const int MAX = 10000100;
const int LIM = 10000000;
bool primes[MAX];
vector<int> vprimes;
vector<vector<int> > pre(11);
void sieve()   //O(n ln ln n)
{
     memset(primes, -1, sizeof primes);
     primes[0] = primes[1] = 0;
     int d = 1;
     int i;
     for (i = 2; i *i <= MAX; i += d, d = 2)
          if (primes[i]) {
               vprimes.push_back(i);
               int d2 = i == 2 ? i : i + i;
               for (int j = i * i; j < MAX; j += d2)
                    primes[j] = 0;
          }

     for (i; i < MAX; i += 2)
          if (primes[i])
               vprimes.push_back(i);
}


void gen()
{
     queue<tuple<ll,int,int> > q; //num,k,lst taken idx
     q.push(mt(1LL,0,-1));
     while (q.size()) {
          auto t = q.front();
          ll num = at(t,0);
          int k = at(t,1), idx = at(t,2);
          q.pop();
          repa(i,idx+(num==1) ,sz(vprimes)-1,1) {
//             num * vprimes[i] <= LIM
               if (num <= (LIM / vprimes[i])+10) {
                    ll newnum = num * vprimes[i];
                    int newk = k + (idx != i);
                    pre[newk].push_back(newnum);
                    q.push(mt(newnum ,newk , i));
               } else break;
          }

     }
     rep(i,sz(pre))
     sort(all(pre[i]));
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     freopen("out.txt", "wt", stdout);
#endif

     sieve();
     gen();

     int tst;
     cin >> tst;
     repa(tt,1,tst,1) {
          int a,b,k;
          cin >> a >> b >> k;
          printf("Case #%d: ", tt);
          if (k >= sz(pre)) {
               printf("0\n");
               continue;
          } else
               printf("%d\n",upper_bound(all(pre[k]),b) - lower_bound(all(pre[k]),a));
     }
     return 0;
}
