#include "dna.h"
#include <algorithm>

int l_pairs[100000][6]; // AT, TA, AC, CA, CT, TC
void init(std::string a, std::string b) {
	//pairs
	if(a[0]=='A'){
		if(b[0]=='T') l_pairs[0][0]++;
		else if(b[0]=='C') l_pairs[0][2]++;
	}else if(a[0]=='T'){
		if(b[0]=='A') l_pairs[0][1]++;
		else if(b[0]=='C') l_pairs[0][5]++;
	}else{
		if(b[0]=='A') l_pairs[0][3]++;
		else if(b[0]=='T') l_pairs[0][4]++;
	}
	for(int i=1;i<a.length();i++){
		for(int j=0;j<6;j++) l_pairs[i][j] = l_pairs[i-1][j];
		if(a[i]=='A'){
			if(b[i]=='T') l_pairs[i][0]++;
			else if(b[i]=='C') l_pairs[i][2]++;
		}else if(a[i]=='T'){
			if(b[i]=='A') l_pairs[i][1]++;
			else if(b[i]=='C') l_pairs[i][5]++;
		}else{
			if(b[i]=='A') l_pairs[i][3]++;
			else if(b[i]=='T') l_pairs[i][4]++;
		}
	}
}

int get_distance(int x, int y) {
	int mutations = 0, rem=0;
	int nAT = l_pairs[y][0], nTA = l_pairs[y][1];
	int nAC = l_pairs[y][2], nCA = l_pairs[y][3];
	int nCT = l_pairs[y][4], nTC = l_pairs[y][5];
	int pairs[6];
	if(x>0){
		nAT -= l_pairs[x-1][0], nTA -= l_pairs[x-1][1];
		nAC -= l_pairs[x-1][2], nCA -= l_pairs[x-1][3];
		nCT -= l_pairs[x-1][4], nTC -= l_pairs[x-1][5];
		if((nAT + nAC == nTA + nCA) && (nTA + nTC == nAT + nCT) && (nCA + nCT == nAC + nTC)){
			for(int i=0;i<6;i++) pairs[i] = l_pairs[y][i] - l_pairs[x-1][i];
			for(int i=0;i<6;i+=2){
				int smaller = std::min(pairs[i], pairs[i+1]);
				mutations += smaller;
				pairs[i] -= smaller;
				pairs[i+1] -= smaller;
				rem += pairs[i] + pairs[i+1];
			}
			mutations += rem/3*2;
		}else return -1;
	}else{
		if((nAT + nAC == nTA + nCA) && (nTA + nTC == nAT + nCT) && (nCA + nCT == nAC + nTC)){
			for(int i=0;i<6;i++) pairs[i] = l_pairs[y][i];
			for(int i=0;i<6;i+=2){
				int smaller = std::min(pairs[i], pairs[i+1]);
				mutations += smaller;
				pairs[i] -= smaller;
				pairs[i+1] -= smaller;
				rem += pairs[i] + pairs[i+1];
			}
			mutations += rem/3*2;
		}else return -1;
	}
	return mutations;
}