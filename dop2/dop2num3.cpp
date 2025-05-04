#include <iostream>
#include <chrono>
using namespace std;

int n = 0; //array size

void createArray(int n, int array[]) {
	for (int i = 0; i != n;++i) {
		array[i] = rand() % 1000;
	}
}

void insertSort(int array[], int n) {
	int temp = 0;
	for (int i = 0;i != n;++i) {
		temp = array[i];
		for (int j = i - 1;j >= 0;--j) {
			if (array[j] > temp) {
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	cout << "Введите число N(кол-во чисел):";
	cin >> n;

	int array[10000];
	createArray(n, array);

	cout << "Массив:" << endl;
	for (int i = 0; i != n;++i) {
		cout << array[i] << " ";
	}

	auto insertStart = chrono::steady_clock::now();
	insertSort(array, n);
	auto insertTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - insertStart);
	cout << endl << endl << "Отсортированный вставкой массив:" << endl;
	for (int i = 0;i != n;++i) {
		cout << array[i] << " ";
	}

	cout << endl << endl << endl <<
		"Затраченное время:" << endl;
	cout << "Сортировка вставкой: " << insertTime.count() << " мкс" << endl;
}