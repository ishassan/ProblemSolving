/*
 ID: fci_isl1
 LANG: C++
 TASK: lamps
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n;
bool on[101], off[101];
set<string> sol;

string apply(string str, int but) {

	if (but == 1)
		for (int j = 0; j < n; j++)
			str[j] = (!(str[j] - '0')) + '0';

	else if (but == 2)
		for (int j = 0; j < n; j += 2)
			str[j] = (!(str[j] - '0')) + '0';

	else if (but == 3)
		for (int j = 1; j < n; j += 2)
			str[j] = (!(str[j] - '0')) + '0';

	else
		for (int j = 0; j < n; j += 3)
			str[j] = (!(str[j] - '0')) + '0';
	return str;
}

int main() {
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);

	int c,in;
	cin >> n >> c;
	string str;
	while (cin >> in) {
		if (in == -1)
			break;
		on[in] = 1;
	}

	while (cin >> in) {
		if (in == -1)
			break;
		off[in] = 1;
	}
	for (int i = 0; i < n; i++)
		str += "1";

if(c==0){
         for(int i=0; i<str.size(); i++){
                 if(str[i]=='1' &&  off[i+1]){
                                cout<<"IMPOSSIBLE"<<endl;
                                return 0;
                 }
                 if(str[i]=='0' &&  on[i+1]){
                                cout<<"IMPOSSIBLE"<<endl;
                                return 0;
                 }
                 cout<<str<<endl;
                 return 0;
         }
         }
	for (int i = 1; i < 5; i++) {
		string temp = apply(str, i);
		sol.insert(temp);
		if(c>1)
		sol.insert(apply(temp, 4));
	}


	vector<string> v(sol.begin(), sol.end());


	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == '1' && off[j+1]){
				v.erase(v.begin() + i);
				i--;
				break;
			}
			if (v[i][j] == '0' && on[j+1]){
				v.erase(v.begin() + i);
				i--;
				break;
			}
		}

if(v.size()==0){
                  cout<<"IMPOSSIBLE"<<endl;
                  return 0;
                  }
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
