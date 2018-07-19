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
 
int main(){
    ios_base::sync_with_stdio(false);

    int cont=0;
	int res[1005];

    int n;
	cin >>n;

	int ant, atual;
	cin >>ant;

	for(int i=1; i<n; i++){
		cin >>atual;
		if(atual<=ant){
			res[cont]=ant;
			cont++;
		}
		ant = atual;
	}
	res[cont]=ant;

	cont++;
	cout <<cont <<endl;
	for(int i=0; i<cont; i++){
		cout <<res[i] <<' ';
	}
	cout <<endl;
    return 0;
}

