// UVa 483
#include <iostream>

using namespace std;


void rev(string& str){
	char temp;
	for(int i=0; i<str.length()/2; i++){
		temp = str[i];
		str[i] = str[str.length()-1-i];
		str[str.length()-1-i] = temp;
	}
}
int main() {

	char x;
	string word;

	while((x=getchar())!=EOF){
		if(x=='\n' || x==' '){
			rev(word);
			cout<<word;
			putchar(x);
			word.clear();
		}
		else{
			word+=x;
		}

	}

	return 0;
}
