#include <iostream>
#include <queue>
#include <list>
#include <iterator>

using namespace std;

#define MX 110

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
        bool vis[MX];
        int dist[MX];
        int key[9];
        int parent[9];
        int smallest= MX;
        //Queue q;
        list<int> Q;
        int nd,u;

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

//
int ExtractMin(list<int> Q){
    int n;
    list<int>::iterator it;

    for(it=Q.begin();it != Q.end(); ++it){
    if(key[*it] < smallest){
        smallest = key[*it];
        n=*it;
        }
    }
    //key[n]=MX;
    return n;
}


    void prims(int source){
    int weight= MX;
    Node * tmp= a[source].head;

     for(int i=0;i< v; ++i){
        Q.push_back(a[i].val);   //
     }

   for (int i = 0; i < v; ++i){
    key[i] = MX;
   }
    key[source] = 0;
    parent[source]= -1;

 while (!Q.empty()){
     u =  ExtractMin(Q);
     nd=u;
    Q.remove(nd);

       Node * temp = a[nd].head;
       while(temp != NULL){
        int next = temp->data;
        int w_next =temp->w;

        list<int>:: iterator it2;
        for(it2=Q.begin();it2 != Q.end(); ++it2){
        if(*it2 == next && w_next < key[next] ){
            parent[next]= n;
            key[next]= w_next;

                }
               }
       }
 }

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
    Graph g(v=9);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7,11);
    g.addEdge(2, 8, 2);

    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.printGraph();

    cout<<"\nEnter source: ";
    cin >> s;
    //cout << "\nBreadth First Traversal :\n"<<endl;
    g.prims(s);

    //cout << "\nFrom node " << s << "\n" << endl;
    //for (int i = 0; i < v; i++){
      //  cout << "Distance of " << i << " is : " << g.key[i] << endl;
    //}

     int sum=0;
    for(int i = 0; i < v; i++){
        //int sum=0;
        sum = sum + g.key[i];
    }
    cout<<sum <<endl;
//Queue q;


    return 0;
}
