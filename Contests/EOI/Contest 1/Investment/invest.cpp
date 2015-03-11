#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include<fstream>
#include <set>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
typedef long long ll;
int N;
int ir[20];
int p[20];
int dp[50000];
int am ;
int main()
{
	int tt,d;
		cin>>am>>N;
		cin>>d;
		for(int i = 0 ; i < d ; i ++ )
		{	cin>>p[i]>>ir[i];

		}
		for( int i=0;i<50000;i++)
		{
			dp[i]=0;
			for (int j=0;j<d;j++)
				if (i>=p[j]/1000 && ir[j]+dp[i-p[j]/1000]>dp[i])
					dp[i]=dp[i-p[j]/1000]+ir[j];
		}
		int res = am;
		for(int i = 0; i < N; i++)
			res += dp[res / 1000];

		cout<<res<<endl;


	return 0;
}
