#include<iostream>
#include<string>
using namespace std;
char mat[84000][6];
char in[50];
unsigned long i, j, k, l, z;
unsigned long n = 0;
int main() {
	for (i = 0; i < 26; i++) {
		mat[n][0] = 'a' + i;
		n++;
	}

	for (i = 0; i < 25; i++) {
		for (j = i + 1; j < 26; j++) {
			mat[n][0] = 'a' + i;
			mat[n][1] = 'a' + j;
			n++;
		}
	}

	for (i = 0; i < 24; i++) {
		for (j = i + 1; j < 25; j++) {
			for (k = j + 1; k < 26; k++) {
				mat[n][0] = 'a' + i;
				mat[n][1] = 'a' + j;
				mat[n][2] = 'a' + k;
				n++;
			}
		}
	}

	for (i = 0; i < 23; i++) {
		for (j = i + 1; j < 24; j++) {
			for (k = j + 1; k < 25; k++) {
				for (l = k + 1; l < 26; l++) {
					mat[n][0] = 'a' + i;
					mat[n][1] = 'a' + j;
					mat[n][2] = 'a' + k;
					mat[n][3] = 'a' + l;
					n++;
				}
			}
		}
	}

	for (i = 0; i < 22; i++) {
		for (j = i + 1; j < 23; j++) {
			for (k = j + 1; k < 24; k++) {
				for (l = k + 1; l < 25; l++) {
					for (z = l + 1; z < 26; z++) {
						mat[n][0] = 'a' + i;
						mat[n][1] = 'a' + j;
						mat[n][2] = 'a' + k;
						mat[n][3] = 'a' + l;
						mat[n][4] = 'a' + z;
						n++;
					}
				}
			}
		}
	}

	string temp;
	while (cin >> temp) {
		for (int h = 0; h <= temp.size(); h++)
			in[h] = temp[h];
		int count = 0;
		for (i = 0; i < n; i++) {
			if (strcmp(in, mat[i]) == 0)//0 means equll or not difrrent
			{
				cout << i + 1 << endl;
				count = 1;
			}
		}
		if (count == 0)
			cout << 0 << endl;
	}
	return 0;
}
