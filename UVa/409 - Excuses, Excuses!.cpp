#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
vs srch;
vector<pair<int, int> > ans;
void lineToWords(string line, int ind) {
	fo(i,line.size())
		line[i] = tolower(line[i]);
	vs words;
	string str;
	fo(i,line.size()) {
		if (!isalnum(line[i])) {
			words.push_back(str);
			str.clear();
		} else
			str += line[i];

	}
	words.push_back(str);
	int count = 0;
	fo(i,srch.size()) {
		for (int j = 0; j < words.size(); j++)
			if (srch[i] == words[j])
				count++;
	}
	ans.push_back(make_pair(count, ind));
}
int main() {
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	int s, d;
	int c = 1;
	string dumm;
	while (cin>>s>>d) {
		string tmp;
		vs b_data;
		srch.clear();
		ans.clear();
		while (s--) {
			cin >> tmp;
			srch.push_back(tmp);
		}
		getline(cin,dumm);
		while (d--) {
			getline(cin,tmp);
			b_data.push_back(tmp);
		}
		fo(i,b_data.size())
			lineToWords(b_data[i], i);
		int worst = -100000000;
		fo(i,ans.size())
			if (worst < ans[i].first)
				worst = ans[i].first;
		cout << "Excuse Set #" << c++ << endl;
		fo(i,ans.size())
			if (worst == ans[i].first) {
				int ind = ans[i].second;
				cout << b_data[ind] << endl;
			}
		cout << endl;
	}
	return 0;

}
