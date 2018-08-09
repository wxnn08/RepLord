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

    int TC;
	cin >>TC;

	while(TC--) {
		int n, m;
		cin >>n >>m;
		int val = n*m;
		
		int res[405];
		memset(res, 0, sizeof res);

		for(int i=0; i<n*m; i++) {
			if(res[i]==0){
				res[i]=val--;
				for(int j=0; j<(i%m); j++) {
					int pos = i+(m-1)*(j+1);
					if((pos/m)<n && res[pos]==0){
						res[pos] = val--;
					}

				}
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout <<res[(i*m)+j] <<' ';
			}
			cout <<endl;
		}

	}
    
    return 0;
}

