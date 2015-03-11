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
#include <fstream>
#include <map>
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
char t[]={'H', 'S' , 'D' , 'C'};
char n[]={'A','K','Q','J','T','9', '8','7' ,'6','5','4','3','2'};
map<char,int> pos;
map<char,int> ps;
struct card
{
	string s;
	card(string ss)
	{
		s = ss;
	}
	card()
	{}
	bool operator < (const card& c)const
	{
		if(pos[s[0]]==pos[c.s[0]])
			return ps[s[1]]<ps[c.s[1]];
		return pos[s[0]]<pos[c.s[0]];
	}
};
int main()
{

	for(int i = 0 ; i < 13 ; i++)
			pos[n[i]]=i;
		for(int i = 0 ; i < 4 ; i++)
			ps[t[i]]=i;
	int tt,n;
	vector<card> c1,c2;
	cin>>n;
	c1.clear();
	c2.clear();
	c1.resize(n);
	c2.resize(n);
	for(int i = 0 ; i < n ; i ++)
	{	cin>>c1[i].s;
	}for(int i = 0 ; i < n ; i ++)
	{	cin>>c2[i].s;
	}
		sort(all(c1));
		sort(all(c2));
		int s =n-1;
		int e = 0;
		int res = 0;
		for (int i=n-1;i>=0;i--)
		{
		  if(c2[i]<c1[s])
			  res++,s--;
		  else
			  e++;
		}
		cout<<res<<endl;


	return 0;
}
