//UVa 146: think of it as numbers not letters
//http://www.algorithmist.com/index.php/UVa_146
// You can use next_permutation() function in algorithm.h
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void rev(string& str) {
	char temp;
	int pos;
	for (int i = 0; i < str.length() / 2; i++) {
		pos = str.length() - 1 - i;

		temp = str[i];
		str[i] = str[pos];
		str[pos] = temp;
	}
}

void swap(string& str, int pos1, int pos2) {
	char temp = str[pos1];
	str[pos1] = str[pos2];
	str[pos2] = temp;
}
int main() {

	string in, sub1, sub2;
	bool edit = 0;
	while (cin >> in) {

		if (in == "#")
			return 0;

		edit = 0;
		for (int i = in.length() - 1; i > -1; i--) {
			for (int j = i - 1; j > -1; j--) {

				if (in[i] > in[j]) {//searching for a rightmost number that is bigger than another on the left

					swap(in, i, j); //swap the two numbers


					//taking away the numbers in between and at the last, then reverse them

					sub1 = in.substr(j + 1, i - j - 1);

					rev(sub1);



					if (i + 1 < in.length()) {
						sub2 = in.substr(i + 1, in.length() - 1 - i);

						in.erase(i + 1, sub2.length());


						rev(sub2);

						in.insert(j + 1, sub2);


					}

					in.erase(j + 1 +sub2.length(), sub1.length());

					if (i + 1 < in.length()) //if i is not the last char

						in.insert(i + 1, sub1);
					else

						in += sub1;

					edit = 1;

					cout << in << endl;

					goto outLoop;

				}
			}
		}
		outLoop: if (!edit)
			cout << "No Successor\n";

	}

	return 0;
}
