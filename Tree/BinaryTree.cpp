#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node* parent;
    node* left;
    node* right;

    node()
    {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    node(int data)
    {
        this->data = data;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    node(node* parent, int data)
    {
        this->data = data;
        this->parent = parent;
        left = nullptr;
        right = nullptr;
    }
};

class BTree
{
    private:
        node* root;

    public:
        BTree(int rootData)
        {
            root = new node(rootData);
        }

        void Swap(node* a, node* b) {
            // 부모의 자식 포인터 갱신
            if (a->parent) {
                if (a->parent->left == a) {
                    a->parent->left = b;
                } else {
                    a->parent->right = b;
                }
            }
            
            if (b->parent) {
                if (b->parent->left == b) {
                    b->parent->left = a;
                } else {
                    b->parent->right = a;
                }
            }
        
            // 부모 포인터 교환
            node* tempParent = a->parent;
            a->parent = b->parent;
            b->parent = tempParent;
        
            // 자식 포인터 교환
            node* tempLeft = a->left;
            node* tempRight = a->right;
            a->left = b->left;
            a->right = b->right;
            b->left = tempLeft;
            b->right = tempRight;
        
            // 자식들의 부모 포인터 갱신
            if (a->left) a->left->parent = a;
            if (a->right) a->right->parent = a;
            if (b->left) b->left->parent = b;
            if (b->right) b->right->parent = b;
        }

        //노드추가 BFS 이용 왼쪽부터 추가
        void AddNode(int data)
        {
            node* newNode;
            queue<node*> que;
            que.push(root);

            while(!que.empty())
            {
                node* cur = que.front();
                que.pop();

                if(cur->left != nullptr)
                {  
                    que.push(cur->left);
                }
                else
                {
                    newNode = new node(cur, data);
                    cur->left = newNode;
                    return;
                }

                if(cur->right!= nullptr)
                {  
                    que.push(cur->right);
                }
                else
                {
                    newNode = new node(cur, data);
                    cur->right = newNode;
                    return;
                }
                
            }
            
        }
        
        //노드삽입
        void InsertNode(node* parent ,int data)
        {
            if(parent->left == nullptr)
            {
                node* newNode = new node(parent, data);
                parent->left = newNode;
            }
            else if(parent->right == nullptr)
            {
                
                node* newNode = new node(parent, data);
                parent->right = newNode;
            }
            else
            {
                cout << "cannot insert\n";
            }
        }

        //노드삭제 BFS 이용 오른쪽부터 삭제
        void DeleteNode()
        {
            node* cur;
            queue<node*> que;
            que.push(root);

            while(!que.empty())
            {
                cur = que.front();
                que.pop();

                if(cur->left != nullptr)
                {  
                    que.push(cur->left);
                }

                if(cur->right!= nullptr)
                {
                    que.push(cur->right);
                }

                if(que.empty() == true)
                {
                    if (cur->parent->right != nullptr)
                    {
                        cur->parent->right = nullptr;
                    }
                    else if (cur->parent->left != nullptr)
                    {
                        cur->parent->left = nullptr;
                    }

                    delete cur;
                    
                }
                
            }
        }

        //노드삭제
        void DeleteNode(int data)
        {
            node* delNode = Find(root, data);

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
            //부모 노드에서 삭제할 노드 포인터 제거
            if(delNode->left == nullptr && delNode->right == nullptr)
            {
                if(delNode == delNode->parent->left)
                {
                    delNode->parent->left = nullptr;
                }
                else
                {
                    delNode->parent->right = nullptr;
                }
            }
            else if(delNode->left == nullptr)
            {
                if(delNode == delNode->parent->left)
                {
                    delNode->parent->left = delNode->right;
                }
                else
                {
                    delNode->parent->right = delNode->right;
                }
            }
            else if(delNode->right == nullptr)
            {
                if(delNode == delNode->parent->left)
                {
                    delNode->parent->left = delNode->left;
                }
                else
                {
                    delNode->parent->right = delNode->left;
                }
            }
            else
            {
                // 오른쪽 서브트리의 가장 왼쪽 노드를 찾음 (후속 노드)
                node* successor = delNode->right;
                while (successor->left != nullptr) 
                {
                    successor = successor->left;
                }
        
                // 후속 노드와 현재 노드를 Swap
                Swap(delNode, successor);
        
                // 후속 노드(현재 delNode 위치)를 삭제
                if (delNode->parent->left == delNode) 
                {
                    delNode->parent->left = nullptr;
                } 
                else 
                {
                    delNode->parent->right = nullptr;
                }

                
            }           
        
            
        
            //메모리 해제
            delete delNode;
        }

        //값과 일치하는 주소 반환 ,전위순회
        node* Find(node* root, int fData)
        {   
            if(root != nullptr)
            {
                // 현재 노드의 값이 찾는 값과 같으면 해당 노드 주소 반환
                if (root->data == fData)
                {
                    return root;
                }            
            
                // 하위 노드를 탐색
                node* found = Find(root->left, fData);
                if (found != nullptr)
                {
                    return found;  // 값을 찾으면 즉시 반환
                }

                found = Find(root->right, fData);
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

        //전위순회
        void PrintTreePre(node* root)
        {
            cout << root->data << " ";
            PrintTreePre(root->left);
            PrintTreePre(root->right);
        }

        //중위순회
        void PrintTreeIn(node* root)
        {
            
            PrintTreeIn(root->left);
            cout << root->data << " ";
            PrintTreeIn(root->right);
            
        }

        //후위순회
        void PrintTreePost(node* root)
        {
            
            PrintTreePost(root->left);
            PrintTreePost(root->right);
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
                    if (cur->left != nullptr)
                        q.push(cur->left);

                    if (cur->right != nullptr)
                        q.push(cur->right);
                }
                
                // 현재 레벨을 모두 출력한 후 줄 바꿈
                cout << "\n";
            }
        }


};

int main()
{
    BTree tr(0);

    tr.AddNode(1);
    tr.AddNode(2);
    tr.AddNode(3);
    tr.AddNode(4);
    tr.AddNode(5);
    tr.AddNode(6);
    tr.AddNode(7);

    tr.PrintTreeLevel(tr.GetRoot());
    tr.DeleteNode(2);


    tr.PrintTreeLevel(tr.GetRoot());

}