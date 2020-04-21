#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, s, min;

    cin >>n >>s;
    min = s;

    int i=0, val;

    while(i<n){
	    
	    cin >>val;
	    s = s+val;
	    
	    if(s<min) min = s;
	    
	    i++;
    }

    cout <<min;

    return 0;
}
