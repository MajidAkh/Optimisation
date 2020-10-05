#include "DPkClusteringMemKN.hpp"
#include <cmath>

 
using namespace std;

void DPkClusteringMemKN::createMatrixDP(){
	matrixDP = new float* [K+1];
	for(int i = 0; i <= K; i++){
		matrixDP[i] = new float [N];
		for(int j = 0; j < N; j++) {
			matrixDP[i][j] =0;
			}
		}	
	
}

void DPkClusteringMemKN::deleteMatrixDP(){
	for(int i = 0; i <= K; i++){
		delete [] matrixDP[i];
	}
	delete [] matrixDP;
}


std::pair<float,int> DPkClusteringMemKN::computeCase(int k, int i) {
	//cout<< "c ( 0"<<","<<i<<") = "<< (this->*func)(0,i) <<  endl;
	float min = matrixDP[k-1][0]+(this->*func)(1, i);
	int ind = 0;

	for (int j= 2; j < i; j++ ){
		//cout<< "c ("<< j<<","<<i<<") = "<< (this->*func)(j,i) <<  endl;
		if ((matrixDP[k-1][j-1]+(this->*func)(j, i)) < min){
			min=(matrixDP[k-1][j-1]+(this->*func)(j, i));
			ind=j;

		}

	}
	
	return make_pair(min,ind);
}



void DPkClusteringMemKN::fillLign(int k) {
	
	
	for (int i =0; i< N; i++){

			matrixDP[k][i]=computeCase(k,i).first;
		
	}	
}

void DPkClusteringMemKN::fillresult(){
	pair<float, int> paire = computeCase(K,N-1);
	OPT= paire.first;
	lastIndex=paire.second;
	
}

void DPkClusteringMemKN::fillFirstLine(){
	int i;
	for (i=0; i < N; i++){
		matrixDP[1][i]= (this->*func)(0,i);
		
	}

}

void DPkClusteringMemKN::backtrack(){
	int i = N-1;
	float value=0.0;
	for (int k=K;k>=1;k--){
		for (int j=0; j<=i; j++){
			//cout<< "M ["<< k<<"]["<<i<<"] = "<<matrixDP[k][i]<<  endl;
			//cout<< "M ["<< k-1<<"]["<<j-1<<"] = "<<matrixDP[k-1][j-1]<<  endl;
			//cout<< "c ("<< j<<","<<i<<") = "<< (this->*func)(j,i) <<  endl;
			

			if (j==0){
				value=0.0;
				}
			else {
				value=matrixDP[k-1][j-1];
			}
			if (matrixDP[k][i]==value+(this->*func)(j,i)){
				for (int p=j; p<=i ; p++){
					solution.push_back(p+1);
					//cout<< "point ajouté"<< endl;
				}
			i=j-1;
			}
		}
		
	}

}


void DPkClusteringMemKN::solve(){

	clearOPT();

	if (K<=2) {
		OPT = dist(0,N-1);
		solution.push_back(0);
		solution.push_back(N-1);
		return;
	}

	createMatrixDP();
	
	fillFirstLine();
	
	for (int k=2 ; k <= K; k++ )fillLign(k);
	
	fillresult();
	//cout <<  " fill result terminé" << endl;
	/*for (int i = 1; i <= K; ++i) {
    	for (int j = 0; j < N; ++j){
     		cout << matrixDP[i][j] << " ";
     	}
    	cout << endl;
  	}*/
	backtrack();
	
	deleteMatrixDP();
}

