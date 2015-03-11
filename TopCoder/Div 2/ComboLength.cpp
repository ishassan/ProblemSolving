//TC 234-D2-1

#include <iostream>

using namespace std;

class ComboLength {

public:
	int howLong(string moves) {

		int len = 0;
		int max = 0;
		int limit = moves.length();
		int limitM = limit - 1;

		for (int i = 0; i < limit; i++) {
			if (moves[i] == 'A') {
				len++;
				if (i < limitM && moves[i + 1] == 'B') {
					if (len > max)
						max = len;

					len = 0;
				}
			}

			else {
				len++;

				if (i < limitM && moves[i + 1] == 'A') {
					if (len > max)
						max = len;

					len = 0;
				}
			}

			if (len > max)
				max = len;
		}

		return max;
	}

};

int main() {

	ComboLength a;

	cout << a.howLong("AAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAA");

	return 0;
}
