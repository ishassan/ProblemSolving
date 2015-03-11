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

pii clus[201];
vector<pii> stps;
int freq[201],cnt[201];
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif
    mem(clus, -1);
    int n, m, num, x;
    cin >> n >> m;
    rep(i, m) {
        cin >> num;
        while(num--) {
            cin >> x;
            --x;
            clus[x] = mp(i,freq[i]++);
        }
    }

    int free, cur = 0;
    rep(i, n) if(clus[i].first == -1) {
        free = i;
        break;
    }
    rep(i, n) {
        if(clus[i].first == cur && clus[i].second == cnt[cur]) {
            if(++cnt[cur] == freq[cur]) ++cur;
            continue;
        }
        

        repa(j, i + 1, n - 1, 1) {
            if(clus[j].first == cur && clus[j].second == cnt[cur]) {
                if(clus[i].first > -1) stps.push_back(mp(i, free));
                clus[free] = clus[i];
                stps.push_back(mp(j, i));
                clus[i] = clus[j];
                clus[j].first = -1;
                 if(++cnt[cur] == freq[cur]) ++cur;
                free = j;
                break;
            }
        }
    }

    cout << sz(stps) << endl;
    rep(i,sz(stps)){
        cout << stps[i].first+1 << " " << stps[i].second+1 << endl;
    }

    return 0;
}