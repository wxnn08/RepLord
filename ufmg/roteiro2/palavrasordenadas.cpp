#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	string p;
	for(int i=0; i<n; i++){
	    cin >>p;
	    bool ordenada = true;
	    
	    for(int j=1; j<p.length() && ordenada; j++){
		if(tolower(p[j]) <= tolower(p[j-1])) ordenada=false;
	    }
	    cout <<p <<": ";
	    if(ordenada) cout <<"O" <<endl;
	    else cout <<"N" <<endl;
	}
    
    return 0;
}

