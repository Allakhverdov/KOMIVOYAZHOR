//
//  min_way.hpp


//найдём точный путь комивояжера

#ifndef min_way_hpp
#define min_way_hpp
#include <iostream>
#include <algorithm>
#include "MatrixGraph.hpp"
struct MinWay
{
    double this_way (MatrixGraph& G, std::vector<int>permutation);
    double get_min_way (MatrixGraph& G);
};
#endif /* min_way_hpp */
