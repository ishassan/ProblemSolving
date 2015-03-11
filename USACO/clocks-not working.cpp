/*
 ID: fci_isl1
 LANG: C++
 TASK: clocks
 */

#include <iostream>
#include <map>
#include <string>
#include <queue>

#define fro q.front()

using namespace std;

int clocks;

string tostr[10];

map<string, char> toint;

int global[262144];

void init() {
	// positions of change
	tostr[1] = "0134";
	tostr[2] = "012";
	tostr[3] = "1245";
	tostr[4] = "036";
	tostr[5] = "13457";
	tostr[6] = "258";
	tostr[7] = "3467";
	tostr[8] = "678";
	tostr[9] = "4578";

	for (int i = '1'; i <= '9'; i++) {
		toint[tostr[i - '0']] = i;	//1 = "0134"
	}
}

short getNum(short ind, int clocks){	//access int variable as array
	ind = 16-(ind*2);
	return ((clocks>>ind) & 3) *3 + 3;
}

void setNum(short ind, int& clocks, short val){
	ind = 16-(ind*2);
	if(val==3){
		clocks = clocks & (~(1<<ind));
		clocks = clocks & (~(1<<(ind+1)));
	}

	else if(val==6){
		clocks = clocks | (1<<ind);
		clocks = clocks & (~(1<<(ind+1)));
	}

	else if(val==9){
			clocks = clocks & (~(1<<ind));
			clocks = clocks | (1<<(ind+1));
		}

	else if(val==12){
		clocks = clocks | (1<<ind);
		clocks = clocks | (1<<(ind+1));
	}

}

void change(short step, int& clocks) {	//applying moves
	if (step == 0)	//no move =0
		return;

	string str = tostr[step];
	int sz = str.size(), pos;
	for (int i = 0; i < sz; i++) {
		pos = str[i] - '0';
		if ((step=getNum(pos,clocks)) == 12)
			setNum(pos,clocks,3);
		else
			setNum(pos,clocks,step+3);
	}
}

struct node{
	int clocks,last,times;
	//last: last move in the path
	//times: number of times the last move has been repeated
};
void BFS() {
	queue<node> q;

	node n;
	n.clocks = clocks;
	n.last = n.times =0;

	q.push(n);
	while (!q.empty()) {
		short size = q.size();
		while (size--) {
			n = q.front();
			clocks = n.clocks;

			q.pop();

			if (clocks == 262143) //final state
				return;

			int newBits = 0;
			for (short i = 1; i < 10; i++) {
				if (n.last == i) {
					if (n.times == 3)	// 1111 = 1
						continue;
					else
						n.times++;
				}
				else if (n.last > i)	// 21 = 12
					i = n.last, n.times = 1;
				else
					n.last = i, n.times = 1;

				newBits = clocks;

				change(i, newBits);

				n.clocks = newBits;

				q.push(n);
				global[newBits] = clocks;
			}
		}
	}
}

char getPath(int& prev, int& next) {	//compares the changes and find the move that has been applied
	string place;
	for (int i = 0; i < 9; i++) {
		if (getNum(i,prev) != getNum(i,next))
			place += i + '0';
	}

	return toint[place];
}
int main() {
	//freopen("clocks.in","r",stdin);
	//freopen("clocks.out","w",stdout);

	init();
	short inp;
	for (int i = 0; i < 9; i++)
		cin >> inp, setNum(i,clocks,inp);

	int start = clocks, end = 262143, prev = 0;
	string path;

	BFS();

	while (end != start) {
		prev = global[end];
		path = getPath(prev, end) + path;
		end = prev;
	}

	cout << path << endl;
	return 0;
}
