#include "1_3_BubbleSort.hpp"

int exec_1_3() {
	int arr[] = { 6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Print(arr, n);

	// Bubble Sort
	{
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
			}
			Print(arr, n);
		}
	}
	cout << endl;

	// Best case
	// ���� for���� ���鼭 �� ���� swap�� �Ͼ�� ���� ���
	{
		int arr[] = { 1,5,2,4,3 };
		int n = sizeof(arr) / sizeof(arr[0]);
		int count;
		for (int i = 0; i < n - 1; i++) {
			count = 0;
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
					count++;
				}
			}
			if (!count) {
				break;
			}

			Print(arr, n);
		}
		cout << "����: ";
		Print(arr, n);
	}

	// Stability
	// bubble sort�� �ٷ� ���� ���ؼ� ������ �� ū ��쿡�� swap�� �ϱ� ������ stable�ϴ�.
	{

	}

	return 0;
}