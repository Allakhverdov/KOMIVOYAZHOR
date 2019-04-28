//
//  struct_Edge.hpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#ifndef struct_Edge_hpp
#define struct_Edge_hpp
struct Edge
{
    Edge(int from, int to, double weight) : from(from), to(to), weight(weight){}
    Edge(){}
    int from = 0;
    int to = 0;
    double weight = 0;
    bool operator <(const Edge& a) const
    {
        return weight < a.weight;
    }
};

#endif /* struct_Edge_hpp */
