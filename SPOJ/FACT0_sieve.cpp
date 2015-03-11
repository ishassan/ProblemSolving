#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
#define itr(A,B) typeof(B) A = B
typedef long long ll;
using namespace std;

const ll MAX = 31622780;
bitset<MAX> isprime;
ll primes[MAX];
int siz=0;

void sieve() {
    isprime.set();
    isprime[0]=0;
    primes[siz++]=2;
    for (ll i = 3; i <= MAX; i+=2)
        if (isprime[i]){
            primes[siz++] = i;
            int d2 = i+i;
            for (ll j = i * i; j <= MAX; j += d2)
                isprime[j] = 0;
        }

}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    sieve();
    ll n;
    while(scanf("%lld",&n) && n){
        char* sp="";
        rep(i,siz) {
            if(primes[i]*primes[i]>n) break;
            if(n%primes[i]) continue;
            int pw=0;
            while(n%primes[i]==0) n/=primes[i], ++pw;
            printf("%s%lld^%d ",sp,primes[i],pw);
            sp = " ";
        }
        if(n > 1)
            printf(" %lld^1",n);
        printf("\n");
    }

}
