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

const int N = 1e5 + 5;
int n;
int p[N];
int v[N];
int dp[10][N];

int solve(int f, int pos) {

	if(pos > n) return 0;
	int &r = dp[f][pos];
	if(r != -2) return r;

	int next = -1;
	for(int i = 1; i <= 5; i++) {
		if((v[pos] == 1 and i > f) or (v[pos] == 0 and i != f) or (v[pos] == -1 and i < f))
			next = solve(i, pos+1);

		if(next != -1) 
			return r = i;
	}
	return r = next;
}
 
int main(){

    cin >>n;
	for(int i = 0 ; i < n; i++) {
		cin >>p[i];
	}
    
	for(int i = 1; i < n; i++) {
		if(p[i] < p[i-1]) v[i] = -1;
		if(p[i] > p[i-1]) v[i] = 1;
		if(p[i] == p[i-1]) v[i] = 0;
	}
	for(int i = 1; i <= 5; i++) 
		for(int j = 0; j < n; j++) 
			dp[i][j] = -2;

	for(int i = 1; i <= 5; i++) {
		int f = solve(i, 1);
		if(f != -1) {
			cout <<i <<' ';
			int next = i;
			for(int i = 1; i < n; i++) {
				cout <<dp[next][i] <<' ';
				next = dp[next][i];
			}
			cout <<endl;
			return 0;
		}
	}
	cout <<-1 <<endl;
	/*
	for(int i = 1; i <= 5; i++) {
		for(int j = 0; j < n; j++) {
			printf("%4d ", dp[i][j]);
		}
		cout <<endl;
	}
	*/
    return 0;
}

