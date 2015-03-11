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

const int MAX = 100000;
long long primepow1[MAX], prime1[MAX], nprimes1 = 0;
long long primepow2[MAX], prime2[MAX], nprimes2 = 0;

void factorization(long long n, ll primepow[], ll prime[], ll& nprimes) { // O(sqrt(n))
    nprimes = 0;
    long long pow = 0;
    int d = 1;
    for (long long i = 2; i * i <= n; i += d, d = 2) {
        pow = 0;
        while (!(n % i))	pow++, n /= i;
        if (pow != 0)
            primepow[nprimes] = pow, prime[nprimes++] = i;
    }
    if (n > 1)
        primepow[nprimes] = 1, prime[nprimes++] = n;
}
//-----------------------------------------
long long divs1[MAX];//holds divisors
long long divs2[MAX];//holds divisors
int sz1 = 0,sz2=0;
void generate_divisors(int ind, ll divs[], int& sz,ll primepow[], ll prime[], ll& nprimes , long long mul = 1) {

    if (ind == nprimes) {
        divs[sz++] = mul;	return;
    }
    long long x = 1;
    for (int i = 0; i <= primepow[ind]; i++) {
        generate_divisors(ind + 1,divs,sz,primepow,prime,nprimes, mul * x);
        x *= prime[ind];
    }
}
char stra[100002],strb[100002];
string a,b;

bool isvalid(int len){
    for (int i = 0,ii=len; ii < sz(a); ++i,++ii) {
        if(a[i%len] != a[ii]) return 0;
    }
    return 1;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif


    scanf("%s %s",stra,strb);
    a = stra, b = strb;

    if(sz(a) > sz(b)) swap(a,b);

    //handle 0
    for (int i = 0,j=0; j < sz(b); ++i,++j) {
        if(a[i%sz(a)] != b[j]){
            printf("0\n");
            return 0;
        }
    }
    factorization(sz(a),primepow1,prime1,nprimes1);
    factorization(sz(b),primepow2,prime2,nprimes2);
    generate_divisors(0,divs1,sz1,primepow1,prime1,nprimes1);
    generate_divisors(0,divs2,sz2,primepow2,prime2,nprimes2);
    sort(divs1,divs1+sz1);
    sort(divs2,divs2+sz2);

    vi common;
    int i=0,j=0;
    while(i<sz1 && j< sz2){
        if(divs1[i] == divs2[j]){
            common.push_back(divs1[i]);
            ++i, ++j;
        }
        else if(divs1[i] > divs2[j]) ++ j;
        else ++i;
    }

    int res=0;
    rep(i,sz(common)){
        res += isvalid(common[i]);
    }
    printf("%d\n",res);
    
}





