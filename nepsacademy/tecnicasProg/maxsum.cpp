#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	int a[100];
	fori(i,0,n) cin >>a[i];

	int endhere = 0;
	int maior = 0;
	for(int i=0; i<n; i++){
		endhere += a[i];
		endhere = max(endhere, 0);
		maior = max(endhere, maior);
	}
    
	cout <<maior <<endl;
    return 0;
}

