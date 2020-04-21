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

    int n, k;
	cin >>n >>k;

	if(k>2*(n-2)) cout <<"NO" <<endl;
	else {
		cout <<"YES" <<endl;
		fori(i,0,4){
			fori(j,0,n){
				if(i==0 || i==3 || j==0 || j==n-1 || k==0){
					cout <<'.';
				}
				else {
					cout <<"#";
					k--;
				}
			}
			cout <<endl;
		}
	}
    
    return 0;
}

