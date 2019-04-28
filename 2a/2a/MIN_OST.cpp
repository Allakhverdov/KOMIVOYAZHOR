//
//  MIN_OST.cpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

//#include "MIN_OST.hpp"
//#include<iostream>
//#include<vector>
//#include "struct_Edge.hpp"
//#include "class_cmp.hpp"
//#include "ArcGraph.hpp"
//#include "Peak.cpp"
//#include"DSU.hpp"
//
//int Kruskal (ArcGraph G, int V)
//{
//    int answer = 0;
//    DSU forest (V);
//    std::vector<Edge>AllEdge = G.GetAllEdge();
//    std::sort(AllEdge.begin(), AllEdge.end(), cmpp);
//    for(int i = 0; i < G.ECount(); ++i)
//    {
//        Edge next_edge = AllEdge[i];
//        if(forest.FindSet(next_edge.from) != forest.FindSet(next_edge.to))
//        {
//            //std::cout<<"соединил "<<next_edge.from<<next_edge.to<<std::endl;
//            forest.Union(next_edge.from, next_edge.to);
//            answer += next_edge.weight;
//        }
//    }
//    return answer;
//}
