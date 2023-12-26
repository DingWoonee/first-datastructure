#include "1_4_InsertionSort.hpp"

void InsertionSort(int* arr, int n) {
	int i, j, num;
	for (i = 1; i < n; i++) {
		num = arr[i];
		for (j = i; j > 0 && arr[j - 1] > num; j--) {
			arr[j] = arr[j - 1];
		}

		// ����
		arr[j] = num;
	}
}

int exec_1_4() {
	// ���� ����(insertion sort)
	{
		int arr[] = { 6,5,4,3,2,1 };
		int n = sizeof(arr) / sizeof(arr[0]);

		Print(arr, n);

		int i, j, num;
		for (i = 1; i < n; i++) {
			num = arr[i];
			for (j = i; j > 0 && arr[j - 1] > num; j--) {
				arr[j] = arr[j - 1];

				cout << "Inner ";
				Print(arr, n);
			}

			// ����
			arr[j] = num;

			cout << "Outer ";
			Print(arr, n);
		}
		
		Print(arr, n);
		cout << endl;
	}

	// Stability
	// arr[j - 1] > num �̺κп��� ������ ū ��쿡��(���� ���� �׷��� ����) shift�� �ϱ� ������ insertion sort�� stable�ϴ�.
	// ���� bubble sort�� swap(3steps)�� �ϴ� �ݸ鿡 insertion sort�� shift�̱� ������ ���������� �� �����ϴ�.

	return 0;
}