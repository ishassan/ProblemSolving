#include <bits/stdc++.h>

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
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

const int MAXN = 200;
vector<vector<pair<int,int> > > adj; //to, cst
int inQ[MAXN], inC;
int dist[MAXN];

bool bellman(int n) {
    queue<int> Q;
    inC++;
    memset(dist , 0, sizeof(dist));
    for (int i = 0; i < n; i++)
        Q.push(i), inQ[i] = inC;
    for (int i = 0; i < n; i++) {
        int s = Q.size();
        while (s--) {
            int cur = Q.front();
            Q.pop();
            inQ[cur] = 0;
            for (pair<int,int> p: adj[cur]) {
                int nxt = p.first;
                int cst = p.second;
                if (dist[nxt] > dist[cur] + cst) {
                    dist[nxt] = dist[cur] + cst;
                    if (inQ[nxt] != inC)
                        Q.push(nxt), inQ[nxt] = inC;
                }
            }
        }
        if (Q.empty())
            return 1;
    }
    return 0;
}
int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.txt", "rt", stdin);
#endif
    char arr[3];
    while (cin >> n && n != 0) {
        cin >> m;
        n++;
        adj = vector<vector<pii> > (n+5);
        while (m--) {
            int a, b, c;
            cin >> a >> b >> arr >> c;
            b += a;
            a--;

            if (arr[0] == 'g')
                swap(a, b), c *= -1;
            c--;
            adj[b].push_back(make_pair(a, c));
        }
        if (bellman(n))
            cout << "lamentable kingdom\n";
        else
            cout << "successful conspiracy\n";
    }
    return 0;
}
