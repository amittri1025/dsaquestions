#include<iostream>
using namespace std;

class graph{
	public: 
		unordered_map<int, list<int>> adj;
		// u-> first edge and v-> second edge
		void addEdge(int u, int v, bool direction){
			// direction => 0 (undirected) and 1(directed)
			
			// agar do node connected hai to , u----v, 
			// to u ki list me v daldo
			adj[u].push_back(v);
			
			// basically , agar undirected hai to , adjacency list me
			// dono nodes me wo number ayega for.eg. u----v
			// so u => [v]
			// and v => [u]
			if(direction==0){
				adj[v].push_back(u);
			}
			
			void printAdjList(){
				for(auto i: adj){
					cout<<i.first<<"->";
						cout<<adj[i];
					cout<<endl;
				}
			}
		}
}

int main(){
	cout<<"Hello World"<<endl;
};
