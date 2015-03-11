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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int arr[3];
int memo[302][302];
bool DP(int a, int b){
    if(a==0 && b == 0) return 0;
    int& m = memo[a][b];
    if(m != -1) return m;
    bool y=1;
    repa(i,1,a,1) y &= DP(a-i,b);
    repa(i,1,b,1) y &= DP(a,b-i);
    repa(i,1,min(a,b),1) y &= DP(a-i,b-i);
    return (m = !y);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    int n;
    scanf("%d",&n);
    rep(i,n) scanf("%d",arr+i);
    if(n==1){
        printf(arr[0]?"BitLGM":"BitAryo");
        return 0;
    }
    if(n==3){
        printf(arr[0]^arr[1]^arr[2]?"BitLGM":"BitAryo");
        return 0;
    }

    mem(memo,-1);
    printf(DP(arr[0],arr[1])?"BitLGM":"BitAryo");
    return 0;
}
