#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class Stack
{
    private:
        node* head;
        int size;
        
    public:
        Stack()
        {
            head = nullptr;
            size = 0;
        }

        //push
        void Push(int addData)
        {
            node* newNode = new node;
            newNode->data = addData;
            newNode->next = nullptr;

            if(head == nullptr)
            {
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

    //pop
    void Pop()
    {
        if(head == nullptr)
        {
            cout << "empty\n";
        }
        else
        {
            node* tmp = head;
            head = head->next;

            delete tmp;
            size--;
        }
        
    }

    //size
    int Size()
    {
        return size;
    }

    //top
    int Top()
    {
        return head->data;
    }

    //empty
    bool IsEmpty()
    {
        if (size > 0)
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
    Stack stk;
    cout << stk.IsEmpty() <<"\n";
    stk.Push(1);
    stk.Push(2);
    stk.Push(3);
    stk.Push(4);
    stk.Push(5);
    stk.Push(6);
    cout << stk.Top() <<"\n";
    stk.Pop();
    stk.Pop();
    stk.Pop();
    cout << stk.Top() <<"\n";
    cout << stk.IsEmpty();
    cout << stk.Size();

}
