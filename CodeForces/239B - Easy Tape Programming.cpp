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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int tst;
    string old;
    cin >> tst >> tst >> old;
    while(tst--) {
        int l, r, pos, dir = 1;
        string str = old;
        cin >> l >> r;
        --l, --r, pos = l;
        int cnt[12] = {0};
        while(pos >= l && pos <= r) {
            if(isdigit(str[pos])) {
                cnt[str[pos] - '0']++;
                if(str[pos]=='0'){
                    str.erase(pos,1);
                    --r;
                    if(dir==-1) --pos;
                    continue;
                }
                str[pos]--;
                pos += dir;
            }
            else{
                dir = str[pos]=='>'?1:-1;
                int npos = pos + dir;
                if(npos < l || npos > r) break;
                if(str[npos] == '>' || str[npos] == '<'){
                    str.erase(pos,1);
                    --r;
                    if(dir==1) --npos;
                }
                pos = npos;
            }
        }
        rep(i,10) cout << cnt[i] << " ";
        cout << endl;
    }


    return 0;
}
