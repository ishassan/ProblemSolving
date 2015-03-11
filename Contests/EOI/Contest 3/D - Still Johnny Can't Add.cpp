#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <numeric>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

int grid[15][15];
int main() {

	int tst;
	cin >> tst;
	foe(t,1,tst) {
		memset(grid, -1, sizeof grid);
		int n;
		cin >> n;
		foe(i,1,n)
			foe(j,1,n)
				cin >> grid[i][j];

		cout << t << ". ";
		int start = grid[1][1];
		bool b = 0;
		foe(i,0,n) {
			grid[0][1] = i;
			grid[1][0] = start - i;
			for (int r = 1; r <= n; r++) {
				for (int c = 1; c <= n; c++) {
					if (grid[0][c] != -1 && grid[r][0] != -1) {
						if (grid[r][c] != grid[r][0] + grid[0][c])
							goto end;
					}

					else if (grid[0][c] == -1)
						grid[0][c] = grid[r][c] - grid[r][0];

					else if (grid[r][0] == -1)
						grid[r][0] = grid[r][c] - grid[0][c];
				}
			}

			b = 1;
			break;

			end: ;

		}
		if (b)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
