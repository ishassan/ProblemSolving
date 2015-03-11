/*
 ID: fci_isl1
 LANG: C++
 TASK: numtri
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
inline int max(int a,int b){
	return (a>b)? a : b;
}

int main() {
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);

	int row,num;
	cin >> row;

	vector<vector<int> > tri(row);

	for (int i = 0; i < row; i++)
		for (int j = 0; j <= i; j++)
			cin >> num, tri[i].push_back(num);

	for(int i = row-2; i>-1; i--){
		for(int j=0; j<=i; j++){
			tri[i][j] += max(tri[i+1][j] , tri[i+1][j+1]);
		}
	}

	cout << tri[0][0]<<endl;

	return 0;
}
