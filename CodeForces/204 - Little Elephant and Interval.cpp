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
#include<omp.h>
#include <complex>

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

ll l,r;
int numl[20],numr[20];
int llen=0,rlen=0;

int calcLevel(int lvl, int idx, int i, int arr[]){
    if(lvl == 0 || lvl == 2) return lvl;
    if(i > arr[idx]) return 2;
    else if(i < arr[idx]) return 0;
    return 1;
}

ll memo[20][10][3][3]; //0 sm, 1 sam, 2 lar
ll DP(int idx, int fst,int llvl, int rlvl){
    if(idx > rlen) return 0;
    ll& m = memo[idx][fst][llvl][rlvl];
    if(m != -1) return m;
    m = 0;

    if(idx == 0)
        reps(i,1,10)
                m += DP(idx+1, i, calcLevel(llvl,idx,i,numl),calcLevel(rlvl,idx,i,numr)) + (i>l && i < r);

    else if((idx+1) < llen)
        rep(i,10)
                m += DP(idx+1,fst, calcLevel(llvl,idx,i,numl), calcLevel(rlvl,idx,i,numr));

    else if((idx+1) == llen)
        rep(i,10){
            int ng = calcLevel(llvl,idx,i,numl);
            int ns = calcLevel(rlvl,idx,i,numr);
            m += DP(idx+1,fst, ng, ns);
            if(llen == rlen)
                m += (ng==2 && ns==0 && i==fst);
            else
                m += (ng==2 && i==fst);
        }

    else if((idx+1) < rlen)
        rep(i,10){
            int ng = calcLevel(llvl,idx,i,numl);
            int ns = calcLevel(rlvl,idx,i,numr);
            m += DP(idx+1,fst, ng, ns) + (i==fst);
        }

    else if((idx+1) == rlen)
        rep(i,10){
            int ng = calcLevel(llvl,idx,i,numl);
            int ns = calcLevel(rlvl,idx,i,numr);
            m += DP(idx+1,fst, ng, ns) + (ns==0 && i==fst);
        }
    return m;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    //  freopen("out","wt",stdout);
#endif

    ios_base::sync_with_stdio(false);


    cin >> l >> r;
    --l, ++r;
    mem(memo,-1);
    ll tmp = l;
    while(tmp){
        numl[llen++] = tmp%10;
        tmp /= 10;
    }
    tmp = r;
    while(tmp){
        numr[rlen++] = tmp%10;
        tmp /= 10;
    }
    reverse(numl, numl+llen);
    reverse(numr, numr+rlen);
    cout << DP(0,0,1,1);
    return 0;
}





