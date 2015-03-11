#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
#include <string>
#include <cstring>

using namespace std;

#define FOR(i,a,b)   	for(int (i)=(a);(i)<(b);(i)++)
#define PB           	push_back
#define INF          	INT_MAX
#define DEBUG(___x)     cout<<#___x<<" = ["<<___x<<"]"<<endl
#define SORT(___a)      sort(___a.begin(),___a.end())
#define RSORT(___a)     sort(___a.rbegin(),___a.rend())
#define PI           	3.141592653589793238
#define MP           	make_pair
#define PII          	pair<int,int>
#define ALL(___v)       (___v).begin(), (___v).end()
#define VS           	vector<string>
#define VI           	vector<int>
#define S            	size()
#define B				begin()
#define E				end()
#define print(___v)     {cout<<"[";if(___v.S)cout<<___v[0];FOR(___i,1,___v.S)cout<<","<<___v[___i];cout<<"]\n";}
#define clr(___x, ___v)	memset(___x, ___v , sizeof ___x);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

typedef long long 					bint;
template<typename T> string tos( T a ) 	{ stringstream ss; string ret; ss << a; ss >> ret; return ret;}

#define MOD             1000000007

void add(bint &res, bint value) {
    res = (res + value) % MOD;
}

string in;
int N;
bint memo[3][702][702][3];

bool opp(int ca, int cb) {

    return (ca != cb && (ca == 0 || cb == 0));
}

bool adj(int ca, int cb) {

    if(ca + cb == 0)return true;
    return (ca != cb);
}

bint dp(int lc, int st, int ed, int rc) {

    if(st > ed) {

        return 1;
    }

    bint &ret = memo[lc][st][ed][rc];
    if(ret != -1)return ret;

    ret = 0;
    int cnt = 1;
    FOR(i,st+1,ed+1) {

        if(in[i] == '(')cnt++;
        else cnt--;

        if(cnt == 0) {

            FOR(x,0,3)FOR(y,0,3) {

                if(adj(lc, x) == false)continue;
                if(opp(x, y) == false)continue;

                if(i == ed) {

                    if(adj(y, rc) == false)continue;
                    add(ret, dp(x, st+1, i-1, y));
                }
                else {

                    add( ret, (dp(x, st+1, i-1, y) * dp(y, i+1, ed, rc)) % MOD );
                }
            }
            break;
        }
    }

    return ret;
}

int main() {


	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while(cin >> in) {

        N = in.S;
        clr(memo, -1);

        cout << dp(0, 0, N-1, 0) << endl;
	}

	return 0;
}
