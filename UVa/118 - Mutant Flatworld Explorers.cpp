#include<iostream>
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct pos {
	int x;
	int y;
	char to;

};
int ret(char pos, char dis[]) {
	for (int i = 0; i < 4; i++)
		if (dis[i] == pos)
			return i;
}
int main() {
	int col, row;
	bool islost = false;
	cin >> col >> row;
	char dis[] = { 'E', 'S', 'W', 'N' };
	vector<vector<bool> > lost(row + 1, vector<bool> (col + 1));
	for (int i = 0; i <= row; i++)
		for (int j = 0; j <= col; j++)
			lost[i][j] = 0;
	pos p;
	while (cin >> p.x >> p.y >> p.to) {
		string mov;
		cin >> mov;
		int ind;
		ind = ret(p.to, dis);
		for (int i = 0; i < mov.size(); i++) {
			if (mov[i] == 'R') {
				ind++;
				if (ind > 3)
					ind = 0;
				p.to = dis[ind];
			} else if (mov[i] == 'L') {
				ind--;
				if (ind < 0)
					ind = 3;
				p.to = dis[ind];
			} else { //F
				if (p.to == 'E')
					p.x++;
				else if (p.to == 'S')
					p.y--;
				else if (p.to == 'W')
					p.x--;
				else
					p.y++;

				if (p.y > row) {
					p.y--;
					if (lost[p.x][p.y] == 0) {//first lost
						cout << p.x << " " << p.y << " " << p.to << " LOST"
								<< endl;
						lost[p.x][p.y] = 1;
						islost = 1;
						break;
					}
				} else if (p.y < 0) {
					p.y++;
					if (lost[p.x][p.y] == 0) {//first lost
						cout << p.x << " " << p.y << " " << p.to << " LOST"
								<< endl;
						lost[p.x][p.y] = 1;
						islost = 1;
						break;
					}

				}

				if (p.x > col) {
					p.x--;
					if (lost[p.x][p.y] == 0) {//first lost
						cout << p.x << " " << p.y << " " << p.to << " LOST"
								<< endl;
						lost[p.x][p.y] = 1;
						islost = 1;
						break;
					}

				} else if (p.x < 0) {
					p.x++;
					if (lost[p.x][p.y] == 0) {//first lost
						cout << p.x << " " << p.y << " " << p.to << " LOST"
								<< endl;
						lost[p.x][p.y] = 1;
						islost = 1;
						break;
					}

				}

			}

		}
		if (islost) {
			islost = 0;
			continue;
		}
		cout << p.x << " " << p.y << " " << p.to << endl;
	}
	return 0;
}
