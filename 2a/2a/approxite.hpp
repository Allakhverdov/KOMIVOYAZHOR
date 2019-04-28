//
//  approxite.hpp
//  2a
//
//  Created by Эдуард on 28.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#ifndef approxite_hpp
#define approxite_hpp

#include "ArcGraph.hpp"
#include "MatrixGraph.hpp"
#include "DSU.hpp"
double Kruskal (ArcGraph G, int V);
double Euler (ArcGraph& A_G, MatrixGraph& M_G, int V);

#endif /* approxite_hpp */
