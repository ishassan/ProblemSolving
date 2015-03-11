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

const int SIZE = 305;
int d[SIZE][SIZE];
void floyd(int n)
{
     for (int k = 0; k < n; k++)
          for (int i = 0; i < n; i++)
               for (int j = 0; j < n; j++) {
                    d[i][j] |= d[i][k] && d[k][j]  ;
               }

}

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("main.txt", "rt", stdin);
     //  freopen("out.txt", "wt", stdout);
#endif

     int n;
     while (cin >> n) {
          int arr[310]= {0};
          int pos[310]= {0};
          rep(i,n) {
               cin >> arr[i];
               pos[arr[i]] = i;
          }
          mem(d,0);
          rep(i,n) d[i][i]=1;
          string str;
          rep(i,n) {
               cin >> str;
               rep(j,sz(str)) {
                    if (str[j] == '1') d[i][j]=1;
               }
          }
          floyd(n);
          int res[310]= {0};
          repa(i,1,n,1) {
               int idx = pos[i];
               rep(b,n) {

                    if (d[idx][b] && res[b]==0) {
                         int num = arr[b];
                         swap(arr[idx],arr[b]);
                         swap(pos[i],pos[num]);
                         res[b] = i;
                         break;
                    }
               }
          }
          rep(i,n) cout << res[i] << " ";
          cout << "\n";
     }

     return 0;
}
