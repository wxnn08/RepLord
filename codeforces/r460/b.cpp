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

int somaD(int n){
	int res = 0;
	while(n){
		res += n%10;
		n /= 10;
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	int k=1;
	int res = 19;
	while(k!=n){
		if(somaD(++res) == 10) k++;
	}
	cout <<res <<endl;

    return 0;
}

