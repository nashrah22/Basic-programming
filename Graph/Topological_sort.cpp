#include <iostream>
#include <queue>
using namespace std;

#define Max 110

//vector < int > graph[MX];
//bool vis[MX];
//int dist[MX];


class Node
{ public:
      char data;
      Node* next;
};

/*
 * Adjacency List
 */
class AdjList
{  public:

    int val;
      Node *head;
};

/*
 * Class Graph
 */
class Graph
{
    public:
        //
        bool vis[Max];
        int time, prev[Max], dist[Max],f[Max];
        int v;
        AdjList* a;
        bool directed;
        queue < int > Q;
//**************** Initialization*****************
        Graph(int v)
        {
         this->v = v;
         a = new AdjList [v];

         for (int i = 0; i < v; ++i){
             a[i].val= i;
             a[i].head = NULL;
           }
        }
// add edge
        void addEdge(int src, int dest)
        {
            Node * n = new Node;
            n->data = dest;
            n->next = NULL;

         if (a[src].head == NULL)
            { a[src].head = n;
            }

        	else {
            Node* tmp = a[src].head; // code logic not working because of insert at last in the linked list
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next=n;
            }

        }
//DFS implementation

      void dfs(int source){

        for(int i=0;i< v; ++i){
           vis[i]= 0;
           prev[i]= NULL;
           dist[i]= Max;   //distance infinity
           f[i]=Max;
        }
            time = 0;

          dfs_visit(source,vis);

   // For unvisited vertices which are not adjacent of any visited nodes

      for(int i=0;i< v; ++i)
        { if(vis[i]==0){

         dfs_visit(i,vis);
        }
   }

}

    void dfs_visit(int source, bool vis[]){

        vis[source]= 1; // grey
        cout<<source<<" ";
        time=time+1;
        dist[source] = time;

        Node * tmp = a[source].head;
        while(tmp != NULL){
        int next = tmp->data;
          if (vis[next] == 0){
           prev[next]= source;
           dfs_visit(next,vis);
         } tmp= tmp->next;
 }
        time=time+ 1;
        f[source]=time;

        Q.push(source);
}

   void printGraph()
   {
    int i;
    for (i = 0; i < v; ++i)
    {
        Node* tmp = a[i].head;
        cout<<"\n Adjacency list of vertex "<<i<<"\n head ";
        while (tmp)
         {
            cout<<"-> "<<tmp->data;
            tmp = tmp->next;
         }
            cout<<endl;
            }
 }
};


int main()
{
     int s,v;

    Graph g(v=9);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 5);
    g.addEdge(1, 7);
    g.addEdge(0, 7);

    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 2);
    g.addEdge(2, 5);
    g.addEdge(6, 7);

    //g.addEdge(6, 4);
    //g.addEdge(6, 5);
    //g.addEdge(6, 7);
   // g.addEdge(7, 3);

    //g.addEdge('shirt', 'tie');
    //g.addEdge('tie', 'jacket');
    //g.addEdge('shirt', 'belt');
    //g.addEdge('belt', 'jacket');
    //g.addEdge('undershorts', 'pants');
    //g.addEdge('pants',' belt');
    //g.addEdge('belt', 'jacket');
    //g.addEdge('pants', 'shoes');
    //g.addEdge('undershorts', 'shoes');
    //g.addEdge('socks', 'shoes');
    //g.addEdge('watch','0');


    //g.printGraph();

    cout<<"\nEnter source: ";
    cin >> s;
    cout << "\nDepth First Traversal :\n"<<endl;
    g.dfs(s);

    cout << "\nFrom node " << s << "\n" << endl;
    for (int i = 0; i < v; i++){
        cout << "Distance of " << i << " is : " << g.dist[i] << " , "<<"Finish time : "<< g.f[i] << endl;
    }

    cout<<"\n Topological sort: "<<endl;

    while(!g.Q.empty()){
        int node = g.Q.front();
        cout << node << " ";
        g.Q.pop();}
    return 0;
}
