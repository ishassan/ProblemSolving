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

ll cum[100010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    repa(i,1,100005,1) cum[i] = i+cum[i-1];
    int n;
    while(cin >> n && n){
       ll st=1, en=1;
       ll mn=1LL<<60,stbst,enbst;
       do{
           ll sum1 = cum[en]-cum[st-1];
           ll sum2 = cum[n]-sum1;
           if(abs(sum1-sum2) < mn){
               mn = abs(sum1-sum2);
               stbst = st;
               enbst = en;
           }
           if(sum1 == sum2) break;
           if(sum1 < sum2) ++en;
           else ++st;

       }while(en <= n && st<=en);
       cout << stbst << " " << enbst << endl;
    }

    return 0;
}

