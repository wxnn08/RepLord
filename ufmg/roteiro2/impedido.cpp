#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

#define for_(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);
    
    int a, d;
    cin >>a >>d;
    while(a!=0 && d!=0){
	int A[20], D[20];

	for_(i, 0, a) cin >>A[i];
	for_(i, 0, d) cin >>D[i];

	sort(A, A+a);
	sort(D, D+d);
	
	if(A[0] < D[1]) cout <<'Y' <<endl;
	else cout <<'N' <<endl;

	cin >>a >>d;
    }

    return 0;
}

