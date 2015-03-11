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

ll fib[50]={0,1};


const int MAX = 1000000;
map<int,int> fct1,fct2;

void factorization(long long n, map<int,int>& fct) { // O(sqrt(n))
    long long pow = 0;
    int d = 1;
    for (long long i = 2; i * i <= n; i += d, d = 2) {
        pow = 0;
        while (!(n % i))	pow++, n /= i;
        if (pow != 0)
            fct[i]+=pow;
    }
    if (n > 1)
        fct[n]+=1;
}

void insert(map<int,int>& fct1,map<int,int>& fct2){
    repi(it,fct2){
        fct1[it->first] += it->second;
    }
}
void pwr(map<int,int>& fct, int mul){
    repi(it,fct){
        fct[it->first] *= mul;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    repa(i,2,42,1) fib[i]=fib[i-1]+fib[i-2];
    int tst;
    cin>>tst;
    while(tst--){
        fct1.clear();
        fct2.clear();
        int a,b,n;
        cin >> n >> a >> b;
        factorization(a,fct1);
        factorization(b,fct2);

        if(n > 2){
            pwr(fct1, fib[n-1]);
            pwr(fct2, fib[n]);
        }
        insert(fct1,fct2);
        repi(it,fct1){
            cout << it->first << " " << it->second << "\n";
        }
        cout << "\n";
    }
    return 0;
}

