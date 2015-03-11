

#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define all(v)                          ((v).begin()), ((v).end())
#define sz(v)                           ((int)((v).size()))
#define clr(v, d)                       memset(v, d, sizeof(v))
#define repi(i, j, n)           for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n)           for(int i=(j);i>=(int)(n);--i)
#define repa(v)                         repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)                       repi(i, 0, sz(v))
#define lp(i, cnt)                      repi(i, 0, cnt)
#define lpi(i, s, cnt)          repi(i, s, cnt)
#define P(x)                            cout<<#x<<" = { "<<x<<" }\n"
#define pb                                      push_back

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef long long         ll;
typedef long double       ld;

const int OO = (int)1e8;        //Small -> WRONG, Large -> OVERFLOW

const double PI  = acos(-1.0);
const double EPS = (1e-7);

int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;   }

map<string, int> idMap;

int id(string str) {
        map<string, int>::iterator it = idMap.find(str);
        if(it == idMap.end()) {
                int s = sz(idMap);
                return idMap[str] = s;
        }
        return it->second;
}

const int MAX = 100001;
int sp, fp;
vector<int> adj[MAX];
bool isChild[MAX];
bool vis[MAX][2];
typedef pair<int, int> Pair;
Pair memo[MAX][2];


#define MP make_pair
#define S first
#define F second

inline void add(Pair &addTo, Pair addFrom) {
        addTo.S += addFrom.S;
        addTo.F += addFrom.F;
}

inline int price(Pair &p) {
        return p.S * sp + p.F * fp;
}

inline int tickets(Pair &p) {
        return p.S + p.F;
}

Pair best(int par, int hasTicket) {
        if(sz(adj[par]) == 0)
                return hasTicket ? MP(0, 0) : MP(1, 0);

        Pair &ret = memo[par][hasTicket];
        if(vis[par][hasTicket]) return ret;
        ret = MP(0, 0);

        // whatever par hasTicket or not; we will try giving him a family ticket
        Pair fTicket = MP(0, 1);
        rep(i, adj[par])        add(fTicket, best(adj[par][i], 1));

        // Now, lets assign single ticket (if do not have one)
        Pair sTicket(1-hasTicket, 0);
        rep(i, adj[par])        add(sTicket, best(adj[par][i], 0));

        if(price(fTicket) == price(sTicket))
                ret = tickets(fTicket) < tickets(sTicket) ? fTicket : sTicket;
        else
                ret = price(fTicket) < price(sTicket) ? fTicket : sTicket;

        vis[par][hasTicket] = 1;
        return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
        freopen("1.in", "rt", stdin);
#endif

        string line, par, child;

        int tt = 1;
        while(cin>>sp>>fp)
        {
                if(sp ==0 && fp == 0)   break;

                clr(vis, 0);
                clr(isChild, 0);
                idMap.clear();
                lp(i, MAX) adj[i].clear();

                cin>>ws;
                while( getline(cin, line))
                {
                        istringstream iss(line);
                        iss>>par;
                        int pi = id(par);

                        while(iss>>child) {
                                int ci = id(child);
                                isChild[ci] = 1;
                                adj[pi].push_back(ci);  // clear when need
                        }

                        cin>>ws;
                        if( isdigit(cin.peek()))        break;
                }

                int n = sz(idMap);
                Pair tot = MP(0, 0);

                lp(i, n) if(!isChild[i])
                        add(tot, best(i, 0));

                cout<<tt++<<". "<<tot.S<<" "<<tot.F<<" "<<price(tot)<<"\n";
        }

        return 0;
}

