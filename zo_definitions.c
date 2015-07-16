#include "zo_interpretter_types.c"

#include "zo_cluster_tree.c"

typedef struct UniversalTuringMachine{

	cluster_tree* memory;
	address* headers;
	unsigned int no_of_headers;

}UniversalTuringMachine;

enum{A=10,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,W,X,Y,Z};
