#include <iostream>
#include <chrono>
using namespace std;

int n = 0; //array size

void createArray(int n, int array[]) {
	for (int i = 0; i != n;++i) {
		array[i] = rand() % 1000;
	}
}

void Shell(int A[], int n) {
	int d = n;
	d = d / 2;
	while (d > 0) {
		for (int i = 0; i < n - d; i++) {
			int j = i;
			while (j >= 0 && A[j] > A[j + d]) {
				int temp = A[j];
				A[j] = A[j + d];
				A[j + d] = temp;
				j--;
			}
		}
		d = d / 2;
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

	auto shellStart = chrono::steady_clock::now();
	Shell(array, n);
	auto shellTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - shellStart);
	cout << endl << endl << "��������������� ������� ����� ������:" << endl;
	for (int i = 0;i != n;++i) {
		cout << array[i] << " ";
	}

	cout << endl << endl << endl <<
		"����������� �����:" << endl;
	cout << "���������� ������� �����: " << shellTime.count() << " ���" << endl;
}