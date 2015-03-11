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
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
int oo=(int)1e9;
bool can(string a,string b){
	rep(i,a.sz)
		if(a[i]==' ')
			a.erase(a.begin()+i--);
	rep(i,b.sz)
		if(b[i]==' ')
			b.erase(b.begin()+i--);
	sort(all(a));
	sort(all(b));
	return a==b;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("a.txt","rt",stdin);
    #endif
    int N;
    cin>>N;
    string s;
    vs v;
    getline(cin,s);
    getline(cin,s);
    string s2="";
    rep(nn,N){
    	cout<<s2;
    	s2="\n";
    	v.clear();
    	while(1){
    		getline(cin,s);
    		if(!s.sz)
    			break;
    		v.pb(s);
    	}
    	sort(all(v));
    	rep(i,v.sz)
			for(int j=i+1;j<v.sz;j++)
				if(can(v[i],v[j]))
					cout<<v[i]<<" = "<<v[j]<<endl;
    }
    return 0;
}
