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

string html;
vi v;
string getNext(int &st)  //st is '<'
{
    int pos = html.find('>', st + 1);
    string res = html.substr(st, pos - st + 1);
    st = pos;
    return res;
}
int parseTable(int st)
{
    getNext(st);
    ++st;
    int res = 0;
    repa(i, st, sz(html)-1, 1) {
        string str = getNext(i);
        if(str == "<tr>" || str == "</tr>") continue;
        if(str == "<td>") {
            int tmpi = i+1;
            string nxt = getNext(tmpi);
            if(nxt == "<table>") 
                i = parseTable(i+1);
            else{
                i = tmpi;
                ++res;
            }
        }
        else if(str == "</td>") ++res;
        else if(str=="</table>"){
            v.push_back(res);
            return i;
        }
    }
    return -1<<27;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif
    string str;
    while(getline(cin, str)) html += str;
    if(sz(html) == 0) {
        cout << 0; return 0;
    }
    parseTable(0);
    sort(all(v));
    repi(it,v) cout <<*it<<" ";


    return 0;
}
