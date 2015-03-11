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

using namespace __gnu_cxx;

struct hashing {
     int operator ()(const pair<int, char> &p) const {
          return p.first * 257 + p.second;
     }
};

unordered_map<pair<int, char> , int , hashing> trie;
int num_nodes;
int insert_char(int node, char c)
{
     auto itr = trie.find(make_pair(node, c));
     if (itr == trie.end()) {
          trie[make_pair(node, c)] = ++num_nodes;
     }
     return trie[make_pair(node, c)];
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
     cin >> tst;
     repa(tt,1,tst,1) {
          int n,res=0;
          cin >> n;
          trie.clear();
          num_nodes = 0;
          string str;
          rep(i,n) {
               cin >> str;
               int node=0, j;
               for (j = 0; j < sz(str); j++) {
                    ++res;
                    if (trie.count(make_pair(node,str[j])))
                         node = trie[make_pair(node,str[j])];
                    else
                         break;
               }
               for (; j < sz(str); j++) {
                    trie[make_pair(node,str[j])] = ++num_nodes;
                    node = num_nodes;
               }
          }
          printf("Case #%d: %d\n",tt,res);

     }
     return 0;
}
