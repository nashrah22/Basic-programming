#include <iostream>
#include <queue>
#include <set>
//#include <multiset>
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
        int smallest,w[16];
        //Queue q;
        list<int> Q;
        int nd,u,ver;
        set<int> A={};
        //A = {};

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
//void Make_Set(int s,int i){
//et<int>s'i'


void Kruskal(){
Node * tmp;
set<int> s[v];
for (int i = 0; i < v; i++) {
        // Insert the column elements
            s[i].insert(a[i].val);
    }

     set<int>::iterator it2;

// sort edges by weight

multiset<int> weight= {80,54,47,75,23,88,55,66,32,93,74,31,74,29,79,68};

    multiset<int>::iterator it;

    for(it=weight.begin(); it!=weight.end(); it++){
        //cout<<*it<<endl;
      for(int i=0;i<v;i++){
        tmp=a[i].head;
        while(tmp !=NULL){
        if(tmp->w == *it){
                u=a[i].val;
                ver=tmp->data;
               // find_set(u,ver);

        for(it2=s[i].begin(); it2!=s[i].end(); it2++){
        {if(s[i].count(u)== 1){
            if (s[i].count(ver)==0)
            {
            A.insert(u);
            A.insert(ver);
            //union
            s[i].insert(ver);
            s[ver].clear();

            }
            }
            else if(s[i].count(ver)== 1){
            if (s[i].count(u)==0)
            {A.insert(u);
            A.insert(ver);
            s[i].insert(u);
            s[u].clear();

            }
            }

      }

       }
            }

            tmp=tmp->next;
        }

        }
      }

      //Find set

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

    g.addEdge(0, 1, 54);
    g.addEdge(0, 6, 47);
    g.addEdge(0, 5, 80);

    g.addEdge(1, 2,74);
    g.addEdge(1, 6, 75);

    g.addEdge(6, 2, 88);
    g.addEdge(6, 7, 55);
    g.addEdge(6, 4, 66);
    g.addEdge(6, 5, 23);

    g.addEdge(5, 7, 32);
    g.addEdge(5, 4, 93);

    g.addEdge(2, 3, 29);
    g.addEdge(2, 7, 31);

    g.addEdge(3, 7, 79);
    g.addEdge(3, 4, 68);
    g.addEdge(7, 4, 74);

  //  g.printGraph();

    cout<<"\nEnter source: ";
    cin >> s;
    //cout << "\nBreadth First Traversal :\n"<<endl;
    g.Kruskal();

    //cout << "\nFrom node " << s << "\n" << endl;
    //for (int i = 0; i < v; i++){
      //  cout << "Distance of " << i << " is : " << g.key[i] << endl;
    //}


     set<int>::iterator it3;
     for(int i=0; i<v; i++){

        for(it3=g.A.begin(); it3!=g.A.end(); it3++)
        {//cout<<"sets:"<<endl;
            cout<<*it3<<endl;
      }
      }


    return 0;
}
