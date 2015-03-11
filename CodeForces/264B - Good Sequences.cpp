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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;


const int MAX = 1000100;
bool primes[MAX];
vi divprimes[MAX];
int cntused[MAX], memo[MAX];
void sieve()   //O(n ln ln n)
{
    memset(primes, 1, sizeof primes);
    primes[0] = primes[1] = 0;
    int d = 1;
    for(int i = 2; i  < MAX; i += d, d = 2)
        if(primes[i]) {
            divprimes[i].push_back(i);
            for(int j = i + i; j < MAX; j += i) {
                primes[j] = 0;
                divprimes[j].push_back(i);
            }
        }
}

int n;
vi v;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    sieve();
    scanf("%d",&n);
    v.resize(n);
    int res=0;
    rep(i,n) {
        scanf("%d",&v[i]);
        int num = v[i];
        rep(j,sz(divprimes[num])){
            int div = divprimes[num][j];
            memo[i] = max(memo[i], cntused[div]+1);
        }
        res = max(res, memo[i]);
        rep(j,sz(divprimes[num])){
            int div = divprimes[num][j];
            cntused[div] = memo[i];
        }
    }
    if(n==1 && v.front()==1)
        printf("1");
    else
        printf("%d",res);
    
    return 0;
}