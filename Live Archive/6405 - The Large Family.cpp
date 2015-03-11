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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n;
    while(cin >> n && n){
        n *= 10;
        int mn=1<<27, dad=-1,mom=-1,chl=-1;
        repa(i,0,n,5){
            int c = i*5;

            int rem = n-c;
            rem /= 2;
            if(rem%10 != 0 && rem%10 != 5) {
                if(rem%10 > 5) rem -= (rem%10) - 5;
                else if(rem%10 > 0) rem -= (rem%10);
            }
            if(i - rem > 5) continue;
            while(rem - i > 5) rem -= 5;

            int clcmn = n-i*5-rem*2;
            if(mn > clcmn){
                mn = clcmn;
                dad = mom = rem;
                chl = i;
            }
        }
        if(mn == 1<<27){
            printf("%.1lf 0.0 0.0 0.0\n",n/10.0);
        }
        else
            printf("%.1lf %.1lf %.1lf %.1lf\n",mn/10.0, dad/10.0, mom/10.0, chl/10.0);
    }
    return 0;
}

