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

enum{
    DOWN,UP,FRONT,BACK,LEFT,RIGHT
};

int arr[6];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    int a,b,c;
    while(cin >> a >> b >> c){
        int x,y,z;
        cin >> x >> y >> z;
        rep(i,6) cin >> arr[i];
        int sum = 0;
        if(a > x) sum += arr[RIGHT];
        else if(a < 0) sum += arr[LEFT];
        if(b > y) sum += arr[UP];
        else if(b < 0) sum += arr[DOWN];
        if(c > z) sum += arr[BACK];
        else if(c < 0) sum += arr[FRONT];
        cout << sum << "\n";
    }


    return 0;
}

