//
//  ArcGraph.hpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#ifndef ArcGraph_hpp
#define ArcGraph_hpp
#include<iostream>
#include<vector>
#include "struct_Edge.hpp"
struct ArcGraph
{
    explicit ArcGraph(size_t EdgeCount);
    ~ArcGraph() = default;
    void AddEdge(int from, int to, double weight);
    int ECount() const;
    std::vector<Edge> GetAllEdge() const;
private:
    std::vector<Edge>AllEdge;
};
#endif /* ArcGraph_hpp */
