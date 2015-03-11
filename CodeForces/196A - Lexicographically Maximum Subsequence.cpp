#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b){
  if(a.first > b.first) return 1;
  if(a.first < b.first) return 0;
  return a.second < b.second;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("main.txt","rt",stdin);
  //  freopen("out.txt","wt",stdout);
#endif

  string str;
  cin >> str;
  vector<pair<char,int> > v(sz(str));
  rep(i,sz(str)){
    v[i] = mp(str[i], i);
  }
  sort(all(v), cmp);
  string res;
  int lst=-1;
  rep(i,sz(v)){
    if(v[i].second > lst)
      res += v[i].first, lst = v[i].second;
  }
  cout << res;
  return 0;
}

