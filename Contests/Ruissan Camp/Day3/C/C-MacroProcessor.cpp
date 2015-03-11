#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define SZ(v)					(int)v.size()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n) 		        for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int OO = (int) 2e9;
const double PI = 2 * acos(0);
const double EPS = 1e-9;

map<string, string> func_body;
map<string, vs> par;
set<string> allMacros;

void split(string str, string delim, vector<string>& res) {
	for (int i = 0; i < SZ(str); i++)
		for (int j = 0; j < SZ(delim); j++)
			if (str[i] == delim[j])
				str[i] = ' ';
	stringstream ss(str);
	while (ss >> str)
		res.push_back(str);
}

void relax(string macroLine) { //deal with macro
	stringstream ss;
	string func_name, tmp, a;
	ss << macroLine, ss >> func_name >> tmp >> a;
	allMacros.insert(func_name);
	vs splitArgs;
	split(a, ",", splitArgs);
	par[func_name] = splitArgs;
	string ret = "";
	while (getline(cin, macroLine)) {
		if ((int) macroLine.find("endm", 0) != -1) {
			func_body[func_name] = ret;
			return;
		}
		ret += macroLine + "\n";
	}
}

string editBody(string macroName, string macroArgs) {
	vs splitArgs;
	split(macroArgs, ",", splitArgs);
	string body = func_body[macroName];
	for (int i = 0; i < SZ(par[macroName]); ++i) {
		while (true) {
			int pos = body.find(par[macroName][i], 0);
			if (pos == -1)
				break;
			body.replace(body.begin() + pos, body.begin() + pos
					+ par[macroName][i].size(), splitArgs[i].begin(),
					splitArgs[i].end());
		}
	}
	return body;
}
int main() {
	freopen("macropr.in", "r", stdin);
	freopen("macropr.out", "w", stdout);

	int nc;
	cin >> nc;
	string dumm;
	getline(cin, dumm);
	for (int tt = 1; tt <= nc; tt++) {
		par.clear();
		func_body.clear();
		allMacros.clear();
		printf("Case #%d:\n", tt);
		string in;
		while (getline(cin, in)) {
			vs splitLine;
			split(in, " ", splitLine);

			if ((int) in.find("end", 0) != -1) {
				cout << in << endl;
				break;
			}

			if ((int) in.find("macro", 0) != -1)
				relax(in);

			else if (splitLine.size() > 0 && allMacros.find(splitLine[0])
					!= allMacros.end()) {
				cout << ";" << in << endl;
				vs splitCall;
				split(in, "", splitCall);
				in = editBody(splitCall[0], splitCall[1]);
				cout << in;
			} else
				cout << in << endl;
		}
	}
	return 0;
}
