//UVa 439, Search(src, dest, moves), find all pathes and minimize. Or use BFS

#include <map>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
using namespace std;


void addNodes(queue<string>& q, string src) {

	string temp = src;

	if (temp[0] < 'h' && temp[1] < '7') {
		temp[0]++;
		temp[1] += 2;
		q.push(temp);
		temp = src;
	}

	if (temp[0] < 'h' && temp[1] > '2') {
		temp[0]++;
		temp[1] -= 2;
		q.push(temp);
		temp = src;
	}

	if (temp[0] < 'g' && temp[1] < '8') {
		temp[0] += 2;
		temp[1]++;
		q.push(temp);
		temp = src;
	}

	if (temp[0] < 'g' && temp[1] > '1') {
		temp[0] += 2;
		temp[1]--;
		q.push(temp);
		temp = src;
	}

	if (temp[0] > 'a' && temp[1] > '2') {
		temp[0]--;
		temp[1] -= 2;
		q.push(temp);
		temp = src;
	}

	if (temp[0] > 'a' && temp[1] < '7') {
		temp[0]--;
		temp[1] += 2;
		q.push(temp);
		temp = src;
	}

	if (temp[0] > 'b' && temp[1] > '1') {
		temp[0] -= 2;
		temp[1]--;
		q.push(temp);
		temp = src;
	}

	if (temp[0] > 'b' && temp[1] < '8') {
		temp[0] -= 2;
		temp[1]++;
		q.push(temp);
		temp = src;
	}

}
int main() {

	string str, src, dest;

	while (getline(cin, str)) {

		queue<string> q;
		bool vis[8][8] = { 0 };
		int depth = 0;

		src = str.substr(0, 2);
		dest = str.substr(3, 2);

		if(src==dest)
			goto out;

		int x, y;
		x = src[0] - 'a';
		y = src[1] - '1';

		vis[x][y] = 1;

		addNodes(q, src);

		while (q.size()) {

			int size = q.size();
			depth++;
			while (size--) {
				string nxl = q.front();
				q.pop();


				if (nxl == dest) {
					goto out;
				}

				x = nxl[0] - 'a';
				y = nxl[1] - '1';
				if (!vis[x][y]){
					addNodes(q, nxl);
					vis[x][y]=1;
				}
			}

		}

		out:
		cout <<"To get from "<<src<<" to "<<dest<<" takes "<<depth<<" knight moves.\n";

	}

	return 0;

}

