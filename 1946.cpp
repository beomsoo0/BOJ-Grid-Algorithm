#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {

	int paper;
	int interview;
};

bool compare(const Point& p1, const Point& p2) {
	
	return p1.paper < p2.paper;
}

int solution() {

	int  people_num;
	int temp;
	int count = 0;
	
	cin >> people_num;

	vector <Point> p(people_num);
	for (int i = 0; i < people_num; i++) {
		cin >> p[i].paper >> p[i].interview;
	}
	sort(p.begin(), p.end(), compare);
	temp = p[0].interview;
	count++;
	for (int i = 1; i < people_num; i++) {
		
		if (p[i].interview < temp) {
			count++;
			temp = p[i].interview;
		}
	}
	p.clear();

	return count;
}



int main() {

	int test_num;
	cin >> test_num;

	for (int i = 0; i < test_num; i++) {
		cout << solution() << endl;
	}


	return 0;
}