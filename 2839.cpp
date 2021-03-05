#include <iostream>
#define big 5
#define small 3

using namespace std;


int solution(int& n) {
	int big_cnt, Residual, small_cnt, cnt;
	

	if (n < small) {
		return -1;
	}

	big_cnt = n / big;

	while (big_cnt >= 0) {
		Residual = n - 5 * big_cnt;
		small_cnt = Residual / small;
		if (Residual % small == 0) {
			return  big_cnt + small_cnt;
		}
		big_cnt--;
	}
	return -1;
}

int main(void) {
	int N, result;
	cin >> N;
	
	result = solution(N);
	cout << result;

	return 0;
}

