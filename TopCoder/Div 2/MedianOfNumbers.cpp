//TC 308-D2-1  Execution Time = 0.000ms
#include <iostream>
#include <vector>
using namespace std;

class MedianOfNumbers {

public:
    void sort(vector<int>& arr) {
        int temp;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

     int findMedian(vector<int> numbers) {

        if (numbers.size() % 2 == 0) 
            return -1;
        
        else {
            sort(numbers);
            return (numbers[numbers.size() / 2]);
        }

    }
};
int main() {

	MedianOfNumbers a;

	vector<int> v;
	v.push_back(3);
	v.push_back(1);

	a.sort(v);

	cout<<v[0];
	

	return 0;
}
