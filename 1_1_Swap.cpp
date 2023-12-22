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
        // cout - 콘솔 출력. 
        // << 연산자 - 스트림 삽입 연산자 또는 스트림 출력 연산자.(std::cout 객체에 값을 삽입하여 출력하게 함. 
        //std::endl - 엔드라인. 줄바꿈 문자와 같은 역할을 한다.

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