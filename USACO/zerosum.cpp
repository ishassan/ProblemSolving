/*
 ID: fci_isl1
 LANG: C++
 TASK: zerosum
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool memo[10][12346];
int sz, lim = 0;
int n;

vector<string> paths;
bool DP(int i, int res,string path) {
	bool &m = memo[i][res];
	if (i == n){
		if(res==0){
		paths.push_back(path);
		return 1;
		}
		return 0;
	}

	if (res > lim)
		return m = 0;

	if (m == 0)
		return 0;

	int count = 0;
	string tmp;
	tmp += ((i+1) +'0');
	count += DP(i + 1, res + i + 1, path+"+"+tmp);
	count += DP(i + 1, res - (i + 1), path + "-" +tmp);
	if(i+2<=n){
		tmp.clear();
		tmp += (i+1)+'0';
		tmp += " " , tmp += (i+2)+'0';
		count += DP(i+2, res + ((i+1)*10)+i+2, path +"+"+tmp);
		count += DP(i+2, res - (((i+1)*10)+i+2) , path +"-"+tmp);
	}

	return m = count;
}
int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 12346; j++)
			memo[i][j] = 1;

	sz = (n % 2 == 0) ? n / 2 : (n + 1) / 2;

	for (int i = 1; i <= sz; i++)
		lim = lim * 10 + i;

	 DP(1, 1,"1");
	 DP(2,12,"1 2");

	 sort(paths.begin(), paths.end());
	 for(int i=0; i<paths.size(); i++)
		 cout<<paths[i]<<endl;



	return 0;
}
