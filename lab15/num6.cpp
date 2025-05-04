#include <iostream>
#include <chrono>
using namespace std;

int n = 0; //array size

void createArray(int n, int array[]) {
	for (int i = 0; i != n;++i) {
		array[i] = rand() % 1000;
	}
}

void bubbleSort(int array[], int n) {
	int temp = 0;
	for (int i = 0;i != n;++i) {
		for (int j = 1;j != n - i;++j) {
			if (array[j] > array[j - 1]) {
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}

		}
	}
}

void quickSort(int array[], int left, int right) {
	int pivot;
	int index;
	int lHold = left;
	int rHold = right;
	pivot = array[left];

	while (right > left) {
		while ((array[right] < pivot) && right > left) {
			--right;
		}
		if (left != right) {
			array[left] = array[right];
			left++;
		}
		while ((array[left] > pivot) && right > left) {
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

int main() {
	setlocale(LC_ALL, "RU");
	cout << "Введите число N(кол-во чисел):";
	cin >> n;

	int array[10000];
	createArray(n, array);
	int B[10000], Bcopy[10000];

	cout << "Массив А:" << endl;
	for (int i = 0; i != n;++i) {
		cout << array[i] << " ";
	}

	int maxIndex = 0; // find max item
	for (int i = 1;i != n;++i) {
		if (array[maxIndex] < array[i]) {
			maxIndex = i;
		}
	}

	// fill array B with items to right of the max item and have even index
	int Bsize = 0;
	for (int i = maxIndex+1; i != n;++i) {
		if (i % 2 == 0) {
			B[Bsize++] = array[i];
		}
	}

	for (int i = 0;i != Bsize;++i) {
		Bcopy[i] = B[i];
	}

	auto bubbleStart = chrono::steady_clock::now();
	bubbleSort(B, Bsize);
	auto bubbleTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - bubbleStart);
	cout << endl << endl << "Отсортированный пузырьком массив:" << endl;
	if (Bsize == 0) {
		cout << "Массив пуст!";
	}
	else {
		for (int i = 0;i != Bsize;++i) {
			cout << B[i] << " ";
		}
	}


	auto quickStart = chrono::steady_clock::now();
	quickSort(Bcopy, 0, Bsize - 1);
	auto quickTime = chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - quickStart);
	cout << endl << endl << "Отсортированный быстро массив:" << endl;
	if (Bsize == 0) {
		cout << "Массив пуст!";
	}
	else {
		for (int i = 0;i != Bsize;++i) {
			cout << Bcopy[i] << " ";
		}
	}

	cout << endl << endl << endl <<
		"Затраченное время:" << endl;
	cout << "Пузырьковая сортировка: " << bubbleTime.count() << " мкс" << endl;
	cout << "Быстрая сортировка: " << quickTime.count() << " мкс" << endl;
}