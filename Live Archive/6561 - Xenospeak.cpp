#include <bits/stdc++.h>
#include <climits>

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
typedef unsigned long long ull;
using namespace std;

ll cnt_len[60] = {1LL, 3LL, 5LL, 11LL, 21LL, 43LL, 85LL, 171LL, 341LL, 683LL, 1365LL, 2731LL, 5461LL, 10923LL, 21845LL, 43691LL, 87381LL, 174763LL, 349525LL, 699051LL, 1398101LL, 2796203LL, 5592405LL, 11184811LL, 22369621LL, 44739243LL, 89478485LL, 178956971LL, 357913941LL, 715827883LL, 1431655765LL, 2863311531LL, 5726623061LL, 11453246123LL, 22906492245LL, 45812984491LL, 91625968981LL, 183251937963LL, 366503875925LL, 733007751851LL, 1466015503701LL, 2932031007403LL, 5864062014805LL, 11728124029611LL, 23456248059221LL, 46912496118443LL, 93824992236885LL, 187649984473771LL, 375299968947541LL, 750599937895083LL, 1501199875790165LL, 3002399751580331LL, 6004799503160661LL, 12009599006321323LL, 24019198012642645LL, 48038396025285291LL, 96076792050570581LL, 192153584101141163LL, 384307168202282325LL, 768614336404564651LL };

string build(ll wordidx, int len, bool canall)
{
     if (len == 0) return "";
     if (wordidx < (1LL<<(len-1)))
          return "a"+build(wordidx, len-1, 1);

     if (canall)
          return "b"+build(wordidx - (1LL<<(len-1)), len-1, 1);
     else if(len-2 >=0)
          return "bb" + build(wordidx - (1LL<<(len-1)), len-2, 0);
}
string getString(ll word_idx)
{
     int len_idx;
     for (len_idx = 0; word_idx >= cnt_len[len_idx]; word_idx -= cnt_len[len_idx++]);
     ++len_idx;
     return build(word_idx, len_idx, 0);
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     ll n,p;
     int tst=1;
     while (cin >> n >> p && (n || p)) {
          ll n1 = n*(p-1), n2 = n*p-1;
          string s1 = getString(n1);
          string s2 = getString(n2);
          printf("Case %d: %s %s\n",tst++, s1.c_str(), s2.c_str());
     }

     return 0;
}
