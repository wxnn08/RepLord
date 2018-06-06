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
    while(cin >>n, n!=0){
	int a[10];
	for(int i=0; i<n; i++){
	    cin >>a[i];
	}
	sort(a, a+n);

	do{
	    for(int i=0; i<n; i++){
		cout <<a[i] <<' ';
	    }
	    cout <<endl;
	} while (next_permutation(a, a+n));
	cout <<endl;
    }
    
    return 0;
}

