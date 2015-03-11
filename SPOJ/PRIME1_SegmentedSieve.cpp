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

typedef long long ll;
using namespace std;

/*
 * Segmented sieve of Eratosthenes used to find primes in range [a, b]
 * Steps
1- find all the primes up to sqrt(b), call them primes[]
2- create a boolean array is_prime[] with length = b-a+1 and fill it with true
3- for each p in primes set is_prime[i*p - a] = false starting at i=ceil(a/p)
4- for each is_prime[i]=true print i+a
 */

//NOTE: in case of multiple test cases, comment calling sieve in
//segmented_sieve and call it once outside the loop

typedef int ntype; 			//adjust to long long if needed
const int SQRT = 31630;		//sqrt(b)
const int INTERVAL = 100005; //b-a

bool primes[SQRT];
bool isPrime[INTERVAL];
void sieve() {
        memset(primes,1,sizeof primes);
        primes[0]=primes[1]=0;
        int d=1;
        for (int i = 2; i * i <= SQRT; i+=d,d=2)
                if (primes[i]){
                	int d2= i==2?i:i+i;
					for (int j = i * i; j < SQRT; j += d2)
						primes[j] = 0;
                }

}

void segmented_sieve(ntype a, ntype b){
	sieve();	//IN CASE OF MULTIPLE TEST CASES,DISABLE AND CALL ONCE OUTSIDE LOOP
	memset(isPrime,1,sizeof isPrime);
	int d=1;
	for (int p = 2; p < SQRT; p+=d,d=2) {
		if(!primes[p]) continue;
		ntype st = (a+p-1)/p; //ceil
		st *= p;
		for (ntype i = st==p?st+p:st; i <= b; i+=p)
			isPrime[i-a]=0;	//DON'T FORGET TO PAD WHEN ACCESS
	}
	if(a==0)	isPrime[0]=isPrime[1]=0;
	if(a==1)	isPrime[0]=0;
}

/*
 * example
 * segmented_sieve(a,b);
 * for(i=a->b)
 * 	if(isPrime[i-a]) print i;
 */
int main() {
	sieve();
	int tst,m,n;
	scanf("%d",&tst);
	char* en="";
	while(tst--){
		scanf("%d%d",&m,&n);
		segmented_sieve(m,n);
		printf(en);
		repe(i,m,n){
			if(isPrime[i-m])
				printf("%d\n",i);
		}
		en="\n";
	}
	return 0;
}
