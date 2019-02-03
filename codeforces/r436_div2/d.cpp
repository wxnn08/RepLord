#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int N = 2e5+5;
int n, qtd[N], v[N], vis[N];

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n;

	for(int i = 0; i < n; i++) {
		cin >>v[i];
		qtd[v[i]]++;
	}
	
	queue<int> q;
	for(int i = 1; i <=n; i++) {
		if(qtd[i] == 0) q.push(i);
	}
    
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(qtd[v[i]] > 1 and (vis[v[i]] or q.front() < v[i])) {
			qtd[v[i]]--;
			ans++;
			v[i] = q.front();
			q.pop();
			qtd[v[i]]++;
		} else {
			vis[v[i]] = 1;
		}
	}

	cout <<ans <<endl;
	for(int i = 0; i < n; i++) {
		cout <<v[i] <<' ';
	}
	cout <<endl;
    return 0;
}

