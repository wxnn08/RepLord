#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;
    string s;
    while(n!=0){
	set<string> seq;
	int cont=0;
	for(int i=0; i<n; i++){
	    cin >>s;
	    sort(s.begin(), s.end());
	    if(!seq.count(s)){
		seq.insert(s);
		cont++;
	    }
	}
	cout <<cont <<endl;
	cin >>n;
    }
    
    return 0;
}

