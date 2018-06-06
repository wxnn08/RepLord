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

int casa[1005][1005];
int maiorCaminho=0;

void dfs(int inI, int inJ, int maior){
	if(casa[inI][inJ]==3){
		maiorCaminho = max(maiorCaminho, maior);
		return;
	}
	
	casa[inI][inJ]=0;

	if(casa[inI+1][inJ]!=0) dfs(inI+1, inJ, maior+1);
	if(inI>0 && casa[inI-1][inJ]!=0) dfs(inI-1, inJ, maior+1);
	if(casa[inI][inJ+1]!=0) dfs(inI, inJ+1, maior+1);
	if(inJ>0 && casa[inI][inJ-1]!=0) dfs(inI, inJ-1, maior+1);
	
	return;
}

int main(){
    ios_base::sync_with_stdio(false);

    memset(casa, 0, sizeof(casa));

	int n, m;
	cin >>n >>m;
	int inI, inJ;

	fori(i, 0, n){
		fori(j, 0, m){
			cin >>casa[i][j];
			if(casa[i][j]==2){
				inI = i;
				inJ = j;
			}
		}
	}

	dfs(inI, inJ, 1);
	cout <<maiorCaminho <<endl;
    
    return 0;
}

