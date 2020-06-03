#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double get_optimal_value(int n,int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int sum = 0;
  double vbyw[n];
  for(int i=0;i<n;i++){
  	vbyw[i] = ((double)values[i])/((double)weights[i]);
  }
  /*3 50
    v   | w
	60  | 20
	100 | 50
	120 | 30
  */
  // vbyw ={3,2,4}
  
  double max= vbyw[0];
  int index =0 ;
 
  while(capacity){//iter1 capacity=50
  //iter2  capacity=20
  	for(int i=0;i<n;i++){
	  if(max < vbyw[i]){
	  	max= vbyw[i];
	  	index=i;
	  }	
	}
	//iter 1
	// max = 4
	// index = 2
	//iter 2
	// max = 3
	// index = 0
	
	vbyw[index]=0.0;
	//iter1 vbyw ={3,2,0}
	//iter2 vbyw ={0,2,0}
	if(weights[index]>capacity){//iter1 30<50 "x"
	//iter2 20<20 "x"
		int diff = weights[index]-capacity;
		sum = sum + weights[index]-diff;
		value= value + (sum * max);
		capacity = capacity - sum ;
	}
	else if(weights[index] <= capacity){//iter1 30 < 50
	//iter2 20==20
		sum = sum + weights[index];
		//iter1 0=0+30 sum=30
		//iter2 30=30+20 sum=50
		value= value + (sum * max);
		//iter1 0.0 = 0.0 + (30*4) value = 120
		//iter2 120 = 120 + (50 * 3) value = 180
		capacity = capacity - sum ;
		//50=50-30 capacity=20
	}
	else{
		
	}
	sum=0;
	max=0;
	index=0;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n,capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
