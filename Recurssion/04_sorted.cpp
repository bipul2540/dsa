#include <iostream>
#include <vector>


using namespace std;

bool isSorted(vector<int> arr, int index){
	if(index >=arr.size()-1){
		return true;
	}
	if(arr[index] > arr[index+1]){
		return false;
	}
	return isSorted(arr, index+1);
}

int main() {

	vector<int> arr = {106, 2, 3, 4, 99};

                    //{array---index)
	bool ans = isSorted(arr, 0);
	if(ans){
		cout << "Array is sorted";
	}else {
		cout << "Arrays is not sorted";
	}

}