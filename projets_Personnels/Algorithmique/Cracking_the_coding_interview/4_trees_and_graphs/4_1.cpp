//Given a direct graph, design an algorithm to find out wether there is a route between two nodes.

/*Thoughts
It is a directed graph, so there should be a path.
We could use a BFS to search for a path or a bidirectionnal search. Bidirectionnal is faster but takes more spaces because we use two BFS
A DFS would do it also.
I suppose we just want to return a boolean that will tell us if there is a path or not.
*/

#include <string>

using std::string;

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

class Graph{
    public:
    int vertices;
    bool **matrix;

    Graph(int nbVertices){
        vertices = nbVertices;
        matrix = new bool *[nbVertices];
        for (int i = 0; i < nbVertices; i++){
            matrix[i] = new bool[nbVertices];
        }
    }

    void addEdge(int x, int y){
        matrix[x][y] = 1;
    }

    void printMatrix(void){
        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start){
        vector<bool> visited(false, vertices);
        visited[start] = true;
        queue<int> q;
        q.push(start);
        cout << start << " ";

        int v=0;
        while (!q.empty()){
            v = q.front();
            q.pop();
            visited[v] = true;
            for (int i = 0; i < vertices; i++){
                if (matrix[v][i] == 1 && (!visited[i])){
                    cout << i << " ";
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start, vector<bool>& visited){
        visited[start] = true;
        cout << start << " ";
        for (int i = 0; i < vertices; i++){
            if (matrix[start][i] == 1 && (!visited[i])){
                DFS(i, visited);
            }
        }

    }

    bool isRoute(int start, int ending){
        if (start == ending) return true;
        vector<bool> visited(false, vertices);
        queue<int> q;
        q.push(start);

        int v = 0;
        while (!q.empty()){
            v = q.front();
            //cout << "v : " << v << " ";
            q.pop();
            //cout << q.size() << " ";
            
            for (int i = 0; i < vertices; i++){
                if (matrix[v][i] == 1 && (!visited[i])){
                    if (i == ending){
                        cout << "there is a path" << endl;
                        return true;
                    }
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << "there is no path ";
        return false;
    }    
            
    

};

int main(void){
    Graph G(7);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,4);
    G.addEdge(1,3);
    G.addEdge(1,5);
    G.addEdge(2,6);
    G.addEdge(4,5);

   /* G.printMatrix();
    cout << endl;
    G.BFS(0);
    vector<bool> visited(false, 7);
    G.DFS(0, visited);
    cout << endl;*/
    cout << G.isRoute(0, 1) << endl;
}