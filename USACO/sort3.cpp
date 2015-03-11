/*
 ID: fci_isl1
 LANG: C++
 TASK: sort3
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int arr[1001];
int n;

int main() {

	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int s1 = 0, s2 = 0, s3 = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] == 1)
			s1++;
		else if (arr[i] == 2)
			s2++; //:D
		else if (arr[i] == 3)
			s3++;
	}

	//start positions
	s3 = s1 + s2;
	s2 = s1;
	s1 = 0;
	int res = 0;
	for (int i = s1; i < s2; i++) {
		if (arr[i] == 1)
			continue;

		bool found = 0;
		if (arr[i] == 2) {
			for (int j = s2; j < s3; j++)
				if (arr[j] == 1) {
					swap(arr[i], arr[j]), res++, found = 1;
					break;
				}
			if (!found)
				for (int j = s3; j < n; j++)
					if (arr[j] == 1) {
						swap(arr[i], arr[j]), res++;
						break;
					}
		}

		else if (arr[i] == 3) {
			for (int j = s3; j < n; j++)
				if (arr[j] == 1) {
					swap(arr[i], arr[j]), res++, found = 1;
					break;
				}
			if (!found)
				for (int j = s2; j < s3; j++)
					if (arr[j] == 1) {
						swap(arr[i], arr[j]), res++;
						break;
					}
		}

	}

	for (int i = s2; i < s3; i++) {
		if (arr[i] == 2)
			continue;

		for (int j = s3; j < n; j++)
			if (arr[j] == 2) {
				swap(arr[i], arr[j]), res++;
				break;
			}

	}
	cout << res << endl;
	return 0;
}
