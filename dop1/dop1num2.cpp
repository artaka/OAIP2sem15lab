#include <iostream>
#include <chrono>
using namespace std;

int n = 0; //array size

void createArray(int n, int array[]) {
	for (int i = 0; i != n;++i) {
		array[i] = rand() % 1000;
	}
}

void selectionSort(int array[], int n) {
	int index = 0;
	int temp = 0;
	for (int i = 0;i != n;++i) {
		index = i;
		for (int j = i;j < n;++j) {
			if (array[j] < array[index]) {
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	cout << "������� ����� N(���-�� �����):";
	cin >> n;

	int array[10000];
	createArray(n, array);

	cout << "������:" << endl;
	for (int i = 0; i != n;++i) {
		cout << array[i] << " ";
	}

	auto selectionStart = chrono::steady_clock::now();
	selectionSort(array, n);
	auto selectionTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - selectionStart);
	cout << endl << endl << "��������������� ������� ������:" << endl;
	for (int i = 0;i != n;++i) {
		cout << array[i] << " ";
	}

	cout << endl << endl << endl <<
		"����������� �����:" << endl;
	cout << "���������� �������: " << selectionTime.count() << " ���" << endl;
}