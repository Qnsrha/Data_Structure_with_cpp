#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class LQueue
{
    private:
        node* front;
        node* rear;
        int size;

    public:
        LQueue()
        {
            front = nullptr;
            rear = nullptr;
            size = 0;
        }

        //enqueue
        void Enqueue(int addData)
        {
            node* newNode = new node;
            newNode->data = addData;
            newNode->next = nullptr;

            if (front == nullptr)
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
            
        }

        //dequeue
        void Dequeue()
        {
            if(front == nullptr)
            {
                cout << "empty\n";
            }
            else
            {
                node* tmp = front;
                front = front->next;

                delete tmp;
                size--;
            }
        }

        //size
        int Size()
        {
            return size;
        }

        //Front
        int Front()
        {
            return front->data;
        }

        //empty
        bool IsEmpty()
        {
            if (size >0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

};

int main()
{
    LQueue que;

    que.Enqueue(1);
    que.Enqueue(2);
    que.Enqueue(3);
    que.Enqueue(4);
    que.Enqueue(5);
    que.Dequeue();
    que.Dequeue();
    que.Dequeue();
    cout << que.Front() <<"\n";
    cout << que.Size() <<"\n";
    cout << que.IsEmpty() <<"\n";

}