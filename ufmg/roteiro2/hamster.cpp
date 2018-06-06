#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int v0, k1, k2;
double calcula(double t){
    double pontoX = k1*(pow(v0,2)*sin(2*t))/10;
    double pontoY = k2*(pow(v0,2)*pow(sin(t),2))/20;
    return pontoX+pontoY;
}
double buscaAngulo(double ti, double tf){
    //calcula meio
    double meio = (ti+tf)/2;
    //cout <<"Ang alto: " <<tf*180/PI <<" / Ang baixo: " <<ti*180/PI <<endl;
    //theta 1 e theta 2, os 2 angulos
    if(abs(ti-tf)<=1e-9) return meio;

    if(calcula(ti)>calcula(tf)) return buscaAngulo(ti,meio);
    else return buscaAngulo(meio, tf);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;
    
    for(int i=0; i<n; i++){
	// velocidade inicial, pontos pra cima, pontos pra frente
	cin >>v0 >>k1 >>k2;
	double angulo = buscaAngulo(0, PI/2);
	cout <<setprecision(3) <<fixed <<angulo <<' ' <<calcula(angulo) <<endl;
    }

    return 0;
}

