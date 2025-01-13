#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(vector<char> list, char value) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == value) {
			return i;
		}
	}
	return -1;
}

int main() {
	string n;
	cin >> n;

	vector<char> the_number = { '2', '0', '1', '8' };
	vector<int> num_cnt(4, 0);

	// 관련
	for (char c : n) {
		int idx = find(the_number, c);
		if (idx != -1) {
			num_cnt[idx]++;
		}
		else {
			cout << "0\n";
			return 0; // 관련 없는 수
		}
	}

	// 밀접, 묶
	int supposed_same = num_cnt[0];
	for (int cnt : num_cnt) {
		//cout << cnt << " ";
		if (cnt == 0) {
			cout << "1\n";
			return 0;
		}
	}

	for (int cnt : num_cnt) {
		if (cnt != supposed_same) {
			cout << "2\n";
			return 0;
		}
	}

	cout << "8\n";


	return 0;
}