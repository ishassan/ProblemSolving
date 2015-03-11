/*
 ID: fci_isl1
 LANG: C++
 PROB: transform
 */

#include <iostream>
#include <string>
using namespace std;

char in[11][11];
char out[11][11];
char proc1[11][11];
char proc2[11][11];
int n;

bool equal(char arr1[][11], char arr2[][11]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr1[i][j] != arr2[i][j])
				return 0;
	return 1;

}

void rotate(char dest[][11], char src[][11]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dest[i][j] = src[n - j - 1][i];
}

void reflect(char dest[][11], char src[][11]) {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dest[i][n-j-1] = src[i][j];
}

int main() {

	freopen("transform.in", "r", stdin);
	freopen("transform.out","w",stdout);


	cin >> n;

	for (int i = 0; i < n; i++)
		scanf("%s", in[i]);

	for (int i = 0; i < n; i++)
		scanf("%s", out[i]);

	rotate(proc1, in);

	if (equal(proc1, out)) {
		cout << 1 << endl;
		return 0;
	}

	rotate(proc2, proc1);

	if (equal(proc2, out)) {
		cout << 2 << endl;
		return 0;
	}

	rotate(proc1, proc2);

	if (equal(proc1, out)) {
		cout << 3 << endl;
		return 0;
	}

	reflect(proc1, in);
	if (equal(proc1, out)) {
		cout << 4 << endl;
		return 0;
	}

	//reflect, rot 90
	rotate(proc2, proc1);
	if (equal(proc2, out)) {
		cout << 5 << endl;
		return 0;
	}

	//ref, rot 180
	rotate(proc1, proc2);
	if (equal(proc1, out)) {
		cout << 5 << endl;
		return 0;
	}

	//ref, rot 270
	rotate(proc2, proc1);
	if (equal(proc2, out)) {
		cout << 5 << endl;
		return 0;
	}

	if (equal(in, out)) {
		cout << 6 << endl;
		return 0;
	}

	cout << 7 << endl;

	return 0;
}
