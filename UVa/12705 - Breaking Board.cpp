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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    vi v;
    repa(i,1,6,1)
            repa(j,1,6,1) v.push_back(i+j);
    sort(all(v));
    int tst;
    cin >> tst;
    string str;
    getline(cin,str);
    while(tst--){
        getline(cin,str);
        int freq[300]={0};
        rep(i,sz(str)) if(str[i] != ' ')freq[str[i]]++;
        vi v2;
        rep(i,300) if(freq[i]) v2.push_back(freq[i]);
        sort(rall(v2));
        int sum=0;
        rep(i,sz(v2)){
            sum += v2[i]*v[i];
        }
        cout << sum << "\n";
    }

    return 0;
}

