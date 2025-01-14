#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct student {
	int time;
	int score;
};

long long computeRSS(vector<student>& students, int a, int b) {
	long long rss = 0;
	long long temp;
	for (int i = 0; i < students.size(); i++) {
		temp = students[i].score - (a * students[i].time + b);
		rss += temp * temp;
	}
	return rss;
}

int main() {
	int n;
	cin >> n;
	
	vector<student> students(n);
	for (int i = 0; i < n; i++) {
		cin >> students[i].time >> students[i].score;
	}

	int min_a = 101;
	int min_b = 101;
	long long curr_rss = LLONG_MAX;
	long long temp_rss = 0;
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			temp_rss = computeRSS(students, a, b);
			
			if (curr_rss > temp_rss) {
				curr_rss = temp_rss;
				min_a = a;
				min_b = b;
			}
		}
	}
	
	cout << min_a << " " << min_b;
	

	return 0;
}