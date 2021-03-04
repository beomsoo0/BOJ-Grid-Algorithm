#include <iostream>
#include <algorithm>

using namespace std;


int main() {

	int N, max;
	cin >> N;
	int* data = new int[N];


	for (int i = 0; i < N; i++) {
		cin >> data[i];
	}

	sort(data, data + N);

	max = data[0] * N;
	for (int i = 1; i < N; i++) {
		if (data[i] * (N - i) > max) {
			max = data[i] * (N - i);
		}
	}
	
	cout << max;

	delete[] data;
	return 0;
}