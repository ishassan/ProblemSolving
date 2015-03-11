#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
const int MAX = 15;
int OO = 67108864;
int adjMax[MAX][MAX];
int prev[MAX][MAX];
#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
void show(int i, int j) {
	if (prev[i][j] == 0)
		cout << " " << i;
	else {
		show(i, prev[i][j]);
		show(prev[i][j], j);
	}
}
void floydWarshal(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prev[i][j] = 0;
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (adjMax[i][j] > adjMax[i][k] + adjMax[k][j])
					adjMax[i][j] = adjMax[i][k] + adjMax[k][j], prev[i][j] = k;
			}
		}
	}
}
int main() {
	int n;
	int count = 1;
	while (cin >> n) {
		memset(prev, -1, sizeof(prev));
		int from, dis;
		if (n == 0)
			return 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				adjMax[i][j] = OO;
			}
		}
		int st;
		for (int i = 1; i <= n; i++) {
			cin >> st;
			int to, del;
			for (int j = 1; j <= st; j++) {
				cin >> to >> del;
				adjMax[i][to] = del;

			}
		}
		cin >> from >> dis;
		if (from == dis) {
			cout << "Case " << count++ << ": Path =" << " " << dis << " "
					<< dis << ";" << " 0 second delay" << endl;
			continue;
		}

		floydWarshal(n);
		cout << "Case " << count++ << ": Path =";
		show(from, dis);
		cout << " " << dis;
		cout << ";" << " ";
		cout << adjMax[from][dis] << " second delay" << endl;

	}
	return 0;
}
