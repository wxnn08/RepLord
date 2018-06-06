#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    map<char,int> m;
    string s;
    cin >>s;
    
    for(int i=0; i<s.length(); i++){
	m[s[i]]++;
    }
    
    //erros:
    if(m.size()>4 || s.length()<4 || m.size()==1){
	cout <<"No" <<endl;
	return 0;
    }
    
    if(m.size()==2){
	map<char,int>::iterator it;
	for(it=m.begin(); it!=m.end(); it++){
	    if(it->sec==1){ 
		cout <<"No" <<endl;
		return 0;
	    }
	}
    }

    cout <<"Yes" <<endl;
    
    return 0;
}

