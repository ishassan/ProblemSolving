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

char str[1000];
vi v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif
    int num;
    scanf("%s",str);
    char* tok = strtok(str,",");
    while(tok !=NULL){
        sscanf(tok,"%d",&num);
        v.push_back(num);
        tok = strtok(NULL,",");
    }
    sort(all(v));
    int l=-10,r=-10;
    rep(i,sz(v)){
        if(i+1 == sz(v) || v[i+1] != v[i]){
            if(v[i]-r<=1){
                r = v[i];
                if(i+1 == sz(v))
                    printf("%d-%d",l,r);
            }
            else{
                if(l > 0)
                {
                    if(l==r)
                        printf("%d,",l);
                    else
                        printf("%d-%d,",l,r);
                }
                l=r=v[i];
                if(i+1==sz(v))
                    printf("%d",l);
            }
        }
    }
    return 0;
}
