#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {

	int begintime;
	int endtime;
};

bool compare(Time a, Time b) {
	if (a.endtime == b.endtime) {
		return a.begintime < b.begintime;
	}
	else {
		return a.endtime < b.endtime;
	}
}

int main() {
	int N;
	cin >> N;

	vector<Time> t(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i].begintime >> t[i].endtime;
	}
	sort(t.begin(), t.end(), compare);

	int count = 0;
	int n = 0;

	for (int i = 0; i < t.size(); i++) {
		if (n <= t[i].begintime) {
			count++;
			n = t[i].endtime;
		}
	}

	cout << count;

	return 0;
}