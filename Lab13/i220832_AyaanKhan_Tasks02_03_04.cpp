#include<iostream>
#include<queue>
using namespace std;


class Node
{
public:
    int data;
    int weight;
    Node* next;

    Node()
    {
        data = -1;
        next = NULL;
        weight = 1;
    }

    Node(int id)
    {
        weight = 1;
        data = id;
        next = NULL;
    }

    Node(int id, int z)
    {
        weight = z;
        data = id;
        next = NULL;
    }
};


class AdjList
{
public:
    Node* head;

    AdjList()
    {
        head = NULL;
    }

    void Insert(Node* ptr)
    {
        ptr->next = head;
        head = ptr;
    }

    void Display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            temp = temp->next;
        }
        //cout << std::endl;
    }
};

class Graph
{
public:
    int maxVertices;
    int noOfVertices;
    AdjList* list;
    int count;

    Graph()
    {
        maxVertices = 0;
        noOfVertices = 0;
        list = NULL;
        count = 0;
    }

    Graph(int x)
    {
        maxVertices = x;
        noOfVertices = 0;
        list = new AdjList[maxVertices];

        for (int i = 0; i < maxVertices; i++)
        {
            list[i].head = new Node(i + 1);
        }

        count = 0;
    }

    ~Graph()
    {
        delete[] list;
    }

    Node* createVertex(int data)
    {
        if (noOfVertices < maxVertices)
        {
            Node* ptr = new Node(data);
            noOfVertices++;
            return ptr;
        }
        else
        {
            return NULL;
        }
    }

    void insertEdge(int x, int y)
    {
        Node* temp = list[x - 1].head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = new Node(y);

        Node* temp2 = list[y - 1].head;

        while (temp2->next)
        {
            temp2 = temp2->next;
        }

        temp2->next = new Node(x);
    }

    void insertEdge(int x, int y, int z)
    {
        Node* temp = list[x - 1].head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = new Node(y, z);

        Node* temp2 = list[y - 1].head;

        while (temp2->next)
        {
            temp2 = temp2->next;
        }

        temp2->next = new Node(x, z);
    }

    void showGraphStructure()
    {
        for (int i = 0; i < maxVertices; i++)
        {
            Node* temp = list[i].head;

            while (temp->next)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }

            cout << temp->data << endl;
        }

    }

    void Graphdisplay()
    {
        showGraphStructure();
    }

    void dijkstra(int x) 
    {
        int* dist = new int[maxVertices];
        bool* visited = new bool[maxVertices];

        for (int i = 0; i < maxVertices; i++) 
        {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[x - 1] = 0;
        queue<int> q;
        q.push(x);

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();

            if (visited[u - 1])
                continue;

            visited[u - 1] = true;

            Node* temp = list[u - 1].head;

            while (temp != nullptr) 
            {
                int v = temp->data;
                int weight = temp->weight;

                if (!visited[v - 1] && dist[u - 1] != INT_MAX && dist[u - 1] + weight < dist[v - 1]) 
                {
                    dist[v - 1] = dist[u - 1] + weight;
                    q.push(v);
                }
                temp = temp->next;
            }
        }

        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < maxVertices; i++) {
            cout << i + 1 << " \t\t " << dist[i] << endl;
        }
    }


    void primMST() 
    {
        int* parent = new int[maxVertices];
        int* key = new int[maxVertices];
        bool* inMST = new bool[maxVertices];
        queue<int> q;

        for (int i = 0; i < maxVertices; i++) 
        {
            key[i] = INT_MAX;
            inMST[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;
        q.push(0);

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();

            if (inMST[u])
                continue;

            inMST[u] = true;

            Node* temp = list[u].head;

            while (temp != nullptr) 
            {
                int v = temp->data - 1;
                int weight = temp->weight;

                if (!inMST[v] && weight < key[v]) 
                {
                    key[v] = weight;
                    parent[v] = u;
                    q.push(v);
                }

                temp = temp->next;
            }
        }

        cout << "Edge \tWeight\n";
        for (int i = 1; i < maxVertices; i++) {
            cout << parent[i] + 1 << " - " << i + 1 << " \t" << key[i] << " \n";
        }
    }
};



int main()
{
    Graph g1(8);

        g1.insertEdge(1, 2, 2);
        g1.insertEdge(2, 3, 6);
        g1.insertEdge(4, 5, 3);
        g1.insertEdge(1, 5, 5);
        g1.insertEdge(6, 1, 4);
        g1.insertEdge(7, 4, 1);
        g1.insertEdge(3, 8, 9);

        g1.Graphdisplay();
        cout << endl;
        g1.dijkstra(1);
        cout << endl;
        g1.primMST();

    return 0;
}