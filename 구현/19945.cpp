#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int num_bits = 0;
	if (n == 0) {
		cout << 1 << '\n';
		return 0;
	}
	else if (n < 0) {
		cout << 32 << '\n';
		return 0;
	}

	while (n > 0) {
		n = n >> 1;
		num_bits++;
	}

	cout << num_bits << '\n';
	
	return 0;
}