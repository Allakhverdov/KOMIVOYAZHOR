//
//  ArcGraph.cpp


#include "ArcGraph.hpp"

ArcGraph::ArcGraph(size_t EdgeCount)
{
    AllEdge.resize(EdgeCount);
}

void ArcGraph::AddEdge(int from, int to, double weight)
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

void ArcGraph::Cout_in_File(std::ofstream &fout)
{
    std::set<std::pair<int, int>>set_;
    for(int i = 0; i < AllEdge.size(); ++i)
    {
        std::pair<int, int> p_1;
        std::pair<int, int> p_2;
        p_1.first = AllEdge[i].from;
        p_1.second = AllEdge[i].to;
        p_2.first = AllEdge[i].to;
        p_2.second = AllEdge[i].from;
        if(!(set_.count(p_1) > 0 || set_.count(p_2) > 0))
        {
            set_.insert(p_2);
            fout << "from:" << AllEdge[i].from << " to:" << AllEdge[i].to << " weight:" << AllEdge[i].weight << std::endl;
        }
    }
}
