/*
 ID: fci_isl1
 LANG: C++
 TASK: calfflac
 */
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

const int SIZE = 20005;
char word[SIZE], non[SIZE];
int sz;

bool isPalindrome(char str[], int start, int end) {

	int sz = start + end;
	int lim = (sz + 1) / 2;

	for (int i = start; i < lim; i++)
		if (str[i] != str[sz - i])
			return 0;

	return 1;
}

void rmv() {
	sz = strlen(word);
	int ind = 0;

	for (int i = 0; i < sz; i++)
		if (isalpha(word[i]))
			non[ind++] = tolower(word[i]);

	sz = ind;
}

int main() {
	freopen("calfflac.in", "r", stdin);
	freopen("calfflac.out", "w", stdout);

	int Max = -1, start = -1, end = -1, len;

	char str[SIZE];
	while (cin.getline(str, SIZE))
		strcat(word, str), strcat(word, "\n");

	rmv();
	int Min = (sz < 2000) ? sz : sz - 2000;
	for (int i = 0; i < Min; i++) {

		for (int j = i + 1; j < sz; j++) {
			if ((len = j - i + 1) > 2000)
				break;

			if (non[i] == non[j] && non[i]!=non[j+1])
				if (isPalindrome(non, i, j))
					if (Max < len)
						Max = len, start = i, end = j;
		}
	}

	printf("%d\n", Max);

	int count = 0, ind = 0;
	while (count < start) {
		if (isalpha(word[ind++]))
			count++;
	}

	while (!isalpha(word[ind]))
		ind++;

	while (count <= end) {
		if (isalpha(word[ind]))
			count++;

		printf("%c", word[ind++]);
	}

	printf("\n");

	return 0;
}
