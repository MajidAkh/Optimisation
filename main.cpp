#include "DPkClusteringMemKN.hpp"

#include <chrono>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {

		
	  	int k = 5;
	    string filename;

	    filename = "data/dataAlea2_50/dataAlea2_50_ex1.txt";
			
	   	if(argc > 1) k = atoi(argv[1]);
	    if(argc > 2) filename = argv[2];

	    DPkClusteringMemKN solver;
		

	    solver.importInstance(filename);
		solver.setK(k);
		solver.setfunc(&DPkClustering::K_Medoids);



	    cout << "Constructeur fini\n";
	    std::chrono::time_point<std::chrono::system_clock> start, end;
			start = std::chrono::system_clock::now();
			solver.solve();
			end = std::chrono::system_clock::now();
			cout<<endl;
			
	    solver.display();
	    cout << "Resolution terminee en  "<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() <<" ms\n";

			
	return 0;
}
