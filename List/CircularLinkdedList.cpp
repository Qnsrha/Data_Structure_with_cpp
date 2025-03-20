#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class CLList
{
    private :

        //끝노드를 가르킴
        node* tail;

    public :
        CLList()
        {
            tail = nullptr;
        }
        //노드생성
        node* CreateNode(int addData)
        {
            node* newNode = new node;
            newNode->data = addData;
            newNode->next = nullptr;

            return newNode;
        }

        //노드 추가
        void AddFront(int addData)
        {
            node* newNode = CreateNode(addData);

            //첫노드
            if (tail == nullptr)            
            {
                tail = newNode;
                tail->next = tail;             
            }
            else  
            { 
                newNode->next = tail->next;
                tail->next = newNode;

            }
        }
        
        void AddBack(int addData)
        {
            node* newNode = CreateNode(addData);

            //첫노드
            if (tail == nullptr)            
            {
                tail = newNode;
                tail->next = tail;             
            }
            else  
            { 
                newNode->next = tail->next;
                tail->next = newNode;
                tail = newNode;
            }
        }

        void Insert(node* prevNode, int addData)
        {
            if (prevNode == nullptr)
            {
                cout << "이전노드 주솟값 nullptr\n";
            }
            else
            {
                node* newNode = CreateNode(addData);

                newNode->next = prevNode->next;
                prevNode->next = newNode;

                if(prevNode == tail)
                {
                    tail = newNode;
                }
            }
            

        }

        //첫노드 삭제
        void Delete()
        {
            if (tail == nullptr)
            {
                cout << "노드가 없습니다.\n";
            }
            //노드 하나일때
            if (tail->next == nullptr)
            {
                delete tail;
                tail = nullptr;
            }
            else
            {
                node* tmp = tail->next;
                tail->next = tmp->next;

                delete tmp;
            }
        }

        //노드삭제
        void Delete(node* prevNode)
        {
            //노드 없을때
            if (tail == nullptr)
            {
                cout << "노드가 없습니다.\n";
            }
            else if (prevNode == nullptr)
            {
                cout << "이전노드 주솟값 nullptr\n";
            }
            else
            {
                node* tmp = prevNode->next;
                prevNode->next = tmp->next;
                
                //끝노드 지울때
                if(tail == prevNode->next)
                {
                    tail = prevNode;
                }

                delete tmp;
            }
            
            
            
        }
        //데이터 검색
        node* Find(int findData)
        {
            node* curNode = tail;
            if (tail == nullptr)
            {
                cout << "노드가 없습니다.";
                return nullptr;
            }
            else
            {
                do
                {
                    if(curNode->data == findData)
                    {
                        return curNode;
                    }
                    curNode = curNode->next;
                } while (curNode != tail);
                
                cout << "값을 찾을 수 없습니다.\n";
                return nullptr;
                
            }
            
            
        }
        //tail
        node* GetTail()
        {
            return tail;
        }

        //리스트 출력
        void PrintList(node* tail)
        {
            node* curNode = tail;
            
            if (tail == nullptr)
            {
                cout << "NULL\n";
            }
            else
            {
                while (curNode->next != tail)
                {
                    cout << curNode->next->data << " -> ";
                    curNode = curNode->next;
                }
                cout << curNode->next->data << " -> head\n";
                
                 
            }
            
            
        }

};

int main()
{
    CLList list;

    
    list.PrintList(list.GetTail());
    list.AddFront(1);
    list.Delete();
    list.AddFront(2);
    list.AddFront(3);
    list.Insert(list.Find(2), 5);
    list.PrintList(list.GetTail());
    list.Delete();
    list.PrintList(list.GetTail());
    cout << list.GetTail();
}