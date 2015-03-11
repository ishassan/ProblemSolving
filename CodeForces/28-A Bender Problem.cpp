#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
	if (fabs(a - b) < eps)
		return 0;
	return a > b ? 1 : -1;
}

int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int diK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int djK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int I, J;

inline bool val(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

int N;
int n,m;
int xs[500];
int ys[500];
int ms[500];
int ret[500];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("a.txt","rt",stdin);
    #endif
    cin>>n>>m;
    rep(i,n)
		cin>>xs[i]>>ys[i];
    rep(i,m)
		cin>>ms[i];
    bool found=0;
    rep(st,2){
    	map<int,vi> t;
    	mem(ret,-1);
    	rep(i,m)
			t[ms[i]].pb(i);
    	int ind=st;
    	rep(i,n/2){
    		int ind2=(ind+1)%n;
    		int ind3=(ind-1+n)%n;
    		int d1=abs(xs[ind]-xs[ind2])+abs(ys[ind]-ys[ind2]);
    		int d2=abs(xs[ind]-xs[ind3])+abs(ys[ind]-ys[ind3]);
    		int d=d1+d2;
    		if(!t[d].sz)
    			goto END;
    		ret[ind]=t[d].back()+1;
    		t[d].pop_back();
    		ind+=2;
    		ind%=n;
    	}
    	found=1;
    	cout<<"YES"<<endl;
    	rep(i,n){
    		if(i)
    			cout<<" ";
    		cout<<ret[i];
    	}
    	cout<<endl;
    	break;
    	END:;
    }
    if(!found)
    	cout<<"NO"<<endl;
	return 0;
}
