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
#include <valarray>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;

const int MAX = 100;
bool primes[MAX];
void sieve()   //O(n ln ln n)
{
    memset(primes, 1, sizeof primes);
    primes[0] = primes[1] = 0;
    int d = 1;
    for(int i = 2; i *i <= MAX; i += d, d = 2)
        if(primes[i]) {
            int d2 = i == 2 ? i : i + i;
            for(int j = i * i; j < MAX; j += d2)
                primes[j] = 0;
        }
        
}

int n, p;
set<ll> st;
void calc(int rem, int lst, ll mul){
    if(rem == 0){
        st.insert(mul);
        return;
    }
    
    repa(i,1,min(rem,lst),1){
        if(i>1 && primes[i]==0) continue;
        calc(rem-i,i,(mul*i)%p);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif

    sieve();
    int tst;
    scanf("%d", &tst);
    while(tst--) {
        scanf("%d%d", &n, &p);
        st.clear();
        calc(n,n,1);
        printf("%d\n", st.size());
    }

    return 0;
}