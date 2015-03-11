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

string str;
int n,k;
string charToNum[]={"TWO","TWO","TWO","THREE","THREE","THREE","FOUR","FOUR","FOUR","FIVE","FIVE","FIVE","SIX","SIX","SIX","SEVEN","SEVEN","SEVEN","SEVEN","EIGHT","EIGHT","EIGHT","NINE","NINE","NINE","NINE"};

ll memo[100][22];
ll cnt(char c, int remLvl){
    if(remLvl == 0) return 1;
    ll& m = memo[c][remLvl];
    if(m != -1) return m;
    m = 0;
    string word = charToNum[c-'A'];
    rep(i,sz(word)) m += cnt(word[i], remLvl-1);
    return m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    mem(memo,-1);
    for (char c = 'A'; c <= 'Z'; ++c) cnt(c, 20);

    int tst;
    cin >> tst;
    repa(T,1,tst,1){
        cin >> str >> n >> k;
        rep(i,sz(str)){
            if(n==0) break;
            ll res = cnt(str[i],n);
            if(res >= k){
                --n;
                str = charToNum[str[i]-'A'];
                i=-1;
            }
            else{
                k -= res;
            }
        }
        printf("Case %d: %c\n",T,str[k-1]);
    }

    return 0;
}

