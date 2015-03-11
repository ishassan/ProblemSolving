#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

const int SZ = 102;
vector<int> x[SZ], y[SZ];


int maxX=-1,maxY=-1;

int area = -1;
int onex,oney,twox,twoy;

void checkRest(int xx,int yy){
	int sz = x[xx].size();
	int len= twox-onex;
	for(int i=0; i<sz; i++){
		if(x[xx][i]== yy+len){

			for(int j=0; j<y[yy+len].size(); j++){
				if(y[yy+len][j] == onex)
					area = max(area,(twox-onex)*(twox-onex));
			}
			break;
		}
	}
}
void checkSecond(int xx, int yy){
	int sz = y[yy].size();
	for(int yi=0; yi<sz; yi++){
		twox = y[yy][yi], twoy=yy;
		checkRest(y[yy][yi], yy);
	}
}

void checkFirst(int xi){
	// now on first corner (x[xi],...)
	int sz = x[xi].size();
	for(int yi=0; yi<sz; yi++){

		onex = xi, oney = x[xi][yi];
		checkSecond(xi, x[xi][yi]);
	}
}

int main() {

	int n;
	cin>>n;
	int xx,yy;
	fo(i,n)
	{
		cin>>xx>>yy;
		maxX = max(maxX,xx);
		maxY = max(maxY,yy);
		x[xx].push_back(yy);
		y[yy].push_back(xx);
	}

	fo(i,SZ){
		sort(x[i].rbegin(), x[i].rend());
		sort(y[i].rbegin(), y[i].rend());
	}

	for(int i =0; i<=maxX; i++){
		checkFirst(i);
	}

	if(area==0)
		cout<<-1<<endl;
	else
	cout<<area<<endl;

	return 0;
}
