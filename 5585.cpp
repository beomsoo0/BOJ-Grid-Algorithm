#include <stdio.h>

int main() {

	int Pay, Resi;
	scanf("%d", &Pay);
	Resi = 1000 - Pay;
	int count = 0;
	if (Resi / 500 != 0) {
		count += Resi / 500;
		Resi = Resi % 500;
	}
	if (Resi / 100 != 0) {
		count += Resi / 100;
		Resi = Resi % 100;
	}
	if (Resi / 50 != 0) {
		count += Resi / 50;
		Resi = Resi % 50;
	}
	if (Resi / 10 != 0) {
		count += Resi / 10;
		Resi = Resi % 10;
	}
	if (Resi / 5 != 0) {
		count += Resi / 5;
		Resi = Resi % 5;		
	}
	if (Resi / 1 != 0) {
		count += Resi / 1;
		Resi = Resi % 1;		
	}
	printf("%d", count);
	return 0;
}