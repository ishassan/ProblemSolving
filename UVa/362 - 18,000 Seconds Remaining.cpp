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
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;


int main() {

	//freopen("out.txt","w",stdout);
	int filesize;
	int dataset = 1;

	while (cin >> filesize) {
		if (filesize == 0)
			return 0;
		vi data;
		int bytes = 0;
		int num;
		while (filesize - bytes > 0) {
			cin >> num;
			data.push_back(num);
			bytes += num;
		}

		cout << "Output for data set " << dataset++ << ", " << filesize
				<< " bytes:" << endl;
		int totaltime = data.size();
		int filesizee = filesize;
		while (data.size() >= 5) {
			int sum = 0;
			fo(i,5)
				sum += data[i];
			int c = 5;
			while (data.size() >= 5 && c--)
				data.erase(data.begin());

			if (sum == 0) {
				cout << "   Time remaining: " << "stalled" << endl;
				continue;
			}

			filesizee -= sum;
			if (filesizee == 0) {
				cout << "   Time remaining: 0 seconds" << endl;
				continue;
			}

			double ret =  filesizee / (sum / 5.0);
			cout << "   Time remaining: " << ceil(ret-1e-9) << " seconds" << endl;
		}
		cout << "Total time: " << totaltime << " seconds" << endl<<endl;
	}
	return 0;
}
