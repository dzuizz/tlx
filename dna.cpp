#include "dna.h"

std::string s1, s2;
void init(std::string a, std::string b) {
	s1=a, s2=b;
}

int get_distance(int x, int y) {
	int need_to_mutate = 0;
	std::string sub_a = s1.substr(x, y-x+1), sub_b = s2.substr(x, y-x+1);
	int count_sub_a[3] = {0, 0, 0}, count_sub_b[3] = {0, 0, 0};
	for(int i=0;i<y-x+1;i++){
		switch (sub_a[i]){
		case 'A':
			count_sub_a[0] += 1;
			break;
		case 'T':
			count_sub_a[1] += 1;
			break;
		case 'C':
			count_sub_a[2] += 1;
			break;
		default:
			break;
		}
		switch (sub_b[i]){
		case 'A':
			count_sub_b[0] += 1;
			break;
		case 'T':
			count_sub_b[1] += 1;
			break;
		case 'C':
			count_sub_b[2] += 1;
			break;
		default:
			break;
		}
	}
	if(count_sub_a[0]==count_sub_b[0] && count_sub_a[1]==count_sub_b[1] && count_sub_a[2]==count_sub_b[2]){
		for(int i=0;i<y-x+1;i++){
			if(sub_a[i]!=sub_b[i]){
				need_to_mutate++;
			}
		}
		return (need_to_mutate+need_to_mutate%2)/2;
	}else{
		return -1;
	}
}
