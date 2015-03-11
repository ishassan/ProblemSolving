#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

double dp[22][22];
bool vis[22][22];
double pWin, pDraw;
double s1win, s2win;
double getProb(int p1, int p2){
	if( vis[p1][p2] )return dp[p1][p2];
	if( p1 == 21 )
		return 1;
	if( p2 == 21 )
		return 0;
	if( p1 == 20 && p2 == 20 )
		return pWin/(1-pDraw);
	vis[p1][p2] = 1;
	if( ((p1+p2)/5) % 2 == 0 )
		return dp[p1][p2] = s1win*getProb(p1+1,p2) + (1-s1win)*getProb(p1,p2+1);
	return dp[p1][p2] = s2win*getProb(p1+1,p2) + (1-s2win)*getProb(p1,p2+1);
}

double getWin(int p1, int p2){
	if( vis[p1][p2] )return dp[p1][p2];
	if( p1 == 21 )
		return 1;
	if( p2 == 21 )
		return 0;
	if( p1 == 20 && p2 == 20 )
		return 0;
	vis[p1][p2] = 1;
	if( ((p1+p2)/5) % 2 == 0 )
		return dp[p1][p2] = s1win*getWin(p1+1,p2) + (1-s1win)*getWin(p1,p2+1);
	return dp[p1][p2] = s2win*getWin(p1+1,p2) + (1-s2win)*getWin(p1,p2+1);
}

double getDraw(int p1, int p2){
	if( vis[p1][p2] )return dp[p1][p2];
	if( p1 == 21 )
		return 0;
	if( p2 == 21 )
		return 0;
	if( p1 == 20 && p2 == 20 )
		return 1;
	vis[p1][p2] = 1;
	if( ((p1+p2)/5) % 2 == 0 )
		return dp[p1][p2] = s1win*getDraw(p1+1,p2) + (1-s1win)*getDraw(p1,p2+1);
	return dp[p1][p2] = s2win*getDraw(p1+1,p2) + (1-s2win)*getDraw(p1,p2+1);
}

int main(){
	//freopen("1.in","rt",stdin);
	int tt;
	cin >> tt;
	for (int ii = 0; ii < tt; ++ii) {
		string s;
		getline(cin,s);
		getline(cin,s);
//		cin >> s;
		cin >> s1win >> s2win;
		printf("Case %d: ",ii+1);
		int p1 = 0, p2 =0;
		bool valid = 1;
		for (int i = 0; i < s.size(); ++i) {
			if( s[i] == 'W' ){
				p1++;
				if( (i/5) % 2 == 0 && s1win == 0){
					valid = 0;
				}else if( (i/5) % 2 == 1 && s2win == 0){
					valid = 0;
				}
			}else{
				p2++;
				if( (i/5) % 2 == 0 && s1win == 1 ){
					valid = 0;
				}else if( (i/5) % 2 == 1 && s2win == 1 ){
					valid = 0;
				}
			}
			if( (p1 == 21||p2==21) && i != s.size()-1 )
				valid = 0;
			if( p1 == 20 && p2 == 20 )
				p1 = 15, p2 = 15;
		}
		if( !valid ){
			printf("-1.000000\n");
			continue;
		}
		memset(vis,0,sizeof vis);
		pWin = getWin(15,15);
		memset(vis,0,sizeof vis);
		pDraw = getDraw(15,15);
		if( fabs(pDraw-1) < 1e-9 ){
			printf("0.000000\n");
			continue;
		}
		memset(vis,0,sizeof vis);
		printf("%.6lf\n",getProb(p1,p2));
	}
}
