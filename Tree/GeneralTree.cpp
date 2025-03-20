#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int data;
    node* parent;
    vector <node*> child;
};

class GTree
{
    private : 
        node* root;

    public :
        //생성자로 root노드 생성 및 초기화
        GTree(int rootData)
        {
            root = new node;
            root->data = rootData;
            root->parent = nullptr;
        }

        void Insert(node* iParent, int iData)
        {
            //노드 생성 및 초기화
            node* newNode = new node;
            newNode->data = iData;
            newNode->parent = iParent;

            //노드 연결
            iParent->child.push_back(newNode);
            
        }

        //후위순회 삭제, 삭제할 하위노드 전체 삭제
        void DelWithLow(node* delNode)
        {
            
            // 하위 노드가 있는 경우 재귀적으로 삭제
            /*
            for (int i = 0; i < delNode->child.size(); i++) {
                Delete(delNode->child[i]);
            }*/

            
            for (node* child : delNode->child) //범위기반 for문
            {
                DelWithLow(child);
            }

            // 부모 노드 자식벡터에서 해당 포인터 비우기
            if (delNode->parent != nullptr)
            {
                auto& siblings = delNode->parent->child;
                siblings.erase(remove(siblings.begin(), siblings.end(), delNode), siblings.end());
            }
        
            // 메모리 해제
            delete delNode;
        }


        //노드 삭제후 자식노드를 부모노드에 연결
        void Del(int fData)
        {
            //삭제할 노드 찾기
            node* delNode = Find(root, fData);
            if (delNode == nullptr)
            {
                cout << "Cannot find node" << endl;
                return;
            }
        
            //루트 노드 삭제 방지
            if (delNode->parent == nullptr) {
                cout << "Cannot delete root node!" << endl;
                return;
            }
        
            //자식 노드를 부모에게 연결
            for (int i = 0; i < delNode->child.size(); i++)
            {
                delNode->parent->child.push_back(delNode->child[i]); // 부모에게 연결
                delNode->child[i]->parent = delNode->parent;            // 부모 설정
            }
            delNode->child.clear();  // 자식 리스트 초기화
        
            //부모 노드에서 삭제할 노드 제거
            for (int i = 0; i < delNode->parent->child.size(); i++)
            {
                if (delNode->parent->child[i] == delNode)
                {
                    delNode->parent->child.erase(delNode->parent->child.begin() + i);
                    --i;  // 삭제 후 인덱스 조정
                }
            }
        
            //메모리 해제
            delete delNode;
        }
        
        

        //값과 일치하는 주소 반환 ,전위순회
        node* Find(node* root, int fData)
        {
            // 현재 노드의 값이 찾는 값과 같으면 해당 노드 주소 반환
            if (root->data == fData)
            {
                return root;
            }
        
            // 하위 노드를 재귀적으로 탐색
            for (int i = 0; i < root->child.size(); i++)
            {
                node* found = Find(root->child[i], fData);
                if (found != nullptr)
                {
                    return found;  // 값을 찾으면 즉시 반환
                }
            }
        
            // 찾는 값이 없는 경우 nullptr 반환
            return nullptr;
        }

        node* GetRoot()
        {
            return root;
        }

        void PrintChildren(node* parent)
        {
            for(int i= 0; i< parent->child.size(); i++)
            {
                cout << parent->child[i]->data << " ";
            }
            cout << "\n";
        }

        //전위순회
        void PrintTreePre(node* root)
        {
            cout << root->data << " ";
            for(int i= 0; i< root->child.size(); i++)
            {
                
                PrintTreePre(root->child[i]);
            }
        }

        //후위순회
        void PrintTreePost(node* root)
        {
            
            for(int i= 0; i< root->child.size(); i++)
            {
                
                PrintTreePost(root->child[i]);
            }
            cout << root->data << " ";
        }

        //레벨순회
        void PrintTreeLevel(node* root)
        {
            if (root == nullptr) return;

            queue<node*> q;
            q.push(root);

            while (!q.empty())
            {
                // 현재 레벨의 노드 개수 확인
                int levelSize = q.size();
        
                // 현재 레벨의 모든 노드를 출력
                for (int i = 0; i < levelSize; i++)
                {
                    node* cur = q.front();
                    cout << cur->data << " ";
                    q.pop();
        
                    // 자식 노드들을 다음 레벨에 추가
                    for (auto child : cur->child)
                    {
                        q.push(child);
                    }
                }
                
                // 현재 레벨을 모두 출력한 후 줄 바꿈
                cout << "\n";
            }
        }


};



int main()
{
    GTree tr(0);

    tr.Insert(tr.GetRoot(), 1);
    tr.Insert(tr.GetRoot(), 2);
    tr.Insert(tr.GetRoot(), 3);
    tr.Insert(tr.Find(tr.GetRoot(), 1), 4);
    tr.Insert(tr.Find(tr.GetRoot(), 2), 12);
    tr.Insert(tr.Find(tr.GetRoot(), 2), 13);
    tr.Insert(tr.Find(tr.GetRoot(), 4), 5);
    tr.Insert(tr.Find(tr.GetRoot(), 4), 6);
    tr.Insert(tr.Find(tr.GetRoot(), 6), 7);
    
    tr.PrintTreeLevel(tr.GetRoot());

    tr.DelWithLow(tr.Find(tr.GetRoot(), 4));

    tr.PrintTreeLevel(tr.GetRoot());
}