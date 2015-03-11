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

char grid[5][5];
pii hsh[300];
string insrt="ABCDEFGHIKLMNOPQRSTUVWXYZ";
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif
     string key,txt;
     int tst;
     cin >> tst;
     getline(cin,txt);
     repa(t,1,tst,1){
          getline(cin,key);
          getline(cin,txt);
          string tmpkey,tmptxt;
          rep(i,sz(key)) if(isalpha(key[i]))  tmpkey += toupper(key[i]);
          rep(i,sz(txt)) if(isalpha(txt[i])) tmptxt += toupper(txt[i]);
          key = tmpkey, txt = tmptxt;
          set<char> vis;
          vis.insert('J');
          int r=0,c=0;
          rep(i,sz(key)){
               if(vis.count(key[i])) continue;
               vis.insert(key[i]);
               grid[r][c] = key[i];
               hsh[key[i]] = mp(r,c);
               if(++c == 5) ++r,c=0;
          }
          repa(i,'A','Z',1){
               if(!vis.count(i)){
                    grid[r][c] = i;
                    hsh[i] = mp(r,c);
                    if(++c == 5) ++r,c=0;
               }
          }
          int ins=0;
          repa(i,0,sz(txt)-1,2){
               if(i == sz(txt)-1){
                    if(insrt[ins] == txt[i]){
                         ins = (ins+1)%sz(insrt);
                         i -= 2;
                         continue;
                    }
                    txt += insrt[ins];
                    ins = (ins+1)%sz(insrt);
                    continue;
               }
               if(txt[i] == txt[i+1]){
                    if(insrt[ins] == txt[i]){
                         ins = (ins+1)%sz(insrt);
                         i -= 2;
                         continue;
                    }
                    txt.insert(i+1,1,insrt[ins]);
                    ins = (ins+1)%sz(insrt);
               }
          }
          string res;
          repa(i,0,sz(txt)-1,2){
               pii p1 = hsh[txt[i]], p2 = hsh[txt[i+1]];
               if(p1.first == p2.first){
                    res += grid[p1.first][(p1.second+1)%5];
                    res += grid[p2.first][(p2.second+1)%5];
               }
               else if(p1.second == p2.second){
                    res += grid[(p1.first+1)%5][p1.second];
                    res += grid[(p2.first+1)%5][p2.second];
               }
               else{
                    res += grid[p1.first][p2.second];
                    res += grid[p2.first][p1.second];
               }
          }
           
          
          printf("Case %d: %s\n", t, res.c_str());
     }

     return 0;
}
