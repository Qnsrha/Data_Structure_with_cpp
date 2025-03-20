#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};


//인접리스트방식으로 연결리스트를 이용해 방향그래프 구현
class DGraph
{
    private :
        vector<node*> adjacencyList;
        int vertexCount;

    public :
        DGraph(int vertexCount)
        {
            this->vertexCount = vertexCount;
            adjacencyList.resize(vertexCount, nullptr);

            for (int i=0; i<vertexCount; i++)
            {   
                
                adjacencyList[i] = new node(i);
            }
        }

        ~DGraph()
        {
            for (int i=0; i<vertexCount; i++)
            {
                node* cur = adjacencyList[i];
                while (cur != nullptr)
                {
                    node* temp = cur;
                    cur = cur->next;
                    delete temp; // 연결 리스트 노드 삭제
                }
                
            }
            adjacencyList.clear();
            
        }

        //정점추가
        void AddVertex()
        {
            
            adjacencyList.push_back(new node(vertexCount+1));

            vertexCount++;
        }
        //정점삭제
        void DeleteVertex()
        {
            if (vertexCount == 0)
            {
                cout << "No vertices to delete!" << endl;
                return;
            }
        
            node* lastNode = adjacencyList.back();  // 마지막 정점 가져오기
        
            // 해당 정점에 연결된 간선 삭제 (메모리 해제)
            node* cur = lastNode;
            while (cur != nullptr)
            {
                node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        
            adjacencyList.pop_back(); // 벡터에서 제거
            vertexCount--;
        }
        //간선추가
        void AddEdge(int a, int b)
        {
            if (a >= vertexCount || b >= vertexCount) 
            {
                cout << "Invalid vertex number!" << endl;
                return;
            }
        
            node* cur = adjacencyList[a];
            while (cur->next != nullptr) 
            {
                if (cur->next->data == b) 
                {
                    cout << "Edge already exists!" << endl;
                    return;
                }
                cur = cur->next;
            }
        
            cur->next = new node(b);
        }
        //간선삭제
        void DeleteEdge(int a, int b)
        {
            if (a >= vertexCount) 
            {
                cout << "Invalid vertex number!" << endl;
                return;
            }

            node* cur = adjacencyList[a];
            node* prev = nullptr;

            while (cur != nullptr && cur->data != b) 
            {
                prev = cur;
                cur = cur->next;
            }

            if (cur == nullptr) 
            {
                cout << "Edge does not exist!" << endl;
                return;
            }

            if (prev != nullptr) 
            {
                prev->next = cur->next;
            }
            else 
            {
                adjacencyList[a] = cur->next; // 첫 번째 노드를 삭제하는 경우
            }

            delete cur;
        }

        //인접정점 출력
        void PrintAdjacencyVertex(int a)
        {
            node* cur = adjacencyList[a]->next;
            while(cur != nullptr)
            {
                cout << cur->data <<" ";
                cur = cur->next;
                
            }
        }
        //그래프출력
        void PrintGraph()
        {
            for(int i= 0; i<vertexCount; i++)
            {
                node* cur = adjacencyList[i];
                while(cur != nullptr)
                {
                    cout << cur->data <<" ";
                    cur = cur->next;
                }
                cout << "\n";
            }
        }
    
};

int main()
{
    DGraph graph(5);

    graph.AddEdge(0,1);
    graph.AddEdge(0,4);
    graph.AddEdge(4,0);
    graph.AddEdge(2,4);
    graph.AddEdge(3,1);

    graph.PrintGraph();
    graph.PrintAdjacencyVertex(0);


}