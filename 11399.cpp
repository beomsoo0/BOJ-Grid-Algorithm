#include <stdio.h>

int main(){
	int num, temp;
	int sum = 0;
	int data[1000] ={0};
	scanf("%d", &num);
	
	for(int i=0; i<num; i++){
		scanf("%d", &data[i]);
	}
	for(int i=0; i<num-1; i++){
		for(int j=0; j<num-1-i; j++){
			if(data[j+1] < data[j]){
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	
	for(int i=0; i<num; i++){
		sum += (num - i) * data[i];
	}
	printf("%d", sum);
	return 0;
}

