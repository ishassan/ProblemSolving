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

int arr[20002];
int n;
int val(int start, int step){
    int cnt=0,sum=0;
    for (int i = start; i < n; i+=step) {
        sum += arr[i];
        ++cnt;
    }
    return cnt>=3?sum:-1<<27;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    cin >> n;
    rep(i,n) cin >> arr[i];
    int mx=-1<<27;
    repa(stp,1,n/2,1)
            rep(st,stp)
            if(n%stp==0)
            mx = max(mx, val(st,stp));
    cout << mx;
    return 0;
}

