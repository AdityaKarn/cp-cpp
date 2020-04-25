#include<iostream>
#include<list>

using namespace std;

//class graph
class graphs
{
private:
    /* data */
    int V;
    list<int> *adj;
    void dfsUtil(int v, bool visited[]);

public:
    graphs(int V);
    void addEdge(int v, int w);
    void bfs(int s);
    void dfs(int v);
};

graphs::graphs(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void graphs::addEdge(int v, int w){
    adj[v].push_back(w);
}



//BFS
void graphs::bfs(int s){

    //creating visited nodes
    bool *visited = new bool[V];

    for(int i = 0; i< V; i++){
        visited[i]= false;
    }

    // creating a queue for bfs
    list<int> queue;

    // root node is visited
    visited[s]= true;
    queue.push_back(s);

    // iterator i that will give all adjacency of the vertex

    list<int>::iterator i;

    while(!queue.empty()){
        //deque the vertex s and print it
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();

        // now get all adjacencys , if not visited, mark visited and push into queue
        for(i = adj[s].begin(); i!= adj[s].end(); i++){
            if(!visited[*i]){
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
}






//DFS

void graphs::dfsUtil(int v, bool visited[]){
   visited[v] = true;
   cout<<v<<" ";

   list<int>::iterator i;
   for(i = adj[v].begin(); i!= adj[v].end(); i++){
       if(!visited[*i]){
           dfsUtil(*i, visited);
       }
   } 
}

void graphs::dfs(int v){
    bool *visited = new bool[V];
    for(int i =0;i<V; i++){
        visited[i]= false;

    }
    dfsUtil(v,visited);
}







int main(){
    graphs g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    g.bfs(2);
    g.dfs(2);
    return 0;
}


/* pseudeo code:->
    class graph(root node):
        constructor:
            int v = root node
            new adjacency list //linked list of an arrays


        void bfs:
            dynamically allocated visited array[v]
            visited[all]= false

            list queue //stores current node to bfs
            add root node to queue

            list iterator i

            while(queue != empty):
                cout<< queue.front();
                queue.pop_front()

                for(iterator = adj[v].front; it != adj[v].end(); i++):
                    if(!visited[*i]){
                        visited[*i] = true
                        add i to queue
                    }   
        

        void dfsUtil:
            visited[v] = true
            cout<<v
            list iterator i

            for(i= adj[v].front; i!= adv[v].end(); i++):
                if(!visited[*i]){
                    dfsUtil(i, visited)
                }

        void dfs:
            bool *visited = dynamically allocated
            turn visited every to false

            dfs util(v, visited)
 */
        