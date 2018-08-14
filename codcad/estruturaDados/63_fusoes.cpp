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

const int MAX = 1e5+5;
int pai[MAX], peso[MAX];

int find(int x) {
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}
void join(int x, int y) {
	x = find(x);
	y = find(y);

	if(x==y) return;

	if(peso[x]>peso[y]) {
		pai[y] = x;
	}
	else if(peso[x]<peso[y]) {
		pai[x] = y;
	}
	else {
		pai[x] = y;
		peso[y]++;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >>n >>k;
	
	fori(i,1,n+1) pai[i] = i;
	memset(peso, 0, sizeof peso);

	fori(i,0,k) {
		char c;
		cin >>c;
		int x, y;
		cin >>x >>y;

		if(c == 'C') {
			if(find(x) == find(y)) cout <<"S";
			else cout <<"N";
			cout <<endl;
		}
		if(c == 'F') {
			join(x,y);
		}
	}

    return 0;
}

