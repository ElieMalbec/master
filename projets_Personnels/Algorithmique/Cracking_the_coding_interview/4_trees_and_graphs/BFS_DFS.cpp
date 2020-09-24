

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::string;

/*class Node{
    public :

    string name;
    vector<Node> children;
};*/


class Adjmat{
    public :
        int **matrix;
        int vertices;

    Adjmat(int nbVertices){
        this->vertices = nbVertices;
        matrix = new int*[nbVertices];
        for (int i = 0; i < nbVertices; i++){
            matrix[i] = new int[nbVertices];
            for (int j = 0; j < nbVertices; j++){
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int i, int j){
        matrix[i][j] = 1;
        //matrix[j][i] = 1;
    }

    void removeEdge(int i, int j){
        matrix[i][j] = 0;
        //matrix[j][i] = 0;
    }

    void print(){
        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void print2(){
        for (int i = 0; i < vertices; i++){
            cout << i << ": ";
            for (int j = 0; j < vertices; j++){
                if (matrix[i][j] == 0){

                }
                else {
                    cout << j << ", ";
                }
            }
            cout << endl;
        }
    }

    void DFS(int noeud, vector<bool>& visited){
        cout << noeud << " ";

        visited[noeud] = true;
        for (int i = 0; i < vertices; i++){
            if (!(visited[i]) && matrix[noeud][i] == 1){
                DFS(i,visited);
            }
        }
    }
    void BFS(int noeud, vector<bool>& visited){
        /*cout << noeud << " ";
        visited[noeud] = true;
        for (int i = 0; i < vertices, i++){
            BFS()
        }*/

        std::queue<int> q;
        q.push(noeud);
        visited[noeud] = true;

        int vis=0;
        while (!(q.empty())){
            vis = q.front();
            cout << vis << " ";
            q.pop();
            for (int i = 0; i < vertices; i++){
                if (matrix[vis][i]== 1 && visited[i] == false){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

    }

    ~Adjmat(){
        for (int i = 0; i < vertices; i++){
            delete [] matrix[i];
        }
        delete []matrix;
    }

};

void DFS(int arr[6][6]){
    for (int i = 0; i < 6; i++){

    }
}


int main(void){
    /*int adjMatrix[6][6]= {{0,1,0,0,1,1},
                        {0,0,0,1,1,0},
                        {0,1,0,0,0,0},
                        {0,0,1,0,1,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0}
    };*/
    Adjmat G(6);
    G.addEdge(0,1);
    G.addEdge(0,4);
    G.addEdge(0,5);
    G.addEdge(1,3);
    G.addEdge(1,4);
    G.addEdge(2,1);
    G.addEdge(3,2);
    G.addEdge(3,4);

    G.print2();

    vector <bool> visited(false,6);
    //G.DFS(0, visited);
    G.BFS(0, visited);
    return 0;
}