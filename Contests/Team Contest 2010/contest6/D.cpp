#include <map>
#include <set>
#include <math.h>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <complex>
#include <cstdio>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,s,m) for(int i=s;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define PI = (2.0 * acos(0.0));
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef complex<double> point;
#define OO ((int)1e9)
#define Y imag()
#define X real()
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[] = { -1, 0, 1, 0, 1, -1, -1, 1 };

point com(vector<point> &polygon){
	point res(0,0);
	double a = 0;
	for(int i = 0 ; i < polygon.size() ; i++){
		int j = (i+1)%(polygon.size());
		res.X+=(polygon[i].X+polygon[j].X)*(polygon[i].X*polygon[j].Y-polygon[j].X*polygon[i].Y);
		res.Y+=(polygon[i].Y+polygon[j].Y)*(polygon[i].X*polygon[j].Y-polygon[j].X*polygon[i].Y);
		a+= polygon[i].X*polygon[j].Y-polygon[i].Y*polygon[j].X;
	}
	a*=0.5;
	res.X/=6*a;
	res.Y/=6*a;
	return res;
}

int main() {

	freopen("d.in", "rt", stdin);
	int n , t = 1;
	double x , y;
	while(cin>>n && n){
		vector<point> v;
		while(n--){
			cin>>x>>y;
			v.push_back(point(x,y));
		}
		point res = com(v);
		printf("Stage #%d: %.6f %.6f\n",t++,res.X,res.Y);
	}

	return 0;
}
