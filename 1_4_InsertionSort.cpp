#include "1_4_InsertionSort.hpp"

void InsertionSort(int* arr, int n) {
	int i, j, num;
	for (i = 1; i < n; i++) {
		num = arr[i];
		for (j = i; j > 0 && arr[j - 1] > num; j--) {
			arr[j] = arr[j - 1];
		}

		// 삽입
		arr[j] = num;
	}
}

int exec_1_4() {
	// 삽입 정렬(insertion sort)
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

			// 삽입
			arr[j] = num;

			cout << "Outer ";
			Print(arr, n);
		}
		
		Print(arr, n);
		cout << endl;
	}

	// Stability
	// arr[j - 1] > num 이부분에서 앞쪽이 큰 경우에만(같은 경우는 그러지 않음) shift를 하기 때문에 insertion sort는 stable하다.
	// 또한 bubble sort는 swap(3steps)를 하는 반면에 insertion sort는 shift이기 때문에 내부적으로 더 간단하다.

	return 0;
}