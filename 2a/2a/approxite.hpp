//
//  approxite.hpp

//через крускал найдём 2-приближение
//через Euler найдём 1,5-приближение

#ifndef approxite_hpp
#define approxite_hpp

#include "ArcGraph.hpp"
#include "MatrixGraph.hpp"
#include "DSU.hpp"
double Kruskal (ArcGraph G, int V);
double Euler (ArcGraph& A_G, MatrixGraph& M_G, int V);

#endif /* approxite_hpp */
