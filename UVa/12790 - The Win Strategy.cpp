#include <bits/stdc++.h>

#define sz(v) (int)((v).size())
using namespace std;

double memo[10004][3];
int vis[10004][3], visID;
const int R = 0, P = 1, S = 2;
int sc[3][3];
double prob[3];
string a,b;
char mapp[300];

double DP(int idx, int cur){
	if(idx == sz(a)) return 0;
	double& ref = memo[idx][cur];
	if(vis[idx][cur] == visID) return ref;
	ref = 0;
	int opp = mapp[b[idx]];
	if(sc[cur][opp] == 1){
		ref = DP(idx+1, (cur+1)%3)+1;
	}
	else if(sc[cur][opp] == -1){
		ref = DP(idx+1, (opp+1)%3)-1;
	}
	else{
		for (int i = 0; i < 3; ++i) {
			ref += prob[i]*DP(idx+1,i);
		}
	}

	vis[idx][cur] = visID;
	return ref;
}

int actual(){
	int res=0;
	for (int i = 0; i < sz(a); ++i) {
		int p1 = mapp[a[i]];
		int p2 = mapp[b[i]];
		res += sc[p1][p2];
	}
	return res;
}
int dcmp(double a, double b){
	if(fabs(a-b) < 1e-9) return 0;
	return a>b?1:-1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
#endif
	memset(sc,0,sizeof sc);
	mapp['R']=0, mapp['P']=1, mapp['S']=2;
	sc[R][P]=-1; sc[P][R]=1;
	sc[R][S]=1; sc[S][R]=-1;
	sc[S][P]=1; sc[P][S]=-1;

	int tst;
	cin >> tst;
	while(tst--){
		++visID;
		cin >> a >> b;
		for (int i = 0; i < sz(a); ++i) {

		}
		for (int i = 0; i < 3; ++i) {
			cin >> prob[i];
			prob[i] /= 100.0;
		}
		int x = actual();
		double y = 0;
		for (int i = 0; i < 3; ++i) {
			y += prob[i]*DP(0,i);
		}
		if(dcmp(y,0) == 0) y = 0;
		char z = dcmp(y,x) > 0?'Y':'N';
		printf("%d %.4lf %c\n",x,y,z);
	}
}
