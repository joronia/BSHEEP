#include <iostream>
using namespace std;

int main() {
	int x, y = 0;
	int counter = 0;
	int num_tests = 0;
	int num_of_sheep = 0;
	cin >> num_tests;
	cout << endl;
	cout << "test" << endl;
	
		
	while (counter != num_tests) {
		cin >> num_of_sheep;
		for (int i = 0; i < num_of_sheep; i++) {
			cin >> x >> y;
		}
		cout << endl;
		counter++;
	}
}