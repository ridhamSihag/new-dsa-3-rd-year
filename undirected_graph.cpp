#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int> *l; //initializing a dynamic array.  ->assume we want an input user enter his enput and based on that input we want an array normal array will return error but we can do this by dynamic array.
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V]; //Format of dynamic array

    }
    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList(){ //print neighours of all vertex
        for(int i = 0 ; i<V ;i++){
            cout<< i << " : ";
            for(int neigh : l[i]){
                cout << neigh << " ";
            } 
            cout<< endl;
        }

    }
    // BFS traversal
    void bfs() {
         queue<int> q;
         vector<bool> vis(V,false);

         q.push(0);
         vis[0] = true;
         while(q.size() > 0){
            int u = q.front();

            cout<< u << " ";
            q.pop();

            for(int v : l[u]){ //immidiate neighour or each value from that container is temporary stored in v
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
         }
         cout<< endl;
    }

    //DFS Traversal
    void dfsHelp(int u , vector<bool>&visit){
        cout<< u << " ";
        visit[u] = true;

        for(int v : l[u]){
            if(!visit[v]){
                dfsHelp(v , visit);
            }
        }

    }
    void dfs(){
        int src = 0;
        vector<bool> visit(V , false);
        dfsHelp(src , visit);
        cout<< endl;

    }


    //Detect cycle in graph
    bool detect_cycle(int src ,int par , vector<bool> &visit){
        visit[src] = true;
        list<int> neighours = l[src];

        for(int v : neighours){
            if(!visit[v]){
                visit[v] = true;
                if(detect_cycle(v , src , visit)){
                    return true;
                }

            }
            else if(v != par){
                return true;
            }
        }
        return false;


    }

    bool iscycle(){
        vector<bool> visit(V ,false);
        for(int i = 0 ; i<V ; i++){
            if(!visit[i]){
                if(detect_cycle(i , -1 , visit)){
                    return true;
                }
            }
        }
        return false;

    }

};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printAdjList();
    g.bfs();
    g.dfs();
    cout<< g.iscycle() <<endl;
    return 0;

}
