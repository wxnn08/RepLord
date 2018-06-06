#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    
    //ler entradas
    int hh, mm;
    double h, d, c ,n;
    cin >>hh >>mm >>h >>d >>c >>n;
    
    //custo sem desconto e com desconto
    double sD=-1, cD=-1;
    if(!(hh>=20 && hh<=23)){
	sD = ceil((h/n))*c;
	int dif;
	dif = (20*60)-((hh*60)+mm);
	h+=dif*d;
	cD=ceil((h/n))*c;
    }
    else{
	cD=ceil((h/n))*c;
    }
    
    cD*=0.8;
    if(sD==-1) cout <<fixed <<setprecision(4) <<cD <<endl;
    else if(sD>cD) cout <<fixed <<setprecision(4) <<cD <<endl; 
    else cout <<fixed <<setprecision(4) <<sD <<endl; 
    return 0;
}

