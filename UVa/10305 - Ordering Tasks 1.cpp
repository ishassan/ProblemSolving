//UVa 10305, Topological Sort
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
#include <stack>
#include <ctime>
using namespace std;

void test(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

void test(bool arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

void test(int** arr, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}
}

void test(bool** arr, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}
}
int main() {

	int n, m, num1, num2, x = 0, y = 0;
	vector<int> select;

	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		//Declaring a dynamic array
		int** input = new int*[m];
		bool** children = new bool*[n];

		int* inDeg = new int[n];
		bool* vis = new bool[n];

		//setup input
		for (int i = 0; i < m; i++)
			input[i] = new int[2];

		//setup children
		for (int i = 0; i < n; i++) {
			children[i] = new bool[n];

			for (int j = 0; j < n; j++) { //initialize arr[i] with 0

				children[i][j] = 0;
			}
		}

		//initialize vis&inDeg with 0
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
			inDeg[i] = 0;
		}
		//storing the input in an array
		for (int i = 0; i < m; i++) {
			cin >> num1 >> num2;

			input[i][0] = num1;
			input[i][1] = num2;
		}

		//calculate inDeg & children values

		for (int i = 0; i < m; i++) {
			x = input[i][0] - 1;
			y = input[i][1] - 1;
			children[x][y] = 1;

			inDeg[y]++;
		}

		//Topological sorting
		for (int i = 0; i < n; i++) {

			select.erase(select.begin(), select.end());
			for (int j = 0; j < n; j++) {
				if (vis[j] == 0 && inDeg[j] == 0) {
					select.push_back(j);
					cout << j + 1 << " ";
					vis[j] = 1;
				}
			}

			//remove edges that connect it with its children
			for (int s = 0; s < select.size(); s++) {
				for (int k = 0; k < n; k++) {
					x = select[s];
					if (children[x][k] == 1) {
						inDeg[k]--;
					}
				}
			}

		}
	}
	return 0;

}

