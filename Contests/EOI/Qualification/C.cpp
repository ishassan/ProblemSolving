#include <iostream>

using namespace std;
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)

int chess[9][9];

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int main() {

	fo(i,8)
		fo(j,8)
			cin >> chess[i][j];

	int ret =0;
	fo(i,8)
		fo(j,8) {
			if (chess[i][j] == 1) {
				fo(k,4) {
					int newi = i + di[k];
					int newj = j + dj[k];

					if (newi < 0)
						newi = 7;
					if (newi > 7)
						newi = 0;

					if (newj < 0)
						newj = 7;
					if (newj > 7)
						newj = 0;


					if(chess[newi][newj]==0)
					{
						ret++;
						break;
					}
				}
			}
		}

	cout<<ret<<endl;
	return 0;
}
