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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

const int SIZE = 1000000*2+3;
int arr[SIZE];
int n;
// https://docs.google.com/file/d/0B-7EjuzKMd80VDUwU1kwcFcyQm8/edit
void f(int k)
{
     if (k==2) {
          repa(i,0,n-2,2) 
               swap(arr[i], arr[i+1]);
     } else {
          int val = arr[k-3],i;
          for (i = k-3; i+k <= n+(k-3); i += k) {
               int nxt = arr[i+k];
               arr[i+k] = val;
               val = nxt;
          }
          if(i < n+(k-3)) 
               arr[n+(k-3)] = val;
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

     cin >> n;
     rep(i,n) arr[i] = i+1;
     repa(k,2,n,1) 
          f(k);

     for (int i = n-2,cnt=0; cnt < n; i++, cnt++) 
          cout << arr[i] <<" ";

     return 0;
}
