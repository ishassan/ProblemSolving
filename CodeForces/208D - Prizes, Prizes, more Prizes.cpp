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

int arr[100];
int pri[5];
ll num[5];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n;
    cin >> n;
    rep(i,n) cin >> arr[i];
    rep(i,5) cin >> pri[i];
    ll sum = 0;
    rep(i,n){
        sum += arr[i];
        while(sum){
            int idx = upper_bound(pri,pri+5,sum)-pri-1;
            if(idx == -1) break;
            num[idx]+= sum/pri[idx];
            sum %= pri[idx];
        }
    }
    char* sep="";
    rep(i,5) cout <<sep<< num[i], sep=" ";
    cout << "\n"<<sum;
    return 0;
}

