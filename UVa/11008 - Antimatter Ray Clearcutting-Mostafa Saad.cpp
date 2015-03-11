// Another buggy code by mostafa_saad
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define repa(v)             for(int i=0;i<(sz(v));++i) for(int j=0;j<(sz(v[i]));++j)
#define rep(i, v)           for(int i=0;i<(sz(v));++i)
#define lp(i, cnt)          for(int i=0;i<(cnt);++i)
#define lpi(i, s, cnt)      for(int i=(s);i<(cnt);++i)
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"

typedef long long ll;
typedef long double ld;

const int OO = (int)1e8;    // Note, IF Small may be WRONG, Large may generate OVERFLOW
const double PI  = acos(-1);
const double EPS = (1e-7);

int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;   }

typedef vector<int> vi;


int setBit(int num, int idx, int value = 1) { return (value) ? (num |(1<<idx) ) : (num &~(1<<idx)); }
int getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
int cntBits(int num) {int ret = 0; while (num) { if(num%2)  ret++;  num/=2; }   return ret;}


int memo[1<<17];
int n, m;

int X[100], Y[100];
int missedPoints[100][100];

int best(int mask)
{
//  cout<<mask<<" "<<n-cntBits(mask)<<"\n";
    if( n-cntBits(mask) >= m)   return 0;
    if( memo[mask] != -1)       return memo[mask];

    vector<int> v;  lp(i, n) if( getBit(mask, i))   v.push_back(i);

    int ret = OO;
    lp(i, sz(v))    lpi(j, i+1, sz(v))
        ret = min(ret, 1 + best( mask & missedPoints[ v[i] ][ v[j] ] ) );

    if(ret == OO)   ret = 1;    // SILLY BUG: What if nothing accesed the DP Logic
    return memo[mask] = ret;
}

// If I, J on same line, what is the mask if missed points
void buildRelations()
{
    lp(i, n)
    {
        lpi(j, 0, n) if(i != j) // DO not LIMIT for i+1, j+1,
        {
            int tempMask = (1<<n)-1;
            tempMask = setBit(tempMask, i, 0);
            tempMask = setBit(tempMask, j, 0);

            lpi(k, 0, n) if(i != k && j != k)
            {
                int x1 = X[j] - X[i];
                int y1 = Y[j] - Y[i];
                int x2 = X[k] - X[i];
                int y2 = Y[k] - Y[i];
                if(x1*y2 - y1*x2 == 0)
                    tempMask = setBit(tempMask, k, 0);
            }
            missedPoints[i][j] = tempMask;
        }
    }

}

int main()
{
    freopen("game.in", "rt", stdin);

    int cases;

    cin>>cases;

    char *l = "";
    for (int k = 1; k <= cases; ++k) {
        cout<<l;    l = "\n";

        cin>>n>>m;

        lp(i, n)    cin>>X[i]>>Y[i];

        buildRelations();

        clr(memo, -1);

        cout<<"Case #"<<k<<":\n";
        cout<<best( (1<<n)-1)<<"\n";

    }

    return 0;
}
