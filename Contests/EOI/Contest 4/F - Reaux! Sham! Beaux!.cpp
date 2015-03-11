#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <ctype.h>
#include <cmath>
#include <queue>

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
typedef long long ll;
using namespace std;

string code[10] = { "cs", "en", "fr", "de", "hu", "it", "jp", "pl", "es" };
string rock[10] = { "Kamen", "Rock", "Pierre", "Stein", "Ko", "Sasso", "Guu",
		"Kamien", "Piedra" };
string rock2[10] = { "Kamen", "Rock", "Pierre", "Stein", "Koe", "Roccia",
		"Guu", "Kamien", "Piedra" };
string sci[10] = { "Nuzky", "Scissors", "Ciseaux", "Schere", "Ollo", "Forbice",
		"Choki", "Nozyce", "Tijera" };
string sci2[10] = { "Nuzky", "Scissors", "Ciseaux", "Schere", "Olloo",
		"Forbice", "Choki", "Nozyce", "Tijera" };
string pap[10] = { "Papir", "Paper", "Feuille", "Papier", "Papir", "Carta",
		"Paa", "Papier", "Papel" };
string pap2[10] = { "Papir", "Paper", "Feuille", "Papier", "Papir", "Rete",
		"Paa", "Papier", "Papel" };
int main() {
	map<string, string> mp;
	map<string, int> index;
	fo(i,10) {
		mp[rock[i]] = "rock";
		mp[rock2[i]] = "rock";
		mp[sci[i]] = "sci";
		mp[sci2[i]] = "sci";
		mp[pap[i]] = "pap";
		mp[pap2[i]] = "pap";
		index[code[i]] = i;
	}
	string strc, name, strc2, name2;
	int tst = 1;
	while (cin >> strc) {
		if (strc == ".")
			break;
		cin >> name >> strc2 >> name2;

		string p1, p2;
		int score1 = 0, score2 = 0;
		while (cin >> p1) {
			if (p1 == "-" || p1 == ".")
				break;
			cin >> p2;

			string r1 = mp[p1], r2 = mp[p2];
			if (r1 == "rock") {
				if (r2 == "sci")
					score1++;
				else if (r2 == "pap")
					score2++;
			}

			else if (r1 == "sci") {
				if (r2 == "rock")
					score2++;
				else if (r2 == "pap")
					score1++;
			}

			else if (r1 == "pap") {
				if (r2 == "rock")
					score1++;
				else if (r2 == "sci")
					score2++;
			}

		}

		cout << "Game #" << tst++ << ":\n";
		cout << name << ": " << score1;
		if (score1 == 1)
			cout << " point\n";
		else
			cout << " points\n";
		cout << name2 << ": " << score2;
		if (score2 == 1)
			cout << " point\n";
		else
			cout << " points\n";

		if (score1 == score2)
			cout << "TIED GAME\n";
		else {
			cout << "WINNER: ";
			if (score1 > score2)
				cout << name << endl;
			else
				cout << name2 << endl;
		}
		cout<<endl;
		if (p1 == ".")
			break;

	}

	return 0;
}
