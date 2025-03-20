#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class DEQueue
{
    private:
        node* front;
        node* rear;
        int size;

    public:
        DEQueue()
        {
            front = nullptr;
            rear = nullptr;
            size = 0;
        }

        node* CreateNode(int addData)
        {
            node* newNode = new node;
            newNode->data = addData;
            newNode->next = nullptr;

            return newNode;
        }

        //enqueue
        void EnqueueFront(int addData)
        {
            node* newNode = CreateNode(addData);

            if (front == nullptr)
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                newNode->next = front;
                front = newNode;
            }
            size++;
            
        }
        void EnqueueRear(int addData)
        {
            node* newNode = CreateNode(addData);

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
        void DequeueFront()
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

        void DequeueRear()
        {
            if(front == nullptr)
            {
                cout << "empty\n";
            }
            else
            {
                node* tmp = front;
                
                
                while(tmp != rear)
                {
                    if( tmp->next == rear)
                    {
                        rear = tmp;
                        delete tmp->next;
                        tmp->next = nullptr;
                        break;
                    }

                    tmp = tmp->next;
                }
                size--;
            }
        }

        //size
        int Size()
        {
            return size;
        }

        //Front
        int GetFront()
        {
            return front->data;
        }

        int GetRear()
        {
            return rear->data;
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
    DEQueue que;
    que.EnqueueFront(1);
    que.EnqueueFront(2);
    que.EnqueueFront(3);
    que.EnqueueFront(4);
    que.DequeueFront();
    que.DequeueRear();

    que.GetFront();
    que.GetRear();
    cout << que.Size() <<"\n";
    cout << que.IsEmpty() <<"\n";

}