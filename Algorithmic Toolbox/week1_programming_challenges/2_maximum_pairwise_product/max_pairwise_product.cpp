#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

//int MaxPairwiseProduct(const std::vector<int>& numbers) {
//    int max_product = 0,index1=0,index2=0;
//    int n = numbers.size();
//
//    for (int first = 0; first < n; ++first) {
//        if(numbers[index1] < numbers[first]){
//			index1=first;
//		}
//    }
//	for (int second = 0; second < n; ++second) {
//        if((numbers[index2] < numbers[second]) && (index1 != index2)){
//			index2=second;
//		}
//    }
//	max_product=numbers[index1] * numbers[index2];
//
//    return max_product;
//}
long long int maxpairwiseproduct(const vector<int>& numbers){
	
	int n = numbers.size();
	int index1=-1;
	int index2=-1;
	for(int i=0;i<n;i++){
		if((index1 == -1)||(numbers[index1] < numbers[i]))
			index1=i;
	}
	
	for(int j=0;j<n;j++){
		if( (j != index1)&&((index2 == -1)||(numbers[index2] < numbers[j])))
			index2=j;
	}

	
	return (long long int)(numbers[index1])*numbers[index2];
}


int main() {
	
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    long long int result=maxpairwiseproduct(numbers);

    cout <<  result<< endl;
    return 0;
}
