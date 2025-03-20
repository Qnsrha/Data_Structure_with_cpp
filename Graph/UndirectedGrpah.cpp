#include <iostream>
#include <vector>

using namespace std;


//인접행렬방식으로 벡터를 이용해 무방향 그래프 구현
class UDGraph
{
    private :
        vector<vector<int>> adjacencyMatrix;
        int vertexCount;

    public :
        UDGraph(int vertexCount)
        {
            this->vertexCount = vertexCount;
            adjacencyMatrix.resize(vertexCount, vector<int> (vertexCount, 0));
        }


        //정점추가
        void Addvertex()
        {

            adjacencyMatrix.emplace_back(vertexCount + 1, 0);  // 새로운 행 추가

            for (int i = 0; i < vertexCount; i++)
            {
                adjacencyMatrix[i].push_back(0);  // 기존 행에 새 열 추가
            }
            vertexCount++;
        }
	    //정점삭제
        void Deletevertex()
        {
            if (vertexCount == 0)
            {
                cout << "No vertices to delete!" << endl;
                return;
            }
                        
            adjacencyMatrix.pop_back(); // 마지막 행 삭제

            for (int i = 0; i < vertexCount -1; i++)
            {
                adjacencyMatrix[i].pop_back();  // 기존 행에 열 하나 삭제
            }
            vertexCount--;
        }
	    //간선추가
        void AddEdge(int a, int b)
        {
            adjacencyMatrix[a][b] = 1;
            adjacencyMatrix[b][a] = 1;
        }

	    //간선삭제
        void DeleteEdge(int a, int b)
        {
            adjacencyMatrix[a][b] = 0;
            adjacencyMatrix[b][a] = 0;
        }
	    //인접정점 출력
        void PrintAdjacencyVertex(int a)
        {
            for (int i = 0; i < vertexCount; i++)
            {
                if (adjacencyMatrix[a][i] ==1)
                {
                    cout << adjacencyMatrix[a][i];
                }   
            }
            cout <<"\n";
            
            
        }
	    //그래프출력
        void PrintGraph()
        {
            for (int i = 0; i < vertexCount; i++)
            {
                for (int j = 0; j < vertexCount; j++)
            {
                cout << adjacencyMatrix[i][j] <<" ";
            }
                cout <<"\n";
            }
        }

};

int main()
{
    UDGraph graph(5);
    
    graph.Addvertex();
    graph.Addvertex();
    graph.Deletevertex();
    graph.Deletevertex();
    graph.AddEdge(1,3);
    graph.AddEdge(2,3);
    graph.AddEdge(4,3);
    graph.AddEdge(0,1);
    graph.AddEdge(2,4);
    graph.AddEdge(0,3);
    graph.AddEdge(1,4);

    graph.PrintGraph();

    graph.DeleteEdge(1,4);
    graph.DeleteEdge(0,1);
    graph.DeleteEdge(2,3);

    graph.PrintGraph();

}