#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 505;
int n;
bool isIn[N];
int v[N];

int check(int a, int b) {
	int ant = -1;
	int cont = 0;

	for(int i = 1; i <= n; i++) {
		if(v[i] == a) {
			if(ant == a) continue;
			cont++;
			ant = a;
		}
		if(v[i] == b) {
			if(ant == b) return -1;
			cont++;
			ant = b;
		}
	}
	return cont;
}

int solve() {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!isIn[i]) continue;
		for(int j = i+1; j <= n; j++) {
			if(!isIn[j]) continue;
			ans = max(ans, check(i, j));
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >>n;
	
	for(int i = 1; i <= n; i++) {
		cin >>v[i];
		isIn[v[i]] = true;
	}
	
	cout <<(n == 1? 1 : solve()) <<endl;

	return 0;
}

