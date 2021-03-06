//  DSU.hpp

#ifndef DSU_hpp
#define DSU_hpp
#include<iostream>
#include<vector>
#include"Peak.hpp"
struct DSU
{
    DSU(size_t VCount);
    void Union(int x,int y);
    void Link(int x,int y);
    int FindSet(int x);
private:
    std::vector<Peak>Trees;
};

#endif /* DSU_hpp */
