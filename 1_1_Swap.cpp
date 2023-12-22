#include "1_1_Swap.hpp"

void MySwapPtr(int* a, int* b);
void MySwapRef(int& a, int& b);
std::string CheckSorted(int num1, int num2);

using namespace std;

int exec_1_1()
{
    //Swap
    {
        int a = 3;
        int b = 2;
        cout << a << " " << b << endl;
        //std - namespace. 
        // cout - �ܼ� ���. 
        // << ������ - ��Ʈ�� ���� ������ �Ǵ� ��Ʈ�� ��� ������.(std::cout ��ü�� ���� �����Ͽ� ����ϰ� ��. 
        //std::endl - �������. �ٹٲ� ���ڿ� ���� ������ �Ѵ�.

        //TODO
        MySwapPtr(&a, &b);
        MySwapRef(a, b);
        swap(a, b);

        cout << a << " " << b << endl;
    }

    //Sorting
    {
        int arr[] = { 9, 3 };

        cout << arr[0] << " " << arr[1] << endl;

        if (arr[0] > arr[1])
            MySwapRef(arr[0], arr[1]);

        cout << arr[0] << " " << arr[1] << endl;
    }

    //
    {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << j << " " << i << " " << CheckSorted(j, i) << endl;
            }
        }
    }

    return 0;
}
void MySwapPtr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void MySwapRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
std::string CheckSorted(int num1, int num2) {
    if (num1 > num2) {
        return "false";
    }
    else {
        return "true";
    }
}