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

int n, d, l;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif

    while(cin >> n >> d >> l) {
        vi arr(n);
        int po = (n + 1) / 2, ne = (n / 2);
        int nval, pval, div, rem;
        if(po * l - ne < d) {
            cout << -1;
            goto end;
        }
        if(po - ne * l > d) {
            cout << -1;
            goto end;
        }

        if(d >= 0) {
            pval = d + ne;
            div = pval / po, rem = pval % po;
        } else {
            nval = po - d;
            div = nval / ne, rem = nval % ne;
        }

        rep(i, n) {
            if((i & 1) == (d<0)) {
                int num = div;
                if(rem) num++, --rem;
                if(num == 0)    ++num, ++arr[i-1];
                if(num > l || (i > 0 && arr[i-1] > l)) {
                    cout << -1;
                    goto end;
                }
                arr[i] = num;
            } else
                arr[i] = 1;
        }
        rep(i, n) {
            cout << arr[i] << " ";
        }
    end:
        cout << endl;
    }
    return 0;
}