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

ll arr[100003],cum[100003];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int x,n,m,k;
    cin >> n >> m >> k;
    rep(i,n) {
        cin >> arr[i];
        cum[i] = i==0?arr[i]:cum[i-1]+arr[i];
    }
    ll cur=0, lastTaken = -1,curtm=0;
    rep(i,m){
        cin >> x;
        int step = x-curtm;
        int failToTakeIdx = lastTaken+step;
        if(failToTakeIdx >= n) break;
        cur += step;

        int l = 0, h = failToTakeIdx-1;
        while(l < h){
            int mid = l+(h-l+1)/2;
            if(cum[failToTakeIdx-1] - (mid?cum[mid-1]:0) > k)
                l = mid; //first not taken
            else
                h = mid-1;
        }
        lastTaken = l-1;
        curtm=x;
    }
    int lastElement = n-1;
    cur+=lastElement-lastTaken;
    cout << cur << "\n";

    return 0;
}

