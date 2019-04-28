//
//  ArcGraph.cpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

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
