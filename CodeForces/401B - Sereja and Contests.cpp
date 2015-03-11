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
set<int> d1,d2;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    
    int n,x,num,a,b;
    cin >> x >> n;
    while(n--){
        cin >> num;
        if(num == 1){
            cin >> a >> b;
            d2.insert(a);
            d1.insert(b);
        }
        else {
            cin >> b;
            d2.insert(b);
        }
    }
    int mn=0,mx=0;
    set<int> msd;
    repa(i,1,x-1,1){
        if(d1.count(i) || d2.count(i)) continue;
        mx++;
        if(!msd.count(i-1)) {
            mn++;
            msd.insert(i);
        }
    }
    cout << mn << " " << mx;
    return 0;
}