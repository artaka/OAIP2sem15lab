#include <iostream>
#include <chrono>
#include <Windows.h>
using namespace std;
int n = 10;

void createArray(int n, int array[]) {
	for (int i = 0; i != n;++i) {
		array[i] = rand() % 1000;
	}
}

void bubbleSort(int array[], int n) {
	int temp = 0;
	for (int i = 0;i != n;++i) {
		for (int j = 1;j != n - i;++j) {
			if (array[j] < array[j - 1]) {
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}

		}
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

void quickSort(int array[], int left, int right) {
	int pivot;
	int index;
	int lHold = left;
	int rHold = right;
	pivot = array[left];

	while (right > left) {
		while ((array[right] > pivot) && right > left) {
			--right;
		}
		if (left != right) {
			array[left] = array[right];
			left++;
		}
		while ((array[left] < pivot) && right > left) {
			++left;
		}
		if (left != right) {
			array[right] = array[left];
			--right;
		}
	}

	array[left] = pivot;
	index = left;
	left = lHold;
	right = rHold;
	if (left < index) {
		quickSort(array, left, index - 1);
	}
	if (right > index) {
		quickSort(array, index + 1, right);
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
	SetConsoleOutputCP(CP_UTF8);
	cout << "Введите число N:";
	cin >> n;

	int array[10000];
	createArray(n, array);

	int B[10000], C[10000], D[10000], E[10000], F[10000];

	for (int i = 0; i != n;++i) {
		B[i] = array[i];
	}

	for (int i = 0; i != n;++i) {
		C[i] = array[i];
	}

	for (int i = 0; i != n;++i) {
		D[i] = array[i];
	}

	for (int i = 0; i != n;++i) {
		E[i] = array[i];
	}

	for (int i = 0; i != n;++i) {
		F[i] = array[i];
	}

	cout << "Исходный массив:" << endl;
	for (int i = 0; i != n;++i) {
		cout << array[i] << " ";
	}

	auto buble = chrono::steady_clock::now();
	bubbleSort(B, n);
	auto bubleTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - buble);
	cout << endl << endl << "Отсортированный пузырьком массив:" << endl;
	for (int i = 0;i != n;++i) {
		cout << B[i] << " ";
	}

	auto insert = chrono::steady_clock::now();
	insertSort(C, n);
	auto insertTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - insert);
	cout << endl << "Отсортированный вставкой массив:" << endl;
	for (int i = 0;i != n;++i) {
		cout << C[i] << " ";
	}

	auto selection = chrono::steady_clock::now();
	selectionSort(D, n);
	auto selectionTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - selection);
	cout << endl << "Отсортированный выбором массив:" << endl;
	for (int i = 0;i != n;++i) {
		cout << D[i] << " ";
	}

	auto quick = chrono::steady_clock::now();
	quickSort(E, 0, n - 1);
	auto quickTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - quick);
	cout << endl << "Отсортированный быстрой сортировкой массив:" << endl;
	for (int i = 0;i != n;++i) {
		cout << E[i] << " ";
	}

	auto shellStart = chrono::steady_clock::now();
	Shell(F, n);
	auto shellTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - shellStart);
	cout << endl << endl << "Отсортированный сортировкой шелла массив:" << endl;
	for (int i = 0;i != n;++i) {
		cout << F[i] << " ";
	}

	cout << endl << endl << endl <<
		"Время сортировок:" << endl;
	cout << "Пузырьковая сортировка: " << bubleTime.count() << " мкс" << endl;
	cout << "Сортировка вставкой: " << insertTime.count() << " мкс" << endl;
	cout << "Сортировка выбором: " << selectionTime.count() << " мкс" << endl;
	cout << "Быстрая сортировка: " << quickTime.count() << " мкс" << endl;
	cout << "Сортировка методом шелла: " << shellTime.count() << " мкс" << endl;
}