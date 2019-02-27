#include <stdio.h>

int main() {
	const int N = 1e3 + 5; // 1e3 + 5 = 1000 + 5
    int v[N];
    
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		v[i] = 0; // necessario zerar pois pode haver lixo nessa posicao do vetor
		for(int j = 0; j < 3; j++) {
			int val; 
			scanf("%d", &val);
			v[i] += val;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(v[i] >= 2) ans = ans+1; //ou ans++;
	}

	printf("%d\n", ans);

    return 0;
}

