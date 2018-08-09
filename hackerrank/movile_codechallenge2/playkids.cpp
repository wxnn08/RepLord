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
const int TAM = 150+5;
int m[TAM][TAM];

void insereMatriz(int x1,int y1, int x2, int y2){
	int c0 = x1;
	int c1 = c0+abs(x2-x1)/3;
	int c2 = c1+abs(x2-x1)/3;
	int c3 = c2+abs(x2-x1)/3;
	int l0 = y1;
	int l1 = l0+abs(y2-y1)/3;
	int l2 = l1+abs(y2-y1)/3;
	int l3 = l2+abs(y2-y1)/3;

	for(int i=l0; i<l3; i++){
		for(int j=c0; j<c3; j++){
			if(i>=l0 && i<l1){
				if((j>=c0 && j<c1) || (j>=c2 && j<c3)) m[i][j] = max(m[i][j],1);
				if(j>=c1 && j<c2) m[i][j] = max(m[i][j],2);
			}
			if(i>=l1 && i<l2){
				if((j>=c0 && j<c1) || (j>=c2 && j<c3)) m[i][j] = max(m[i][j],2);
				if(j>=c1 && j<c2) m[i][j] = max(m[i][j],3);
			}
			if(i>=l2 && i<=l3){
				if((j>=c0 && j<c1) || (j>=c2 && j<c3)) m[i][j] = max(m[i][j],1);
				if(j>=c1 && j<c2) m[i][j] = max(m[i][j],2);
			}
		}
	}
}

int toque(int x,int y){
	int val = m[y][x];
	if(y>0)	val = max(val, m[y-1][x]);
	if(x>0) val = max(val, m[y][x-1]);
	if(y>0 && x>0) val = max(val, m[y-1][x-1]);
	return val;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int n;
	cin >>n;
	while(n--){
		int x1,y1,x2,y2;
		cin >>x1 >>y1 >>x2 >>y2;
		insereMatriz(x1,y1,x2,y2);
	}
/*	
	cout <<endl;
	fori(i,0,150){
		fori(j,0,150){
			cout <<m[i][j];
		}
		cout <<endl;
	}
*/
	int TC;
	cin >>TC;

	while(TC--) {
		int u;
		cin >>u;
		int res = 0;
		fori(i,0,u){
			int x, y;
			cin >>x >>y;
			res += toque(x,y);
		}
		
		double media = (double)res/u;

		if(media<1.1) cout <<"crianca";
		else if(media>1.9) cout <<"adulto";
		else cout <<"indefinido";
		cout <<endl;
	}
    
    return 0;
}

