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

int arr[100002],cum[100002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n;
    cin >> n;
    rep(i,n) {
        cin >> arr[i];
        cum[i] = i==0?arr[i]:cum[i-1]+arr[i];
    }
    int a,b;
    cin >> a >> b;
    --a,--b;
    if(a == b){
        pii p1 = mp(cum[a], cum[n-1]-cum[a]);
        pii p2 = mp(cum[n-1]-cum[a-1], cum[a-1]);
        p1 = max(p1,p2);
        cout << p1.first <<" " << p1.second << "\n";
        return 0;
    }
    int siz = max(a,b)-min(a,b)-1;
    int mid;
    if(a<b){
        mid = a+(siz+1)/2;
        cout << cum[mid] <<" " << cum[n-1]-cum[mid]<<"\n";
    }
    else{
        mid = a-(siz+1)/2;
        cout << cum[n-1]-cum[mid-1] << " " << cum[mid-1] <<"\n";
    }


    return 0;
}

