#include "1_5_SequentialSearch.hpp"

//�迭 arr�� x�� �� �� �������� ��ȯ
int Count(int* arr, int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += arr[i] == x;
	}
	return count;
}

// �迭 arr�� x�� ������ index ��ȯ, ������ -1 ��ȯ
int SequentialSearch(int* arr, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x)
			return i;
	}
	return -1;
}

int SortedCountHelper(int* arr, int n, int x, int start) { // start ���
	int count = 0;
	for (int i = start; i < n; i++) {
		if (arr[i] != x)
			return count;
		count++;
	}
	return count;
}

int SortedCount(int* arr, int n, int x) {
	int i = SequentialSearch(arr, n, x);

	if (i >= 0)
		return SortedCountHelper(arr, n, x, i + 1) + 1;
	else
		return 0;
}

int exec_1_5() {
	//���ĵ��� ���� �����͸� ����

	int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// ������ �˰����̳� �ڷᱸ���� ������ ����
	// �Ǽ��� ���ɼ��� ���� �ܼ��� ����� �������� ��ƿ�.

	cout << "Count 9 = " << Count(arr, n, 9) << endl;
	cout << "Count 2 = " << Count(arr, n, 2) << endl;
	cout << "Count 8 = " << Count(arr, n, 8) << endl;
	cout << "Count 1 = " << Count(arr, n, 1) << endl;
	cout << endl;

	cout << "Search 2 = " << SequentialSearch(arr, n, 2) << endl;
	cout << "Search 5 = " << SequentialSearch(arr, n, 5) << endl;
	cout << "Search 9 = " << SequentialSearch(arr, n, 9) << endl;
	cout << endl;

	InsertionSort(arr, n);

	Print(arr, n);

	cout << "Sorted Count 9 = " << SortedCount(arr, n, 9) << endl;
	cout << "Sorted Count 2 = " << SortedCount(arr, n, 2) << endl;
	cout << "Sorted Count 8 = " << SortedCount(arr, n, 8) << endl;
	cout << "Sorted Count 1 = " << SortedCount(arr, n, 1) << endl;
	cout << endl;

	return 0;

}