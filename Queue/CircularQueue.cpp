#include <iostream>
using namespace std;

class CQueue
{
    private :
        int* que ;
        int queSize;
        int front;
        int rear;
    

    public :

        //동적 배열 할당 및 초기화
        CQueue(int size) 
        {

            front = 0;
            rear = 0;
            queSize = size;
            que = new int[size];
            for (int i =0; i<size; i++ )
            {
                que[i] = 0;
            }
        }

        //동적 배열 삭제
        ~CQueue()
        {
            delete[] que;
        }

        //enqueue
        void Enqueue(int addData)
        {
            if (IsFull())
            {
                cout << "Full\n";
            }
            else
            {
                que[rear] = addData;
                rear= (rear+1)% queSize;
            }
            
        }
        //dequeue
        void Dequeue()
        {
            if (IsEmpty())
            {
                cout << "Empty\n";
            }
            else
            {
                que[front] = 0;
                front= (front+1)% queSize;
            }
            
        }

        //count
        int Count()
        {
            return (rear - front + queSize) % queSize;
        }

        //front
        void GetFront()
        {
            if (IsEmpty())
                cout << "Empty\n";
            else
                cout << que[front];
        }

        //full
        bool IsFull()
        {
            
            if (front == (rear+1)%queSize)
                return true;
            else
                return false;
        }

        //empty
        bool IsEmpty()
        {
            
            if (front == rear)
                return true;
            else
                return false;
        }
        

};


int main()
{
    CQueue que(5);

    cout << que.IsEmpty() << "\n";
    cout << que.IsFull() << "\n";
    que.GetFront();
    que.Dequeue();
    que.Enqueue(5);
    que.Enqueue(6);
    que.Enqueue(7);
    que.Dequeue();
    que.GetFront();
    
    
}