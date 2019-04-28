//
//  1,5 - approximation.cpp
//  2a
//
//  Created by Эдуард on 28.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#include "2 - 1,5 - approximation.h"

double Kruskal (ArcGraph G, int V)     ///по ссылке?
{
    double answer = 0;
    DSU forest (V);
    std::vector<Edge>AllEdge = G.GetAllEdge();
    std::sort(AllEdge.begin(), AllEdge.end());
    for(int i = 0; i < G.ECount(); ++i)
    {
        Edge next_edge = AllEdge[i];
        if(forest.FindSet(next_edge.from) != forest.FindSet(next_edge.to))
        {
            forest.Union(next_edge.from, next_edge.to);
            answer += next_edge.weight;
        }
    }
    return answer;
}

////////////////
////////////////
////////////////

double Kruskal_ (ArcGraph& A_G, MatrixGraph& M_G, int V)
{
    double answer = 0;
    DSU forest (V);
    std::vector<Edge>AllEdge = A_G.GetAllEdge();
    std::vector<int>deg(V,0);
    std::vector<int>odd_top;
    std::vector<bool>used(V,false);
    std::vector<std::vector<double>> Minost(V,std::vector<double>(V,-1));
    std::vector<std::vector<double>> Matrix = M_G.GetAll();
    std::sort(AllEdge.begin(), AllEdge.end());
    for(int i = 0; i < A_G.ECount(); ++i)
    {
        Edge next_edge = AllEdge[i];
        if(forest.FindSet(next_edge.from) != forest.FindSet(next_edge.to))
        {
            forest.Union(next_edge.from, next_edge.to);
            answer += next_edge.weight;
            Minost[next_edge.from][next_edge.to] = next_edge.weight;
            Minost[next_edge.to][next_edge.from] = next_edge.weight;
            //std::cout<<next_edge.from<< " " <<next_edge.to << std::endl;
            ++deg[next_edge.from];
            ++deg[next_edge.to];
        }
    }
    //std::cout<<std::endl<<"//////"<<std::endl;
    for(int i = 0; i < V; ++i)
    {
        if(deg[i] % 2)
        {
            //std::cout<< i <<" ";
            odd_top.push_back(i);
            used[i] = true;
        }
    }
    //std::cout<<std::endl<<"//////"<<std::endl;
    double now_min = 10e9;
    int from = 0;
    int to = 0;
    for(int l = 0; l < odd_top.size() ; ++l)
    {
        for(int i = 0; i < odd_top.size(); ++i)
        {
            for(int j = 0; j < odd_top.size(); ++j)
            {
                if(i == j){continue;}
                if(Minost[odd_top[i]][odd_top[j]] == -1 && used[odd_top[i]] && used[odd_top[j]] && Matrix[odd_top[i]][odd_top[j]] < now_min)
                {
                    from = odd_top[i];
                    to = odd_top[j];
                    now_min = Matrix[odd_top[i]][odd_top[j]];
                }
            }
        }
        if(now_min == 10e9){/*std::cout<<"NOP"*/;continue;}
        Minost[from][to] = now_min;
        Minost[to][from] = now_min;
        used[from] = false;
        used[to] = false;
        answer += now_min;
        //std::cout<<from<< " " <<to<<" "<<now_min<<std::endl;
        now_min = 10e9;
    }
    return answer;
}

////////////////
////////////////
////////////////
