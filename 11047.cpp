#include <stdio.h>

int main() {

	int N, K, Quotient, Residual;
	int COIN[10] = { 0 };
	int count = 0;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &COIN[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		Quotient = K / COIN[i];
		Residual = K % COIN[i];

		if (Quotient != 0) {
			K = Residual;
			count += Quotient;
		}
	}
	printf("%d", count);

	return 0;
}