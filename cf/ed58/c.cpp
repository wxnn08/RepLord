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

const int N = 1e5 + 5;
ll seg[4*N+1];
ll lazy[4*N+1];

ll seg2[4*N+1];
ll lazy2[4*N+1];

void prop(int r, int i, int j){
	seg[r] += lazy[r]*(j-i+1);
	
	if(i != j) {
		lazy[2*r] += lazy[r];
		lazy[2*r+1] += lazy[r];
	}
	lazy[r] = 0;
}

ll query(int r, int i, int j, int a, int b){
	prop(r,i,j);
	if(i >b or j<a) return 0;
	if(i>=a and j<=b) return seg[r];
	
	int mid = (i+j)>>1;
	return query(2*r, i, mid, a, b) + query(2*r+1, mid+1, j, a, b);
}

void update(int r, int i, int j, int a, int b, int v){
	prop(r, i, j);
	if(i>b or j<a) return;
	if(i>=a and j<=b) {
		lazy[r] += (ll)v;
		prop(r, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(2*r, i, mid, a, b, v);
	update(2*r+1, mid+1, j, a , b, v);
	seg[r] = seg[2*r] + seg[2*r+1];
	return;
}

void prop2(int r, int i, int j){
	seg2[r] += lazy2[r]*(j-i+1);
	
	if(i != j) {
		lazy2[2*r] += lazy2[r];
		lazy2[2*r+1] += lazy2[r];
	}
	lazy2[r] = 0;
}

ll query2(int r, int i, int j, int a, int b){
	prop2(r,i,j);
	if(i >b or j<a) return 0;
	if(i>=a and j<=b) return seg2[r];
	
	int mid = (i+j)>>1;
	return query2(2*r, i, mid, a, b) + query2(2*r+1, mid+1, j, a, b);
}

void update2(int r, int i, int j, int a, int b, int v){
	prop2(r, i, j);
	if(i>b or j<a) return;
	if(i>=a and j<=b) {
		lazy2[r] += (ll)v;
		prop2(r, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update2(2*r, i, mid, a, b, v);
	update2(2*r+1, mid+1, j, a , b, v);
	seg2[r] = seg2[2*r] + seg2[2*r+1];
	return;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int tc;
	cin >>tc;

	while(tc--) {
		int n;
		cin >>n;
		
		memset(seg, 0, sizeof(seg));
		memset(seg2, 0, sizeof(seg2));
		memset(lazy, 0, sizeof(lazy));
		memset(lazy2, 0, sizeof(lazy2));

		bool aa = true;
		vector<int> ans;
		
		int a, b;
		for(int i = 0; i < n and aa; i++) {
			cin >>a >>b;
			update(1, 0, N, a, b, 1);

			ll v = query(1, 0, N, a, b);
			if(v > (b-a+1)) {
				update(1, 0, N, a, b, -1);

				update2(1, 0, N, a, b, 1);
				ll t = query2(1, 0, N, a, b);

				if(t > (b-a+1)) {
					cout <<-1 <<endl;
					aa = false;
				}
				else {
					ans.pb(2);
				}
			}
			else {
				ans.pb(1);
			}
		}
		if(aa) {
			bool f = false;
			for(int i = 0; i < ans.size()-1; i++) {
				if(ans[i] == 2)
					f = true;
				cout <<ans[i] <<' ';
			}
			if(!f)
				cout <<2 <<endl;
			else
				cout <<ans[ans.size()-1] <<endl;
		}
	}

    return 0;
}

