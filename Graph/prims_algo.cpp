#include <iostream>
#include <queue>
using namespace std;

#define Max 110

//vector < int > graph[MX];
//bool vis[MX];
//int dist[MX];


class Node
{ public:
      int data;
      int w;
      Node* next;

      Node(int data,int w){
    this->data=data;
    this->w=w;
    next = NULL;
    }

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
        int time, parent[9], key[9],f[Max];
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
        void addEdge(int src, int dest, int weight)
        {
            Node * n1 = new Node(dest,weight);
            Node * n2 = new Node(src, weight);
            //n1->data = dest;
            //n2->data = src;

            //n->data = src;
            //n1->next = NULL;
            //n2->next = NULL;

            if (a[src].head == NULL && a[dest].head == NULL)
            { a[src].head = n1;
              a[dest].head= n2;
            }

            else if( a[src].head != NULL && a[dest].head == NULL ){

            n1->next= a[src].head;
            a[src].head= n1;
           // As a[dest].head is NULL
            a[dest].head = n2;

            }		// 0--->NULL

            else if(a[src].head == NULL && a[dest].head != NULL){

             a[src].head = n1;
             n2->next= a[dest].head;
             a[dest].head= n2;
           // As a[dest].head is NULL

            }


            else {
             n1->next= a[src].head;
             a[src].head= n1;

             n2->next= a[dest].head;
             a[dest].head= n2;


        	}

        }
//DFS implementation
void prim(int source){

 queue < int > Q;

 for (int i = 0; i < v; ++i){
             Q.push(a[i].val);
 }
  queue<int> copy_q = Q;

  while(!copy_q.empty()){
        int node = copy_q.front();
        key[node]= Max;
        //cout << node << " ";
        copy_q.pop();


}
key[source]=0;
parent[source]= NULL;



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

    Graph g(v=8);
    g.addEdge(0, 2, 47);
    g.addEdge(0, 4, 80);
    g.addEdge(0, 5, 54);

    g.addEdge(2, 4, 23);
    g.addEdge(2, 1, 55);
    g.addEdge(2, 5, 75);
    g.addEdge(2, 3, 88);
    g.addEdge(2, 6, 66);

    g.addEdge(4, 1, 32);
    g.addEdge(4, 6, 93);

    g.addEdge(1, 7, 79);
    g.addEdge(1, 3, 31);
    g.addEdge(1, 6, 74);

    g.addEdge(3, 5, 74);
    g.addEdge(3, 7, 29);

    g.addEdge(7, 6, 68);
    //

   // g.addEdge(6, 5, 75);
    //g.addEdge(2, 3, 88);
    //g.addEdge(2, 6, 66);

   // g.addEdge(4, 1, 32);
    //g.addEdge(4, 6, 93);

    //g.addEdge('shirt', 'tie');
   // g.addEdge('tie', 'jacket');
   // g.addEdge('shirt', 'belt');
    //g.addEdge('belt', 'jacket');
    //g.addEdge('undershorts', 'pants');
    //g.addEdge('pants',' belt');
    //g.addEdge('belt', 'jacket');
    //g.addEdge('pants', 'shoes');
    //g.addEdge('undershorts', 'shoes');
    //g.addEdge('socks', 'shoes');
    //g.addEdge('watch','0');


    g.printGraph();

    cout<<"\nEnter source: ";
    cin >> s;
    cout << "\nDepth First Traversal :\n"<<endl;
    //g.dfs(s);

    //cout << "\nFrom node " << s << "\n" << endl;
    //for (int i = 0; i < v; i++){
      //  cout << "Distance of " << i << " is : " <<// g.dist[i] << " , "<<"Finish time : "<< g.f[i] << endl;
    //}

    cout<<"\n Topological sort: "<<endl;

    while(!g.Q.empty()){
        int node = g.Q.front();
        cout << node << " ";
        g.Q.pop();}
    return 0;
}
