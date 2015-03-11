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

char grid[1002][1002];
int vis[1002][1002];
int row1 = -1, col1 = -1;
vector<pii> bomb[2];
set<pii> rats[2];

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
int n, m, d, numrat = 0, curvis = 0;
void BFS(int r, int c, int nbomb, int nrat)
{
    queue<pair<pii, int> > q;
    curvis++;
    vis[r][c] = curvis;
    q.push(mp(mp(r, c), 0));
    if(nrat > -1 && grid[r][c] == 'R')
        rats[nrat].insert(mp(r, c));
    else if(nbomb > -1)
        bomb[nbomb].push_back(mp(r, c));

    while(q.size()) {
        r = q.front().first.first;
        c = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        if(steps == d) continue;

        rep(d, 4) {
            int nr = r + di[d];
            int nc = c + dj[d];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == 'X' || vis[nr][nc] == curvis) continue;
            vis[nr][nc] = curvis;
            q.push(mp(mp(nr, nc) , steps + 1));
            if(nrat > -1 && grid[nr][nc] == 'R')
                rats[nrat].insert(mp(nr, nc));
            else if(nbomb > -1)
                bomb[nbomb].push_back(mp(nr, nc));
        }
    }
}


int main()
{

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);


    scanf("%d%d%d", &n, &m, &d);
    rep(i, n) {
        scanf("%s", grid[i]);
        string tst = grid[i];
        rep(j, m)
        if(grid[i][j] == 'R') {
            ++numrat;
            row1 = i, col1 = j;
        }
    }

    BFS(row1, col1, 0, -1);
    rep(k, sz(bomb[0])) {
        pii b = bomb[0][k];
        if(b.first == 6 && b.second == 9)
            int t = 1;
        rats[0].clear();
        BFS(b.first, b.second, -1, 0);
        if(rats[0].size() == numrat) {
            rep(ii, n)
            rep(jj, m) {
                if(grid[ii][jj] == 'X' || (ii == b.first && jj == b.second)) continue;
                printf("%d %d %d %d", b.first + 1, b.second + 1, ii + 1, jj + 1);
                return 0;
            }
        }
        rep(i, n)
        rep(j, m) {
            if(grid[i][j] != 'R' || rats[0].count(mp(i, j))) continue;
            bomb[1].clear();
            BFS(i, j, 1, -1);

            rep(k2, sz(bomb[1])) {
                pii b2 = bomb[1][k2];
                if(b2.first == 1 && b2.second == 2)
                    int t = 1;
                rats[1].clear();
                BFS(b2.first, b2.second, -1, 1);
                set<pii> res = rats[0];
                res.insert(all(rats[1]));
                if(res.size() == numrat) {
                    printf("%d %d %d %d", b.first + 1, b.second + 1, b2.first + 1, b2.second + 1);
                    return 0;
                }
            }
            goto out;
        }
    out:
        ;

    }
    printf("-1");

    return 0;
}