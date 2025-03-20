#include <iostream>
#include <vector>

using namespace std;


class Heap
{
    private :
        vector<int> heap;
        int size;

    public :
        Heap()
        {
            heap.push_back(0);
            size = 0;
        }

        void AddValue(int value)
        {
            heap.push_back(value);
            size ++;

            int i = size;
            int tmp;

            //MaxHeap
            while(i > 1 && heap[i] > heap[i/2]) // heap[i] <heap[1/2] <- MinHeap
            {
                tmp = heap[i];
                heap[i] = heap[i/2];
                heap[i/2] = tmp;

                i /= 2;
            }


        }
        void DeleteMax()
        {
            heap[1] = heap.back();
            heap.pop_back();
            size--;
            
            //자식노드값과 비교후 큰자식노드와 교환
            
            int i;
            int tmp;

            //MaxHeap
            while (i * 2 <= size)
            {
                int child = i * 2;
                
                // 오른쪽 자식이 있고, 오른쪽 자식이 더 큰 경우
                if (child + 1 <= size && heap[child] < heap[child + 1])
                {
                    child++;
                }

                // 현재 노드가 더 크면 힙 조건 만족, 반복 종료
                if (heap[i] >= heap[child])
                {
                    break;
                }

                // 현재 노드와 더 큰 자식 노드 교환
                tmp = heap[i];
                heap[i] = heap[child];
                heap[child] = tmp;

                // 인덱스를 자식 노드로 이동
                i = child;
            }
                    
        }

        void PrintHeap()
        {
            int i = 1;
            int level = 1;

            while(i <= size)
            {
                for (int j = 0; j < level && i <= size; j++)
                {
                    cout << heap[i++] << " ";
                }

                // 한 레벨의 노드를 출력한 후 줄바꿈
                cout << "\n";

                // 레벨을 증가시키고, 다음 레벨에서는 두 배 더 많은 노드를 출력
                
                level *= 2;
            }
        }
};

int main()
{
    Heap h;

    h.AddValue(1);
    h.AddValue(12);
    h.AddValue(3);
    h.AddValue(15);
    h.AddValue(44);
    h.AddValue(4);
    h.AddValue(43);
    h.AddValue(42);
    h.AddValue(32);
    h.PrintHeap();


    h.DeleteMax();
    h.DeleteMax();
    h.DeleteMax();
    h.DeleteMax();

    h.PrintHeap();
}