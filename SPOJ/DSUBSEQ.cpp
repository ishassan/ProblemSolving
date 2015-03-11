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

/*
 * http://codinghangover.wordpress.com/2013/12/10/spoj-dsubseq-distinct-subsequences/
 A C C
 2 4 8

 - - -
 A - -
 - C -
 A C -

 - - C ==>dup
 A - C ==>dup
 - C C
 A C C


 - - -
 A - -
 - C -
 A C -
 - C C
 A C C
 */

const int mod = 1000000007;
ll memo[100003];
int last[300];
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     int tst;
     string str;
   
     cin >> tst;
     rep(i,tst) {
          cin >> str;
          str = "0" + str; //dummy to sentinel (to represent empty string)
          mem(last,-1);
          memo[0]=1;
          repa(i,1,sz(str)-1,1){
               memo[i] = (memo[i-1]*2)%mod;
               if(last[str[i]] >= 0){
                    memo[i] -= memo[ last[str[i]]-1  ];
                    if(memo[i] < 0) memo[i] += mod;
               }
               last[str[i]] = i;
          }
          cout << memo[sz(str)-1] << endl;
          
     }
     return 0;
}
