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
#define indexof(v,x) (int((find((v).begin(), (v).end(),(x))-(v).begin() + 1)%((v).size()+1))-1)

typedef long long ll;
using namespace std;

string str;
set<char> uniq;
int cnt[300];
ll fact[21];
string get_perm(ll rem)
{
     string res;
     int siz = sz(str);
     while (rem) {
          ll sum = 0;
          auto cur = uniq.begin();
          while (1) {
               ll f = fact[siz-1];
               repa(c,'a','z',1) {
                    int div = c == *cur?cnt[c]-1:cnt[c];
                    if (div > 1) f /= div;
               }
               if (f + sum > rem) {
                    rem -= sum;
                    siz--;
                    res += *cur;
                    cnt[*cur]--;
                    if (cnt[*cur] == 0) uniq.erase(cur);
                    break;
               } else {
                    sum += f;
                    ++cur;
               }
          }
     }
     repa(c,'a','z',1) if (cnt[c]) res += string(cnt[c],c);
     return res;
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
//       freopen("out.txt", "wt", stdout);
#endif
     
     int tst;
     ll rem;
     fact[0] = fact[1] = 1;
     repa(i,2,20,1) fact[i] = fact[i-1]*i;
     cin >> tst;

     while (tst--) {
          cin >> str >> rem;
          sort(all(str));
          mem(cnt,0);
          uniq.clear();
          rep(i,sz(str)) cnt[str[i]]++, uniq.insert(str[i]);

          cout << get_perm(rem) << "\n";
     }
     return 0;
}
