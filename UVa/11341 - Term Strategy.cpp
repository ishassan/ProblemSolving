#include<iostream>
#include<vector>
using namespace std;

const int N = 12, M = 102;
int mat[N][M];
int memo[N][M];
int n, m;

int score(int courseId, int reminderTime) {
	if (courseId == n)
		return 0;

	if(memo[courseId][reminderTime]!= -1)
		return memo[courseId][reminderTime];

	int maxScore=-1;

	for (int j = 0; j < m; j++) {
		if (j + 1 > reminderTime || mat[courseId][j] < 5)
			continue;

		maxScore = max(maxScore,mat[courseId][j] + score(courseId + 1, reminderTime - (j + 1)));
	}

	return memo[courseId][reminderTime] = maxScore;
}
int main() {
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif

	int tst;
	cin >> tst;
	while (tst--) {
		cin >> n >> m;

		memset(mat,-1,sizeof mat);

		bool fail = 0;

		for (int i = 0; i < n; i++) {
			int mx = -2;

			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];

				if (mx < mat[i][j])
					mx = mat[i][j];
			}

			if (mx < 5) {
				printf("Peter, you shouldn't have played billiard that much.\n");
				fail = 1;
				break;
			}
		}
		if (fail)
			continue;

		memset(memo, -1, sizeof(memo));

		double res = (double) score(0, m) / n;

		if (res >= 5.0)
			printf("Maximal possible average mark - %.2lf.\n",res+1e-9);

		else
			printf("Peter, you shouldn't have played billiard that much.\n");
	}
	return 0;
}
