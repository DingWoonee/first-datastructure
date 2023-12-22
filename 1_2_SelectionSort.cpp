#include "1_2_SelectionSort.hpp"

struct Element {
	int key;
	char value;
};

bool CheckSorted(int* arr, int size) {
	// TODO: 정렬 확인 함수 구현
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

void Print(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int exec_1_2() {
	// 3개 정렬
	{
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				for (int i = 0; i < 3; i++) {
					int arr[3] = { i,j,k };
					int size = sizeof(arr) / sizeof(arr[0]);

					for (int e = 0; e < size; e++) {
						// std::endl은 '\n'을 출력하고 그 다음에 std::flush를 호출한다는 의미이다.
						cout << arr[e] << " " << flush;
					}

					cout << " -> " << flush;

					//TODO: 정렬 해보기
					if (arr[0] > arr[1]) swap(arr[0], arr[1]);
					if (arr[1] > arr[2]) swap(arr[1], arr[2]);
					if (arr[0] > arr[1]) swap(arr[0], arr[1]);

					for (int e = 0; e < size; e++) {
						cout << arr[e] << " " << flush;
					}

					cout << boolalpha;
					cout << CheckSorted(arr, size); //정렬 되었나 확인
					cout << endl;
				}
			}
		}
		cout << endl;
	}

	// 가장 작은 수 하나 찾기
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		int minNum = arr[0];
		for (int i = 1; i < size; i++) {
			//if (minNum > arr[i]) minNum = arr[i];
			//std::min(arr[i], minNum);
			minNum = minNum > arr[i] ? arr[i] : minNum;
		}

		cout << "Minimum number is " << minNum << endl << endl;
	}

	// 가장 작은 수의 인덱스 찾기
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		int minIndex = 0;
		for (int i = 1; i < size; i++) {
			/*if (arr[minIndex] > arr[i]) {
				minIndex = i;
			}*/
			minIndex = arr[minIndex] > arr[i] ? i : minIndex;
		}

		cout << "The index of min is " << minIndex << endl;
		cout << "Minimum number is " << arr[minIndex] << endl << endl;
	}

	// Selection Sort
	// 힌트: swap();
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		Print(arr, size);

		int min_index;
		for (int i = 0; i < size - 1; i++) {
			int min_index = i;
			for (int j = i + 1; j < size; j++) {
				if (arr[min_index] > arr[j])
					min_index = j;
			}
			if (min_index != i)
				swap(arr[min_index], arr[i]);

			Print(arr, size);

			cout << boolalpha;
			cout << CheckSorted(arr, size);
			cout << endl;
		}
	}

	return 0;
}