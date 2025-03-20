#include <iostream>

using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};

class DLList
{
    private: 
        node* head;
        node* tail;

    public:
        DLList()
        {
            head = nullptr;
            tail = nullptr;
        }

        //노드생성
        node* CreateNode(int addData)
        {
            node* newNode = new node;
            newNode->data = addData;
            newNode->next = nullptr;
            newNode->prev = nullptr;

            return newNode;
        }

        //노드추가
        void AddFront(int addData)
        {
            node* newNode = CreateNode(addData);

            //첫노드
            if (head == nullptr)
            {
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                               
            }
            head = newNode; 
        }
        
        void AddBack(int addData)
        {
            node* newNode = CreateNode(addData);

            //첫노드
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
            }

            tail = newNode;
        }
        
        void Insert(node* prevNode, int addData)
        {
            //맨앞에 삽입 시
            if (prevNode == nullptr)
            {
                cout << "이전노드 주솟값 nullptr\n";
            }
            else
            {
                node* newNode = CreateNode(addData);

                newNode->next = prevNode->next;
                prevNode->next = newNode;

                newNode->prev = prevNode;

                //맨뒤에 삽입 시
                if (prevNode == tail) // (prevNode->next == nullptr)
                {
                    tail = newNode;
                }
                else
                {
                    newNode->next->prev = newNode;
                }
            }
        }

        //노드삭제
        void Delete(node* curNode)
        {
            //노드 없을때
            if (head == nullptr)
            {
                cout << "노드가 없습니다.";
            }
            else if (curNode == nullptr)
            {
                cout << "주솟값 nullptr\n";
            }
            //첫노드 지울때
            else if (curNode == head)
            {
                //노드 하나일때
                if (head->next == nullptr) //(head == tail)
                {
                    delete head;

                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    node* tmp = head;
                    head = tmp->next;
                    head->prev = nullptr;

                    delete tmp;
                }
            }
            
            else
            {
                node* tmp = curNode;
                
                //끝노드 지울때
                if (tail == curNode)
                {
                    tail = curNode->prev;
                }
                
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;                

                delete tmp;
            }
        }

        //앞에서부터 노드검색
        node* FindFront(int findData)
        {
            node* curNode = head;
            if (head == nullptr)
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
                } while (curNode != nullptr);

                cout << "값을 찾을 수 없습니다.\n";
                return nullptr;
            }   
        }

        //뒤에서부터 노드검색
        node* FindBack(int findData)
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
                    curNode = curNode->prev;
                } while (curNode != nullptr);

                cout << "값을 찾을 수 없습니다.\n";
                return nullptr;
            }   
        }

        //head, tail 값 가져오기
        node* GetHead()
        {
            return head;
        }
        
        node* GetTail()
        {
            return tail;
        }

        //리스트 출력
        void PrintList(node* head)
        {
            if (head == nullptr)
            {
                cout << "NULL\n";
            }
            else
            {
                if (head->next == nullptr)
                {
                    if(head->prev == nullptr)
                    {
                        cout << "NULL" << " <- ";
                    }
                    cout << head->data << " -> ";
                }
                else
                {
                    if(head->prev == nullptr)
                    {
                        cout << "NULL" << " <- ";
                    }
                    cout << head->data << " <-> ";
                }

                PrintList(head->next);
            }
        }
};

int main()
{
    DLList list;

    list.AddFront(1);
    list.Delete(nullptr);
    
    list.AddFront(2);
    list.AddFront(3);
    list.Delete(list.FindFront(2));
    list.PrintList(list.GetHead());
    list.AddBack(10);
    list.AddBack(20);
    list.AddBack(30);
    
    list.Delete(nullptr);
    list.PrintList(list.GetHead());
    list.Insert(nullptr,50);
    list.Insert(list.GetHead()->next,250);
    list.Insert(list.FindFront(250),450);
    list.PrintList(list.GetHead());
    cout << list.FindBack(250);

}