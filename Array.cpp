#include <iostream>
using namespace std;

class Arr
{
    private :
        int* arr;
        int arrSize;
        bool dynamic;
    

    public :

        //정적 배열 할당 및 초기화
        Arr() 
        {
            dynamic = false; // 정적 배열을 사용한다고 표시
            arrSize = 5;
            static int sArr[5] = {0,};  // 정적 배열
            arr = sArr;  // sArr의 주소를 arr에 할당
        }

        // 동적 배열 할당 및 초기화
        Arr(int size) 
        {
            dynamic = true; // 동적 배열을 사용한다고 표시
            arrSize = size;
            arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = 0; // 초기화
            }
        }

        // 복사 생성자
        Arr(const Arr& other) 
        {
            dynamic = other.dynamic;
            arrSize = other.arrSize;
            
            if (dynamic) 
            {
                arr = new int[arrSize];
                for (int i = 0; i < arrSize; i++) 
                {
                    arr[i] = other.arr[i];
                }
            } 
            else 
            {
                arr = other.arr;  // 정적 배열은 주소만 복사
            }
        }

        // 대입 연산자
        Arr& operator=(const Arr& other) 
        {
            if (this == &other) 
                return *this;

            if (dynamic) 
            {
                delete[] arr;  // 기존 배열 메모리 해제
            }

            dynamic = other.dynamic;
            arrSize = other.arrSize;

            if (dynamic) 
            {
                arr = new int[arrSize];
                for (int i = 0; i < arrSize; i++) 
                {
                    arr[i] = other.arr[i];
                }
            } 
            else 
            {
                arr = other.arr;  // 정적 배열은 주소만 복사
            }

            return *this;
        }

        // 동적 배열 삭제
        ~Arr() 
        {
            if (dynamic) 
            {
                delete[] arr;
            }
        }

        // 값 설정
        void SetValue(int setValue, int idx) 
        {
            if (idx >= 0 && idx < arrSize) 
            {
                arr[idx] = setValue;
            } 
            else 
            {
                cout << "Index out of bounds!" << endl;
            }
        }

        // 값 출력
        void PrintValue(int idx) 
        {
            if (idx >= 0 && idx < arrSize) 
            {
                cout << arr[idx] << endl;
            } 
            else 
            {
                cout << "Index out of bounds!" << endl;
            }
        }

        // 배열 전체 출력
        void PrintArray() 
        {
            for (int i = 0; i < arrSize; i++) 
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // 배열 크기 출력
        void PrintArraySize() 
        {
            cout << arrSize << endl;
        }

};


int main()
{
    Arr arr1; // 정적 배열
    arr1.SetValue(10, 0);
    arr1.SetValue(20, 1);
    arr1.PrintArray(); // 10 20 0 0 0

    Arr arr2(3); // 동적 배열
    arr2.SetValue(5, 0);
    arr2.SetValue(15, 1);
    arr2.PrintArray(); // 5 15 0

    Arr arr3 = arr2; // 복사 생성자 호출
    arr3.PrintArray(); // 5 15 0

    return 0;
}