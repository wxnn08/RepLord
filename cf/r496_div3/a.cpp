#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	vector<int> v;
	int esc[1005];

	//for(int i=0; i<n; i++){
	fori(i,0,n){
		cin >>esc[i];
	}

	fori(i,1,n){
		if(esc[i-1]>=esc[i]){
			v.pb(esc[i-1]);
		}
	}
	
	v.pb(esc[n-1]);

	cout <<v.size() <<endl;
	for(int i:v)
		cout <<i <<' ';
	cout <<endl;
    
    return 0;
}

