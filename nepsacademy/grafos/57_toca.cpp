/* Aí, você já parou pra pensar, por que que você vive?
 * O que é que te move?
 * Aquele momento que decodifica o segredo da sua alma
 * E de repente tudo começa a fazer sentido.
 * É um chamado legítimo que vem lá do íntimo 
 * É quando a poesia entra em sincronia com o ritmo 
 * E te faz pensar 
 * Se não fosse isso eu podia até respirar, mas vivo eu também não ia tá!
 */
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

const int N = 1e3 + 5;
int mat[N][N];
int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visit[N][N];
int n, m;

bool valid(int ii, int jj) {
	return ii >= 0 and jj >= 0 and ii < n and jj < m and mat[ii][jj] != 0;
}

int dfs(int ii, int jj) {
	if(mat[ii][jj] == 3) return 1; // Se eu cheguei no destino
	visit[ii][jj] = true; // Marco como visitado para n voltar no nó

	int ans = INF; 
	for(int k = 0; k < 4; k++) { // Vou tentar ir para todos os lados
		int i = ii+pos[k][0];
		int j = jj+pos[k][1];

		// Se for uma posição valida e eu não visitei, visite:
		if(valid(i, j) and !visit[i][j]) { 
			ans = min(ans, dfs(i, j) + 1);
			// Armazena o minimo da resposta atual e ir para o caminho
			// escolhido adicionando 1 (estou dando 1 passo)
		}
	}
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(false);

	// Leitura da entrada:
	cin >>n >>m;
	int ini, inj;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >>mat[i][j];
			// Gravo inicio da dfs:
			if(mat[i][j] == 2) ini = i, inj = j;
		}
	}

	cout <<dfs(ini, inj) <<endl;
	
	return 0;
}

