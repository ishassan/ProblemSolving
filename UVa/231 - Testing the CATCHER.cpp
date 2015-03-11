#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

const int MAX = 10000;
int memo[MAX][MAX];
vector<int> in;

int lis(int cur, int last){
	if(cur == in.size())
		return 0;

	if(memo[cur][last]!=-1)
		return memo[cur][last];

	int no = lis(cur+1, last);
	int yes =0;

	if(last==in.size() || in[cur]<=in[last])
		yes = lis(cur+1,cur) +1;

	return memo[cur][last] = max(yes,no);

}
int main() {

	//freopen("out.txt","w",stdout);

	int cur;
	bool found = 0;
	int tst=1;
	bool start = 1;
	bool endln = 0;

	while (1) {

		in.erase(in.begin(),in.end());
		if(start){
			start=0;
			cin>>cur;
			if(cur==-1)
				return 0;

			in.push_back(cur);
		}
		while (cin >> cur) {

			if (cur == -1) {

				if (found)
					goto end;

				else {
					found = 1;

					if(endln)
						cout<<endl;

					else
						endln = 1;

					break;
				}

			}

			found = 0;

			in.push_back(cur);

		}

		int size = in.size() +1;

		fo(i,size)
			fo(j,size)
				memo[i][j]=-1;

		cout<<"Test #"<<tst++<<":\n";
		cout<<"  maximum possible interceptions: "<<lis(0,size-1)<<endl;
	}

	end:
	return 0;
}

