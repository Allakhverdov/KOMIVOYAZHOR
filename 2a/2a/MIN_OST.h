//
//  MIN_OST.h
//  2a

#ifndef MIN_OST_h
#define MIN_OST_h

#include<iostream>
#include<vector>

struct Edge
{
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight){}
    Edge(){}
    int from = 0;
    int to = 0;
    int weight = 0;
};

class Cmp
{
public:
    bool operator() (const Edge &a, const Edge &b)
    {
        return a.weight < b.weight;
    }
}cmpp;

struct ArcGraph
{
    explicit ArcGraph(size_t EdgeCount);
    ~ArcGraph() = default;
    void AddEdge(int from, int to, int weight);
    int ECount() const;
    std::vector<Edge> GetAllEdge() const;
private:
    std::vector<Edge>AllEdge;
};

ArcGraph::ArcGraph(size_t EdgeCount)
{
    AllEdge.resize(EdgeCount);
}

void ArcGraph::AddEdge(int from, int to, int weight)
{
    Edge new_edge(from, to, weight);
    AllEdge.push_back(new_edge);
}

int ArcGraph::ECount() const
{
    return AllEdge.size();
}

std::vector<Edge> ArcGraph::GetAllEdge() const
{
    return AllEdge;
}

struct Peak
{
    Peak(int parent, int me): parent(parent), me(me){}
    Peak(){}
    int parent = 0;
    int me = 0;
    int rank = 0;
};

struct DSU
{
    DSU(size_t VCount);
    void Union(int x,int y);
    void Link(int x,int y);
    int FindSet(int x);
    //private:
    std::vector<Peak>Trees;
};

DSU::DSU(size_t VCount)
{
    Trees.resize(VCount);
    for(int i = 0; i < VCount; ++i)
    {
        
        Trees[i].me = i;
        Trees[i].parent = i;
        Trees[i].rank = 0;
    }
}

int DSU::FindSet(int x)
{
    if (Trees[x].me != Trees[x].parent)
    {
        Trees[x].parent = FindSet(Trees[x].parent);
    }
    return Trees[x].parent;
}

void DSU::Link(int x_root,int y_root)
{
    if(Trees[x_root].rank > Trees[y_root].rank)
    {
        Trees[y_root].parent = x_root;
    }
    else if(Trees[x_root].rank < Trees[y_root].rank)
    {
        Trees[x_root].parent = y_root;
    }
    if(Trees[x_root].rank == Trees[y_root].rank)
    {
        Trees[x_root].rank = Trees[y_root].rank + 1;
        Trees[y_root].parent = x_root;
    }
}

void DSU::Union(int x,int y)
{
    Link(FindSet(x), FindSet(y));
}

int Kruskal (ArcGraph G, int V)
{
    int answer = 0;
    DSU forest (V);
    std::vector<Edge>AllEdge = G.GetAllEdge();
    std::sort(AllEdge.begin(), AllEdge.end(), cmpp);
    for(int i = 0; i < G.ECount(); ++i)
    {
        Edge next_edge = AllEdge[i];
        if(forest.FindSet(next_edge.from) != forest.FindSet(next_edge.to))
        {
            //std::cout<<"соединил "<<next_edge.from<<next_edge.to<<std::endl;
            forest.Union(next_edge.from, next_edge.to);
            answer += next_edge.weight;
        }
    }
    return answer;
}

int main()
{
    //    DSU A(10);
    //    A.Union(3, 5);
    //    A.Union(5, 7);
    //    A.Union(5, 9);
    //    A.Union(1, 2);
    //    std::cout << A.FindSet(5);
    //    std::cout << A.FindSet(9);
    //    std::cout << A.FindSet(2);
    //    std::cout << A.FindSet(1);
    
    int E = 0;
    int V = 0;
    ArcGraph G(0);
    std::cin >> V >> E;
    for(int i = 0; i < E; ++i)
    {
        int from = 0;
        int to = 0;
        int weight = 0;
        std::cin >> from >> to >> weight;
        G.AddEdge(from - 1, to - 1, weight);
    }
    
    std::cout << Kruskal(G, V);
    
    return 0;
}


#endif /* MIN_OST_h */
