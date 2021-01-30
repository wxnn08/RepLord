    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
     
    vector<long long int> bag;
     
    int qtd = 0;
    void build(int i, int res, long long int val){
    	if(res < 0) return;
    	if(i >= 10){
    		if(res == 0) bag.push_back(val);
    		else return;
    	}
    	else{
    		for(long long int j=0; j <= 9; j++){
    			build(i+1, res-j, val*10+j);
    		}
    	}
    }
     
     
    int main(){
    	build(0, 10, 0);
    	int k;
    	sort(bag.begin(), bag.end());
    	cin >> k;
    	cout << bag[k-1] << endl;
    }
     
