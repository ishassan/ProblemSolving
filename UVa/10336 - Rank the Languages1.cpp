//UVa 10336, FloodFill connected component
//http://www.codecodex.com/wiki/index.php?title=Implementing_the_flood_fill_algorithm#C
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
#include <stack>
#include <ctime>
using namespace std;

void floodFill(vector<string> v, bool** vis, int y, int x, char cur) {

	if (vis[y][x])
		return;

	int left = x, right = x;

	//search right side
	while (1) {
		vis[y][right] = 1;
		right++;

		if (right >= v[y].length() || v[y][right] != cur) {
			right--;
			break;
		}
	}

	//search left side
	while (1) {
		vis[y][left] = 1;
		left--;

		if (left < 0 || v[y][left] != cur) {
			left++;
			break;
		}
	}

	//search top & bottm side
	for (int i = left; i <= right; i++) {

		if (y > 0 && v[y - 1][i] == cur)
			floodFill(v, vis, y - 1, i, cur);

		if (y < v.size() - 1 && v[y + 1][i] == cur)
			floodFill(v, vis, y + 1, i, cur);
	}

}

void sort(vector<pair<int, char> >& vp) {

	pair<int, char> temp;

	for (int i = 0; i < vp.size(); i++)
		for (int j = i + 1; j < vp.size(); j++) {
			if (vp[i].first < vp[j].first) {
				temp = vp[i];
				vp[i] = vp[j];
				vp[j] = temp;
			}

			else if (vp[i].first == vp[j].first)
				if (vp[i].second > vp[j].second) {
					temp = vp[i];
					vp[i] = vp[j];
					vp[j] = temp;
				}
		}
}
int main() {

	int n, h, w;
	vector<string> in;
	vector<pair<int, char> > res;

	char cur;

	pair<int, char> p;

	string str;
	bool** vis;

	map<char, int> m;


	cin >> n;

	for (int a = 0; a < n; a++) {

		cin >> h >> w;

		//initialize map m with 0
		for (char c = 'a'; c <= 'z'; c++)
				m[c] = 0;

		for (int j = 0; j < h; j++) {
			cin >> str;
			in.push_back(str);
		}

		vis = new bool*[h];
		for (int i = 0; i < h; i++) {
			vis[i] = new bool[w];

			for (int j = 0; j < w; j++)
				vis[i][j] = 0;
		}

		//implement floodFill
		for (int y = 0; y < in.size(); y++) {

			for (int x = 0; x < in[y].size(); x++) {

				if (vis[y][x])
					continue;

				cur = in[y][x];
				floodFill(in, vis, y, x, cur);
				m[cur]++;

			}
		}

		//storing and sorting results in pair
		for (char c = 'a'; c <= 'z'; c++) {
			if (m[c] != 0) {
				p.first = m[c];
				p.second = c;
				res.push_back(p);
			}
		}

		sort(res);

		//Output
		cout<<"World #"<<a+1<<endl;
		for(int i=0; i<res.size(); i++)
			cout<<res[i].second<<": "<<res[i].first<<endl;

		//delete array vis
		for (int i = 0; i < h; i++)
			delete vis[i];

		delete vis;

		in.erase(in.begin(), in.end());
		res.erase(res.begin(),res.end());
	}
	return 0;

}

