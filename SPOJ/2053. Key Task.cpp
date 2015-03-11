//SPOJ CERC07K
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

//for seeking the four directions
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

void copyArr(bool src[], bool dest[]){

	for(int i=0; i<26; i++)
		dest[i]=src[i];
}

struct point {

	int srcR, srcC;

	bool keys[26];

	point(){
		memset(keys,0,26);
	}

};

int main() {

	int r, c;
	int srcR, srcC;

	while (1) {

		cin >> r >> c;

		if (r == 0 && c == 0)
			break;

		bool found = 0;
		vector<string> graph(r);
		bool vis[182][182][2][2][2][2] = {0};	//vis[row][col][b][g][r][y]

		for (int i = 0; i < r; i++)
			cin >> graph[i];

		//search for 'X'
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (graph[i][j] == 'X') {
					found = 1;
					break;
				}
			}
			if (found)
				break;
		}

		if (!found) {
			cout << "The poor student is trapped!\n";
			continue;
		}

		found = 0;

		//search for '*'
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (graph[i][j] == '*') {
					srcR = i;
					srcC = j;
					vis[srcR][srcC][0][0][0][0] = 1;
					found = 1;
					break;
				}
			}

			if (found)
				break;
		}

		found = 0;

		//BFS
		point pnt;
		pnt.srcR = srcR;
		pnt.srcC = srcC;


		queue<point> q;
		q.push(pnt);

		int steps = 0;
		int newR, newC;
		char cur, next;
		bool keys[26]={0};

		while (q.size()) {

			int size = q.size();

			while (size--) {

				srcR = q.front().srcR;
				srcC = q.front().srcC;
				copyArr(q.front().keys,keys);

				q.pop();
				cur = graph[srcR][srcC];

				if (cur == 'X') {
					found = 1;
					break;
				}

				else if (cur == 'b' || cur == 'r' || cur == 'y' || cur == 'g') {
					keys[cur-'a']=1;
					//b = 1, g=6, r=17, y=24
					vis[srcR][srcC][keys[1]][keys[6]][keys[17]][keys[24]]=1;
				}

				for (int i = 0; i < 4; i++) {
					newR = srcR + dr[i];
					newC = srcC + dc[i];

					if (newR < 0 || newR >= r || newC < 0 || newC >= c)
						continue;

					next = graph[newR][newC];

					if (vis[newR][newC][keys[1]][keys[6]][keys[17]][keys[24]] == 1 || next == '#')
						continue;

					else if (next == 'B' || next == 'R' || next == 'Y' || next
							== 'G') {
						if (keys[next-'A']==0)
							continue;

					}

					pnt.srcR = newR;
					pnt.srcC = newC;
					copyArr(keys,pnt.keys);

					q.push(pnt);

					vis[newR][newC][keys[1]][keys[6]][keys[17]][keys[24]]=1;
				}

			}

			if (found)
				break;

			steps++;

		}

		if (found == 0)
			cout << "The poor student is trapped!\n";

		else
			cout << "Escape possible in " << steps << " steps.\n";

		found = 0;
	}
	return 0;
}
