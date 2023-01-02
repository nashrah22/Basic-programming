#include <iostream>
#include <queue>
using namespace std;

#define MX 110

//vector < int > graph[MX];
//bool vis[MX];
//int dist[MX];
class Nodee {
public:
 int data;
 Nodee *next;

 Nodee(int data){

 this->data = data;
 next = NULL;
}

 };

 class Queue {

 public:
    Nodee *head, *tail;

    Queue(){

     head = NULL;
     tail = NULL;
    }

//void insert_at_begin(int data)


void enqueue(int data){
Nodee *n = new Node(data);
Nodee *temp;

    if(head == NULL){
            head = n;
            tail = n;

    }
    else{
            temp=tail;
            temp->next = n;
            tail= temp->next;

        //tail = n-> next;

    }
}


void dequeue(){
Nodee *tmp;
tmp=head;
head= tmp->next;
delete tmp;


}


 };



class Node
{public:
    int data;
    int w;
     Node* next;

     Node(int data, int w){
     this->data=data;
     this->w = w;
     next = NULL;
     }
};

/*
 * Adjacency List
 */
class AdjList
{ public:
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
        bool vis[MX];
        int dist[MX];
        int key[9];
        int parent[9];
        Queue q;
        int nd;

        //
        int v;
        AdjList* a;
        bool directed;

        Graph(int v)
        {
        this->v = v;
        a = new AdjList [v];
       // directed= dir;
            	 //total vertices
        for (int i = 0; i < v; ++i){
               // cin>> val;
               a[i].val = i;
               a[i].head = NULL;
                }		//linking head of all vertices (array) to NULL ,it doesn't store any number only stores HEAD
        }


        void addEdge(int src, int dest, int weight)
        {
            Node * n1 = new Node(dest, weight);
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

            //n->next = a[src].head;		//*next(of dst) storing address of head->next node i.e.. 1--->2 (first node from head)
            //a[src].head = n;
        	}

        }




    void prims(int source){
    int weight, nd, smallest = MX;
    Node * tmp= a[source].head;

     //queue < int > Q;

     for(int i=0;i< v; ++i){
        //Q.push(a[i].val)   //

        q.enqueue(a[i].val);

     }

   for (int i = 0; i < v; ++i){
    key[i] = MX;
   }

    key[source] = 0;
    parent[source]= NULL;


   Nodee* tmp = q.head;
 while (tmp != NULL){
      for(int i=0; i<v; i++){
       if(key[i] < smallest){
        smallest = key[i];
        nd = i;
       }
      }
       Node * temp = a[nd].head;
       while(temp != NULL){
              int next = temp->data;
              int w_next =temp->w;
               Nodee* t = q.head;
               while (t != NULL)
               {
                   if(t->data= next && w_next <key[next]){
               parent[next]= nd;
               key[next]= w_next;
               }
               } t=t->next;
               }
               temp=temp->next;

       }
       tmp= tmp->next;

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

   // bool dir;
   //cout<<"enter no of vetices: "<<endl;
   //cin>>v;
    Graph g(v=8);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 7);
    g.addEdge(6, 7);

    g.printGraph();

    cout<<"\nEnter source: ";
    cin >> s;
    cout << "\nBreadth First Traversal :\n"<<endl;
    g.bfs(g,s);

    cout << "\nFrom node " << s << "\n" << endl;
    for (int i = 0; i < v; i++){
        cout << "Distance of " << i << " is : " << g.dist[i] << endl;
    }
Queue q;


    return 0;
}
