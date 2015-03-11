#include <stdio.h>
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
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

vs graph(5);

void display() {
	fo(a,5) {
		fo(b,5) {
			cout << graph[a][b];
			if (b < 4)
				cout << " ";
		}

		cout << endl;
	}
}

int main() {

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	map<char, pair<int, int> > m;
	m['A'] = make_pair(-1, 0);
	m['B'] = make_pair(1, 0);
	m['R'] = make_pair(0, 1);
	m['L'] = make_pair(0, -1);

	int counter = 1;
	string ln;
	bool start = 1;
	while (getline(cin, ln)) {
		if (ln == "Z")
			return 0;

		if (start)
			start = 0;
		else
			cout << endl;

		//loading graph
		graph[0] = ln;
		foo(i,1,5) {
			getline(cin, ln);
			graph[i] = ln;
		}

		//specify coordinates of the empty square
		int r, c;
		fo(i,5)
			fo(j,5)
				if (graph[i][j] == ' ') {
					r = i;
					c = j;
					goto skip;
				}

		skip: ;

		bool bad = 0;
		char ch;
		while (cin >> ch) {

			if (ch == '0' && bad)
				break;
			if (bad)
				continue;

			if (ch == '0') {
				cout << "Puzzle #" << counter++ << ":\n";
				display();
				goto end;
			}

			int nr = r + m[ch].first;
			int nc = c + m[ch].second;

			if (nr < 0 || nc < 0 || nr > 4 || nc > 4) {
				cout << "Puzzle #" << counter++
						<< ":\nThis puzzle has no final configuration.\n";
				bad = 1;
				continue;
			}

			graph[r][c] = graph[nr][nc];
			graph[nr][nc] = ' ';
			r = nr, c = nc;

		}

		end: ;

		getline(cin, ln);
	}
	return 0;
}
