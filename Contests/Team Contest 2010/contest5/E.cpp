#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
#define MAX 150
vector<string> data;

int toI(string b) {
	int x = 0, y = 1;
	for (int i = b.size() - 1; i >= 0; i--)
		x += (y * (b[i] - '0')), y *= 2;
	return x;
}

string decode(string code) {
	string decoded = "";
	while (code.size()) {
		int x = toI(code.substr(0, 5));
		code = code.substr(5);
		if (x < 26)
			decoded += char('a' + x);
		else if (x == 26)
			decoded += "_";
		else if (x == 27)
			decoded += "/";
		else if (x == 28)
			decoded += ":";
		else if (x == 29)
			decoded += ".";
		else if (x == 30)
			decoded += "!";
		else if (x == 31)
			decoded += "?";
	}
	//cout << decoded << endl;
	return decoded;
}

string check(int i, int j, vector<string> s) {
	if ((s.size() + i) > data.size() || s[0].size() + j > data[0].size())
		return "";
	string code = "";
	for (int k = 0; k < 7; k++) {
		for (int l = 0; l < 9; l++) {
			if (s[k][l] == '-')
				code += data[i + k][j + l];
			else if (s[k][l] != data[i + k][j + l]) {
				return "";
			}
		}
	}
	//	cout << i << " " << j << " " << s[0]<<" "<<data[i] << endl;

	return decode(code);
}

vector<string> rotate(vector<string> v) {

	vector<string> res;
	for (int i = 0; i < v[0].size(); ++i) {
		string tmp = "";
		for (int j = v.size() - 1; j >= 0; --j) {
			tmp += v[j][i];
		}

		res.push_back(tmp);
	}
	return res;

}

int main() {

	freopen("E.in", "r", stdin);
	vector<string> s;
	s.push_back("1010---01");
	s.push_back("1000---00");
	s.push_back("10-------");
	s.push_back("10-------");
	s.push_back("10-------");
	s.push_back("1000---00");
	s.push_back("101000001");

	int N, H, W;
	string decoded;
	cin >> N;
	while (N--) {
		decoded = "";
		data.clear();
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			string str;
			cin >> str;
			data.push_back(str);
		}
		for (int i = 0; i < 4; i++) {
			{
				for (int i = 0; i < H; i++)
					for (int j = 0; j < W; j++) {
						string sol = check(i, j, s);
						if (sol != "") {
							if (decoded != "") {
								decoded = "INTERFERENCE";
								i = H, j = W;
							} else
								decoded = sol;
						}
					}
			}
			data = rotate(data);
		}
		if (decoded == "")
			cout << "NOCODE" << endl;
		else
			cout << decoded << endl;
	}

}
