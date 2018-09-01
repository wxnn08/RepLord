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


	const int N = 1e5+5;
	int p[N];
	int n;
	cin >>n;
	int total = 0;
	for(int i=0; i<n; i++){
		cin >>p[i];
		total += p[i];
	}
	
	int maior = 0;
	int val = 0;
	for(int i=0; i<n*2; i++) {
		val = max(val+p[i%n], 0);
		maior = max(maior, val);
	}
	cout <<max(0, maior) <<endl;

    return 0;
}

