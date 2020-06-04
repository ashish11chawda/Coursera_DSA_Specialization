#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int d, int m, vector<int> & stop) {
    stop.insert(stop.begin(),0);
    stop.insert(stop.end(),d);
	
    int curpos=0;
    int prepos=0;
    while(curpos < stop.size() ){
    	int lastpos=curpos;
    	while((curpos < stop.size()) && ((stop[curpos+1]-stop[lastpos])<= m)){
    		curpos++;
		}
		if(curpos == lastpos){
			return -1;
		}
		if(curpos<(stop.size())){
			prepos++;
		}
		
    
	}
    
    
    return prepos;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
