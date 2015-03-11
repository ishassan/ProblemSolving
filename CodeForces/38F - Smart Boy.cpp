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

string dic[35];
struct state {
    int idx, st, en, sum, mx;
    bool same;
    state() {}
    state(int pidx, int pst, int pen, int psum, int pmx, bool psame) {
        idx = pidx, st = pst, en = pen, sum = psum, mx = pmx, same = psame;
    }
};
void updateLeft(state &stt, char cur)
{
    string &s = dic[stt.idx];
    stt.same = stt.same && s[stt.st] == cur ? 1 : 0;
    stt.st--;
    stt.sum += cur - 'a' + 1;
    stt.mx = max(stt.mx, cur - 'a' + 1);
}
void updateRight(state &stt, char cur)
{
    string &s = dic[stt.idx];
    stt.same = stt.same && s[stt.en] == cur ? 1 : 0;
    stt.en++;
    stt.sum += cur - 'a' + 1;
    stt.mx = max(stt.mx, cur - 'a' + 1);
}
int update(char cur, bool isen, vector<state> v, vector<state>& res)
{
    set<int> uniq;
    rep(i, sz(v)) {
        string &s = dic[v[i].idx];
        int st = v[i].st, en = v[i].en;
        if(!isen) {
            if(st > 0 && s[st - 1] == cur) {
                updateLeft(v[i], cur);
                uniq.insert(v[i].idx);
                continue;
            }
        } else if(isen) {
            if(en + 1 < sz(s) && s[en + 1] == cur) {
                updateRight(v[i], cur);
                uniq.insert(v[i].idx);
                continue;
            }
        }
        if(v[i].same) {
            if(st > 0 && s[st - 1] == cur && s[st]==cur) {
                updateLeft(v[i], cur);
                uniq.insert(v[i].idx);
                continue;
            }
            if(en + 1 < sz(s) && s[en + 1] == cur && s[en]==cur) {
                updateRight(v[i], cur);
                uniq.insert(v[i].idx);
                continue;
            }
        }
        v.erase(v.begin() + i);
        --i;
    }
    res = v;
    return uniq.size();
}


pair<int, vector<int> > memo[32][32][32][2];
//state: dic-idx, st, en, turn
pair<int, vector<int> > DP(bool turn, vector<state> v)
{
    pair<int, vector<int> > &m = memo[v[0].idx][v[0].st][v[0].en][turn];
    if(m.first != -1) return m;
    rep(i, sz(v)) {
        string &s = dic[v[i].idx];
        int st = v[i].st, en = v[i].en;
        vector<state> nxtv[2];
        int num[2]={-1,-1};
        if(st > 0)
            num[0] = update(s[st - 1], 0, v, nxtv[0]);
        if(en + 1 < sz(s))
            num[1] = update(s[en + 1], 1, v, nxtv[1]);
        rep(d, 2) {
            if(num[d]==-1) continue;
            pair<int, vector<int> > nxt = DP(!turn, nxtv[d]);
            int score = nxtv[d][0].sum * nxtv[d][0].mx + num[d];
            nxt.second[turn] += score;

            if(m.first == -1) {
                m = nxt;
                continue;
            }
            if(m.first == turn && nxt.first != turn) continue;
            if(m.first != turn && nxt.first == turn) {
                m = nxt;
                continue;
            }

            if(nxt.second[turn] > m.second[turn]) {
                m = nxt;
                continue;
            }
            if(nxt.second[turn] == m.second[turn] && nxt.second[!turn] < m.second[!turn]) {
                m = nxt;
                continue;
            }
        }
    }
    if(m.first == -1) m.first = !turn;
    return m;
}
vector<state> mp[300];
set<int> uniq[300];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
    #endif
    
    vi v(2, 0);
    rep(i, 32) rep(i2, 32) rep(i3, 32) rep(i4, 2) memo[i][i2][i3][i4] = mp(-1, v);
    int n;
    cin >> n;
    
    rep(i, n) {
        cin >> dic[i];
        rep(j, sz(dic[i])) {
            char c = dic[i][j];

            mp[c].push_back(state(i, j, j, c - 'a' + 1, c - 'a' + 1, 1));
            uniq[c].insert(i);
        }
    }
    pair<int, vector<int> > m = mp(-1, v);
    repa(ch, 'a', 'z', 1) {
        
        if(mp[ch].size() == 0)continue;
        bool turn=0;
        pair<int, vector<int> > nxt = DP(!turn, mp[ch]);
        int score = mp[ch][0].sum * mp[ch][0].mx + sz(uniq[ch]);
        nxt.second[turn] += score;
        if(m.first == -1) {
            m = nxt;
            continue;
        }
        if(m.first == turn && nxt.first != turn) continue;
        if(m.first != turn && nxt.first == turn) {
            m = nxt;
            continue;
        }
        if(nxt.second[turn] > m.second[turn]) {
            m = nxt;
            continue;
        }
        if(nxt.second[turn] == m.second[turn] && nxt.second[!turn] < m.second[!turn]) {
            m = nxt;
            continue;
        }
    }
    cout << (m.first==0?"First\n":"Second\n");
    cout << m.second[0] << " " << m.second[1];
    return 0;
}
