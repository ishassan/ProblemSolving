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


pii arr[202];
int sum;

int isok(double mid, int N){
    double sc = arr[0].first + sum*mid;
    double per = mid;
    reps(i,1,N){
        if(sc < arr[i].first) return 1;
        per += (sc - arr[i].first) / sum;
    }
    if(fabs(per - 1.0) < 1e-9)
        return 0;
    if(per + 1e-9 < 1.0) return 1;
    return -1;
}

double getEqual(int N){
    double s=0,e=1;
    while(fabs(s-e)>1e-9){
        double mid = (s+e)/2.0;
        int ok = isok(mid,N);
        if(ok == 0) return mid;
        if(ok == 1)
            s = mid;
        else
            e = mid;
    }
    return s;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int tst;
    scanf("%d",&tst);
    repe(tt,1,tst){
        int n;sum=0;
        scanf("%d",&n);
        rep(i,n)
                scanf("%d",&arr[i].first),arr[i].second=i, sum+=arr[i].first;

        printf("Case #%d:",tt);
        sort(arr,arr+n);
        double e;
        reps(i,1,n){
            e = getEqual(i+1);
            double sc = arr[0].first + e*sum;
            if(i+1==n || sc < arr[i+1].first)
                break;
        }

        double res[202]={0};
        double sc = arr[0].first + sum*e;
        res[arr[0].second] = e*100;
        reps(i,1,n)
        {
            if(arr[i].first > sc)
                res[arr[i].second]=0;
            else
                res[arr[i].second]=(sc-arr[i].first)*100/sum;
        }

        rep(i,n)
                printf(" %.6lf",res[i]);
        printf("\n");
    }
    
}





