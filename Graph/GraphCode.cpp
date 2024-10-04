#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

class Graph{
    int currentSize;
    int matrix[100][100];

    int find(int i, int *parent)
    {
        while (parent[i] != i)
            i = parent[i];
        return i;
    }

    void union1(int i, int j, int *parent)
    {
        int a = find(i, parent);
        int b = find(j,parent);
        parent[a] = b;
    }

    void Rasdel(string str){
        string sub = "";
        int v;
        int u;
        int count;
        int i =0;
        while (str[i]!=' '){
            sub+=str[i];
            i++;
        }
        u= stoi(sub);
        i++;
        sub="";
        while (str[i]!=' '){
            sub+=str[i];
            i++;
        }
        v = stoi(sub);
        i++;
        sub="";
        for (;i<str.length();i++){
            sub+=str[i];
        }
        count = stoi(sub);
        add_edge(u,v,count);
    }

public:

    void Read(){
        cout<<"Reading data started..."<<endl;
        ifstream fin("GraphInput.txt");
        string b;
        getline(fin,b);
        string sub="";
        for (int i =0;i<b.length();i++){
            sub+=b[i];
        }
        currentSize = stoi(sub);
        for (int i=0; i<currentSize;i++){
            getline(fin,b);
            Rasdel(b);

        }
        cout<<"Reading data finished..."<<endl;
    }

    void displayMatrix() {
        int i, j;
        cout<<"   ";
        for (int k = 0; k < currentSize; k++){
            cout<<to_string(k)+" ";
        }
        cout<<"\n";
        for(i = 0; i < currentSize; i++) {
            cout<<to_string(i)+"| ";
            for(j = 0; j < currentSize; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void removeVertex(int x)
    {
        if (x > currentSize) {
            cout << "\nVertex not present!";
            return;
        }
        else {
            int i;


            while (x < currentSize) {

                for (i = 0; i < currentSize; ++i) {
                    matrix[i][x] = matrix[i][x + 1];
                }

                for (i = 0; i < currentSize; ++i) {
                    matrix[x][i] = matrix[x + 1][i];
                }
                x++;
            }
            currentSize--;
        }
    }

    void add_vertex(){
        currentSize++;
    }

    void add_edge(int u, int v, int value) { //function to add edge into the matrix
        if ((v< currentSize and u < currentSize) and (v>=0 and u>=0)) {
            if (matrix[u][v]==0) {
                matrix[u][v] = value;
                matrix[v][u] = value;
            }else cout<<"Rebro already exist"<<"\n";
        }else cout<<"Isn't exist vertex"<<"\n";
    }

    void del_edge(int u, int v){
        if ((v< currentSize and u < currentSize) and (v>=0 and u>=0)) {
            matrix[u][v] = 0;
            matrix[v][u] = 0;
        }else cout<<"Isn't exist vertex"<<"\n";
    }

    void bfs(int start)
    {
        if (start<currentSize and start>=0) {
            vector<bool> visited(currentSize, false);
            vector<int> q;
            q.push_back(start);
            visited[start] = true;
            int vis;
            while (!q.empty()) {
                vis = q[0];
                cout << vis << " ";
                q.erase(q.begin());
                for (int i = 0; i < currentSize; i++) {
                    if (matrix[vis][i] != 0 && (!visited[i])) {
                        q.push_back(i);
                        visited[i] = true;
                    }
                }
            }
            cout << "\n";
        }else cout<<"Isn't exist vertex"<<"\n";
    }

    bool connected(){
        int counter = 0;
        for (int i = 0; i< currentSize; i++){
            for (int j = 0; j<currentSize;j++){
                if(matrix[i][j]==0) counter++;
            }
            if (counter==currentSize) return 0;
        }
        return 1;
    }

    void kruskalMST()
    {
        if (connected()) {
            int parent[currentSize];
            int mincost = 0; // Cost of min MST.

            for (int i = 0; i < currentSize; i++)
                parent[i] = i;

            int edge_count = 0;
            while (edge_count < currentSize - 1) {
                int min = INT_MAX, a = -1, b = -1;
                for (int i = 0; i < currentSize; i++) {
                    for (int j = 0; j < currentSize; j++) {
                        if (matrix[i][j] != 0 && find(i, parent) != find(j, parent) && matrix[i][j] < min) {
                            min = matrix[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }

                union1(a, b, parent);
                printf("Edge %d:(%d, %d) cost:%d \n",
                       edge_count++, a, b, min);
                mincost += min;
            }
            printf("\n Minimum cost= %d \n", mincost);
        }else cout<<"Graph isn't connected!";
    }


};

int main() {
    Graph graph;
    graph.Read();
    graph.add_vertex();
    graph.displayMatrix();
    graph.bfs(0);
    graph.kruskalMST();
}
//input:
//2 3 1
//6 5 2