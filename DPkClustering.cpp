#include "DPkClustering.hpp"
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void DPkClustering::importInstance(string filename){
	instance.import(filename);
	N = instance.getSize();
//    lastIndex = -1;
    OPT = -1.0;
}

void DPkClustering::display() {
	instance.display();
    cout << "\nN= " << N << " , K= " << K << " , OPT=" << OPT  << endl;

	 cout<<"\nSelection des points:\n";
	 for (vector<int>::iterator it2 = solution.begin() ; it2 != solution.end(); ++it2){
		 cout  << *it2 << " ";
	 }
	 cout <<endl<<endl;
}

void DPkClustering::clearOPT(){
	solution.clear();
    lastIndex = -1;
    OPT = -1.0;
}

std::pair<float, float> DPkClustering::means(int i, int j){
    float x=0.0;
    float y=0.0;

    for (int k = i; k<=j; k++){
        x= x+ instance.points[k].first;
        y= y+ instance.points[k].second;
    }

    x=x/(j-i+1);
    y=y/(j-i+1);

    return make_pair(x,y);

}

float DPkClustering::K_Means(int i, int j){
	float somme=0.0;
	std::pair<float, float> paire = means(i,j);

	for (int k= i; k<=j; k++){
		somme=somme+ (pow((instance.points[k].first - paire.first),2)+pow((instance.points[k].second - paire.second),2));

	}

	return somme;
}

float DPkClustering::medoids(int i, int j, int l){
    float value=0.0;
    for (int k=i; k<=j;k++){
		value=value+ (sqrt(pow((instance.points[k].first - instance.points[l].first),2)+pow((instance.points[k].second - instance.points[l].second),2)));

	}
	return value;
}


float DPkClustering::K_Medoids(int i, int j){
	float min=medoids(i,j,i); // min initial pour l=i
	
	for (int l=i+1; l<=j; l++){
		if (medoids(i,j,l)<min){
			min=medoids(i, j,l);
		}
	}

	return min;

}







