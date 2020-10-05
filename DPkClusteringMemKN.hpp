#pragma once

#include "DPkClustering.hpp"


class DPkClusteringMemKN : public DPkClustering{
    
    protected:

    float** matrixDP;

    float (DPkClustering::*func)(int k, int i)=NULL;

	void createMatrixDP();
	void deleteMatrixDP();


	std::pair<float,int> computeCase(int k, int i);
	void fillLign(int k);
	void fillresult();

	void fillFirstLine();
	void backtrack();

    public:


	void setfunc( float (DPkClustering::*fonction)(int, int)) { func= fonction;};
    void solve();

};
