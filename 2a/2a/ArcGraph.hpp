
//  ArcGraph.hpp


//это просто ArcGraph

#ifndef ArcGraph_hpp
#define ArcGraph_hpp
#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "struct_Edge.hpp"
struct ArcGraph
{
    explicit ArcGraph(size_t EdgeCount);
    ~ArcGraph() = default;
    void AddEdge(int from, int to, double weight);
    void Cout_in_File(std::ofstream &fout);             //эта функция записывает результаты в фаил File.txt
    int ECount() const;
    std::vector<Edge> GetAllEdge() const;
private:
    std::vector<Edge>AllEdge;
};
#endif /* ArcGraph_hpp */
