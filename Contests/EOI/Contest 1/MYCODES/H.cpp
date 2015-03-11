#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

int main() {

	string path;
	while (getline(cin, path)) {
		string name = path, ext;
		int i, last = -1;
		bool dot = 0;
		for (i = path.size() - 1; i > -1; i--) {
			if (path[i] == '.' && !dot) {
				dot = 1;
				ext = path.substr(i + 1, path.size() - i);
				last = i;
			}

			if (path[i] == '\\') {
				if (last == -1)
					name = path.substr(i + 1, path.size() - i);
				else
					name = path.substr(i + 1, last - i - 1);
				last = i;
				break;
			}
		}

		if (ext == "inv") {
			ext = ".exe";
			reverse(name.begin(), name.end());
			cout << "ren " << path << " " << path.substr(0, last + 1) << name
					<< ext << endl;
		}

		else if (ext == "shf") {
			ext = ".dll";
			name = name[name.size() - 1] + name;
			name.erase(name.size() - 1, 1);
			cout << "ren " << path << " " << path.substr(0, last + 1) << name
					<< ext << endl;
		} else
			cout<<"correct\n";

	}

	return 0;
}
