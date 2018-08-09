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

const int TAM = 5e8;
int dp[TAM];

int procura(int n){
	int val; 
	int menor = -INF, maior = INF;
	for(int i=0; i<29; i++){
		for(int j=i+1; j<29; j++){
			if(dp[i]==0) dp[i] = (1<<i);
			if(dp[j]==0) dp[j] = (1<<j);
			val = dp[i]+dp[j];
			if(val<=1e9){
				if(val>n) maior = min(maior, val);
				else menor = max(menor,val);
			}
		}
	}

	return min(abs(n-menor), abs(n-maior));
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int TC;
	cin >>TC;
	while(TC--){
		int n;
		cin >>n;
		cout <<procura(n) <<endl;
		//cout << (n<<1) <<endl;
	}

    return 0;
}

