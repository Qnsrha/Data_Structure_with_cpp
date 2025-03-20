#include <iostream>
#include <Windows.h>

//콘솔 한글 출력 필요

using namespace std;

class ArrayList
{
    private :
        int* arr;
        int arrSize;
        int count;

    public :

        //동적 배열 할당 및 초기화
        ArrayList(int size) 
        {
            
            arrSize =size;
            count = size;

            arr = new int[size];
            for (int i =0; i<size; i++ )
            {
                arr[i] = i;
            }
        }

        //동적 배열 삭제
        ~ArrayList()
        {
            delete[] arr;
        }


        
        void insertValue(int value, int idx)
        {
            //배열크기가 초과되면 두배크기로 새로생성 후 값 복사
            if (arrSize <= count)
            {
                int* temp = new int[arrSize*2];

                for (int i =0; i < arrSize*2; i++)
                {
                    if (i < arrSize)
                    {
                        temp[i] = arr[i];
                    }
                    else
                    {
                        temp[i] = 0;
                    }
                }

                delete[] arr;

                arr = temp;

                arrSize = arrSize*2;
                
            }

            //추가할 위치에서 우측 값들을 한칸씩 우측으로 이동
            for (int i = arrSize -1; i > idx; i--)
            {
                arr[i] = arr[i-1];
            }

            arr[idx] = value;
            count++;

        }

        
        void deleteValue(int idx)
        {
            //삭제할 위치에서 우측 값들을 한칸씩 좌측으로 이동
            for(int i = idx; i < arrSize; i++)
            {
                if(i == arrSize-1)
                {
                    arr[i] = 0;
                }
                else
                {
                    arr[i] = arr[i+1];
                }
            }
            count --;
        }

        
        void changeValue(int value, int idx)
        {
            arr[idx] = value;
        }

        
        void printValue(int idx)
        {
            cout << arr[idx] << endl;
        }

        
        void printArray()
        {
            for (int i =0; i < arrSize; i++)
            {
                cout << arr[i] << endl;
            }
        }

        
        void printArraySize()
        {
            cout << arrSize << endl;
        }
};

int main()
{
    int num = 0;
    int value = 0;
    int idx = 0;
    int size = 0;
    char ch;


    cout << "set the array size. (value greater than or equal 1)\n";
    cin >> size;
    system("cls"); 
    
    while (size < 1)
    {
        cout << "Enter an integer greater than or equal to 1.\n" ;
        cin >> size;
    }

    ArrayList arr1(size);

    while (1)
    {

        cout << "1.insert value\n2.delete value\n3.change value\n4.print value\n5.print array size\n6.print array\n7.exit\n";
        cin >> num;
        system("cls");

        switch(num)
        {
            case 1:
            cout << "input value and index.\n";
            cin >> value >> idx;
            system("cls"); 
            arr1.insertValue(value, idx);
            break;

            case 2: 
            cout << "input index.\n";
            cin >>idx;
            system("cls"); 
            arr1.deleteValue(idx);
            break;

            case 3:
            cout << "input value and index.\n";
            cin >> value >> idx;
            system("cls"); 
            arr1.changeValue(value, idx);
            break;

            case 4:
            cout << "input index.\n";
            cin >>idx;
            system("cls");  
            arr1.printValue(idx);
            break;

            case 5: 
            arr1.printArraySize();
            //TODO WAIT INPUT
            break;

            case 6:
            arr1.printArray();
            //TODO WAIT INPUT
            break;

            case 7: return 0;
            break;

            default :
            cout << "enter the number given.";
            break;

        }
    }
}