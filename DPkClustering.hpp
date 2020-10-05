
#pragma once

#include "instance.hpp"


class DPkClustering  {
    protected:
    Instance instance;
    std::vector<int>  solution;
    int N;
    int K;

    float OPT;
    int lastIndex;

    float dist(int i, int ii){return instance.distance(i, ii, 1.0);};

    public:
    float K_Means(int i, int j);
    std::pair<float, float> means(int i, int j);
    float K_Medoids(int i, int j);
    float medoids(int i, int j, int l);

    void importInstance(std::string filename);
    void clearOPT();
    void display();

    void setK(int k) {K = k;};
    float getOPT() {return OPT;}

    void solve();

};