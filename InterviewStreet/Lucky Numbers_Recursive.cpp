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

const int SUM = 180,SUM2 = 1600;
const int MAX = 2000;
bool primes[MAX];
void sieve() { //O(n ln ln n)
        memset(primes,1,sizeof primes);
        primes[0]=primes[1]=0;
        int d=1;
        for (int i = 2; i * i <= MAX; i+=d,d=2)
                if (primes[i]){
                    int d2= i==2?i:i+i;
                for (int j = i * i; j < MAX; j += d2)
                    primes[j] = 0;
                }

}

ll A,B;
vector<int> digits[2];
ll memo[20][SUM][SUM2];
ll DP(int idx, int prime, int prime2, bool less, bool isB){
    if(prime >= SUM || prime2 >= SUM2) return 0;
    if(idx == -1) return primes[prime] && primes[prime2];
    if(less){
        ll& m = memo[idx][prime][prime2];
        if(m != -1) return m;
        m = 0;
        rep(i,10)
                m += DP(idx-1,prime+i, prime2+i*i, true, isB);
        return m;
    }
    ll res=0;
    repe(i,0,digits[isB][idx]){
        res += DP(idx-1, prime + i,prime2 + i*i,(i < digits[isB][idx]), isB);
    }
    return res;
}

void toDigits(ll num, int idx){
    while(num){
        digits[idx].push_back(num%10);
        num/=10;
    }

}

int main(){
//#ifndef ONLINE_JUDGE
//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);
//#endif


    mem(memo,-1);
    sieve();

    int tst;
    scanf("%d",&tst);
    while(tst--){
        digits[0].clear();
        digits[1].clear();
        scanf("%lld%lld",&A,&B);
        --A;
        toDigits(A,0);
        toDigits(B,1);
        ll res=DP(sz(digits[1])-1,0,0,0,1)-DP(sz(digits[0])-1,0,0,0,0);
        printf("%lld\n",res);
    }
    return 0;
}


