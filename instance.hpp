#pragma once

#include <vector>
#include <iostream>
#include <utility>

class Instance {

	private:


    
//    int N;


    public:
    //Instance();
    std::vector<std::pair<float, float>> points;    
    void import(std::string filename);
    void display();
    int getSize();

    float distance(int i, int ii);
    float distance(int i, int ii, float a);
    std::pair<float, float> getPoint(int i){return points[i];};

};

