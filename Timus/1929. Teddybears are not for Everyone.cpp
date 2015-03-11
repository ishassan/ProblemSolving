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

int arr[1000];
bool isbear[1000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n,m;
    cin >> n >> m;
    rep(i,m) {
        cin >> arr[i];
        isbear[arr[i]]=1;
    }
    sort(arr,arr+m);
    int res = 0;
    repa(i,2,n,1){
        repa(j,i+1,n,1){
            if(!isbear[i] && !isbear[j] && !isbear[1]) continue;
            int remb = m-isbear[i]-isbear[j]-isbear[1];
            int div=(n-3)/3;
            if(remb >= div) ++res;
        }
    }
    cout << res << "\n";

    return 0;
}

