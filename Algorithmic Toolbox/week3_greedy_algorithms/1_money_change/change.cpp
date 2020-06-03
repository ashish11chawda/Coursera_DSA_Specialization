#include <iostream>

int get_change(int m) {
  //write your code here
  int n=0;
  
  while(m){
  	if(m>=10){
  		n = n + (m/10);
  		m = m%10;
	}
	else if(m>=5 && m<10){
		n = n + (m/5);
		m = m%5;
	}
	else if(m>=1){
		n = n + m;
		m = m%1;
	}
	else{	
	}
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
