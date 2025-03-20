#include <iostream>

using namespace std;




struct node
{
    int data;
    node* next;
};

class SLList
{
    private :
        //첫노드를 가르킴
        node* head;

    public :
        SLList()
        {
            head = nullptr;
        }

        //노드생성
        node* CreateNode(int addData)
        {
            node* newNode = new node;
            newNode->data = addData;
            newNode->next = nullptr;

            return newNode;
        }

        //노드 맨앞 추가
        void AddFront(int addData)
        {
            node* newNode = CreateNode(addData);

            //첫노드 아닐시
            if (head != nullptr)            
            {
                newNode->next = head;                                
            }
            
            head = newNode;
        }
        //노드 중간 삽입
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
            }
        }

        //노드 맨뒤 추가
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
                node* curNode = head;
                while(1)
                {
                    if(curNode->next == nullptr)
                    {
                        curNode->next = newNode;
                        break;
                    }
                    curNode = curNode->next;
                }
                
            }
        }

        //첫 노드 삭제
        void Delete()
        {
            //노드 없을때
            if (head == nullptr)
            {
                cout << "노드가 없습니다.\n";
            }
            //노드 하나일때
            else if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                node* tmp = head;
                head = tmp->next;

                delete tmp;
            }
        }
        //노드 삭제
        void Delete(node* prevNode)
        {
            //노드 없을때
            if (head == nullptr)
            {
                cout << "노드가 없습니다./n";
            }
            else if (prevNode == nullptr)
            {
                cout << "이전노드 주솟값 nullptr\n";
            }
            else
            {
                node* tmp = prevNode->next;
                prevNode->next = tmp->next;

                delete tmp;
            }
        }

        //노드검색
        node* Find(int findData)
        {
            node* curNode = head;
            if (head == nullptr)
            {
                cout << "노드가 없습니다./n";
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

        //head
        node* GetHead()
        {
            return head;
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
                cout << head->data << " -> ";
                PrintList(head->next);
            }
            
            
        }

};

int main()
{
    SLList list;

    
    list.PrintList(list.GetHead());
    list.AddFront(1);
    
    list.AddFront(2);
    list.AddFront(3);

    
    list.Delete(list.Find(5));
    
    list.Insert(list.GetHead(), 5);
    list.PrintList(list.GetHead());
    cout << list.Find(5)<<"\n";
    list.AddBack(13);
    list.AddBack(14);
    list.PrintList(list.GetHead());
    cout << list.GetHead();
}
