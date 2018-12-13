#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    
	int n, c;
	scanf(" %d %d", &n, &c);
    int ini = 1, fim = n, mid, i = 1, ans;
	bool f = false;

	while(!f and i <= n) {
		printf("1 %d\n", i);
		fflush(stdout);
		scanf(" %d", &ans);
		if(ans) {
			printf("2\n");
			fflush(stdout);
			fim = i;
			f = true;
		}
		else {
			ini = i;
		}
		i += 1000;
	}
	
	while(ini < fim) {
		mid = ini+((fim-ini)/10);
		printf("1 %d\n", mid);
		fflush(stdout);
		scanf(" %d", &ans);
		if(ans) {
			fim = mid;
			printf("2\n");
			fflush(stdout);
		}
		else {
			ini = mid+1;
		}
	}
	printf("3 %d\n", ini);
	fflush(stdout);

    return 0;
}

