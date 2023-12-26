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

	// 비교 횟수 세보기, 더 효율적인 방법은 없을까?
	{
		ofstream ofile("log.txt");
		for (int size = 1; size < 1000; size++) {
			int count = 0;
			int* arr = new int[size];
			for (int s = 0; s < size; s++) {
				arr[s] = size - s;
			}

			int min_index;
			for (int i = 0; i < size - 1; i++) {
				min_index = i;
				for (int j = i + 1; j < size; j++) {
					count++;
					if (arr[j] < arr[min_index])
						min_index = j;
				}
				swap(arr[i], arr[min_index]);
			}

			//cout << size << ", " << count << endl;
			ofile << size << ", " << count << endl;
			//Print(arr, size);

			delete[] arr;
		}
		ofile.close();
	}

	// 정렬의 안정성 확인(unstable)
	// Element에서 val에 상관없이 key를 기준으로 정렬함.
	// 여기서 key는 둘다 2이지만 값이 다른 두 요소의 순서가 바뀌었음.
	// 이는 stable하지 않은 정렬임. 안정적인 정렬 알고리즘은 동일한 값을 가진 요소들 사이의 원래 순서를 변경하지 않는다.
	{
		Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
		int size = sizeof(arr) / sizeof(arr[0]);

		int min_index;
		for (int i = 0; i < size - 1; i++) {
			min_index = i;
			for (int j = i + 1; j < size; j++) {
				if (arr[j].key < arr[min_index].key)
					min_index = j;
			}
			swap(arr[i], arr[min_index]);
		}
	}

	return 0;
}