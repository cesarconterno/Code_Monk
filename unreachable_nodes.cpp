#include <iostream>
#include <vector>
#define TAM 1000
using namespace std;

vector <int> adj[TAM];
bool visited[TAM];

void dfs(int s) {
	visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
        	if(visited[adj[s][i]] == false)
             		dfs(adj[s][i]);
        }
}

void initialize() {
	for(int i = 0;i < TAM;++i)
        	visited[i] = false;
}

int main() {
        int nodes, edges, x, y, node_init;
	int unreachable_nodes = 0;
        cin >> nodes;                       //Number of nodes
        cin >> edges;                       //Number of edges
	
	for(int i = 0;i < edges;++i) {
        	cin >> x >> y;     
     		//Undirected Graph 
         	adj[x].push_back(y);//Edge from vertex x to vertex y
         	adj[y].push_back(x);//Edge from vertex y to vertex x
        }

        initialize();//Initialize all nodes as not visited
	cin >> node_init;
        dfs(node_init);
	for(int i=1;i <= nodes; i++){
		if(visited[i] == false) unreachable_nodes++;
	}


        cout << "Unreachable nodes: " << unreachable_nodes << endl;
        return 0;
}
