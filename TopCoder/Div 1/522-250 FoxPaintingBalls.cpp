#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "algorithm"
#include "cmath"
#include "cstring"
#include "string"
#include "map"
#include "set"
#include "stack"
#include "list"
#include "vector"
#include "queue"

using namespace std;

#define PI acos(-1)
#define MP make_pair
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define SET(v,i) memset(v, i, sizeof(v))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORN(i,a,b) for (int i = (a); i < (b); i++)
#define DOWN(i,a,b) for (int i = (a); i > (b); i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FREOPEN freopen("a.in", "r", stdin); freopen("a.out", "w", stdout)

class FoxAndFlowerShopDivTwo{
public:
	int theMaxFlowers(vector < string > f, int x, int y) {
		int R = f.size();
		int C = f[0].size();
		int result = 0, sum;
		
		//case 1
		
		sum = 0;
		FOR (i, 0, R - 1)
			FOR (j, 0, y - 1) 
				sum += f[i][j] == 'F';
		result = max(result, sum);
		
		//case 2
		sum = 0;
		FOR (i, 0, R - 1)
			FOR (j, y + 1, C - 1) 
				sum += f[i][j] == 'F';
		result = max(result, sum);
		
		//case 3
		sum = 0;
		FOR (i, 0, x - 1)
			FOR (j, 0, C - 1) 
				sum += f[i][j] == 'F';
		result = max(result, sum);
		
		//case 4
		sum = 0;
		FOR (i, x + 1, R - 1)
			FOR (j, 0, C - 1) 
				sum += f[i][j] == 'F';
		result = max(result, sum);
		
		return result;
	}
};
