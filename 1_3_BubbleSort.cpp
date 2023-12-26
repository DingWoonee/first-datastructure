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
	// 안쪽 for문을 돌면서 한 번도 swap이 일어나지 않은 경우
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
		cout << "최종: ";
		Print(arr, n);
	}

	// Stability
	// bubble sort는 바로 옆과 비교해서 앞쪽이 더 큰 경우에만 swap을 하기 때문에 stable하다.
	{

	}

	return 0;
}