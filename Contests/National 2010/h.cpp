#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>

#define fo(i,n) for(int i=0; i<n; ++i)
#define foo(i,m,n) for(int i=m; i<n; ++i)
#define foe(i,m,n) for(int i=m; i<=n; ++i)
#define SZ(a) a.size()
#define  mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream

typedef long long ll;
using namespace std;

int main() {

	freopen("starship.in", "r", stdin);

	int T;
	scanf("%d",&T);
	int N;

	vector <pair<int,int> > al;
	long long F,res,cnt,x;
	long long f,s,a,b,R1,R2,M1=1<<31,M2=1<<7,a1,a2,b1,b2;
	while(T--)
	{
		scanf("%d",&N);
		cin>>F;
		cin>>f>>s>>a>>b;
		al.clear();
		al.resize(N);
		al[0]=make_pair(s,f);
		res=0;
		cnt=0;
		a1=a%M1;
		b1=b%M1;
		a2=a%M2;
		b2=b%M2;
		for(int i=1;i<al.size();++i)
		{
			R1= ((((al[i-1].first%M1)*a1)%M1)+b1)%M1;

			R2= ((((al[i-1].second%M2)*a2)%M2)+b2)%M2;
			al[i]=make_pair(R1,R2);
		}
		sort(al.begin(),al.end());
		for(int i=0;i<al.size();++i)
		{
			if(cnt==F)break;
			x=min(F-cnt,(long long)al[i].second);
			cnt+=x;
			res+=(al[i].first*x);

		}
		cout<<res<<endl;


	}

	return 0;
}
