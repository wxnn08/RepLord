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
 
const int TAM = 257;
vector<int> v;

bool cmp(int a, int b){
	return a<b;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, k;
	cin >>n >>k;
	vector<int> u;
	fori(i,0,n){
		int aux;
		cin >>aux;
		u.pb(aux);
	}
	
	v = u;
	sort(v.begin(), v.end(), cmp);
	int visit[TAM];
	memset(visit, -1, sizeof visit);
	for(int i:v){
		if(visit[i]==-1) {
			int t=0;
			int menor = i-(k-1);
			for(int j=i; j>=0 && t<k; t++, j--){
				if(menor<=0) visit[j]=0;
				else if(visit[j]==-1)visit[j] = menor;
			}
		}
	}

	for(int i:u) cout <<visit[i] <<' ';
	cout <<endl;
    
    return 0;
}

