#include "dna.h"

int pref[100005][6], pairs[6]; // AC, CA, CT, TC, TA, AT

void init(std::string a, std::string b) {
	for (int i = 0; i < (int) a.size(); ++i) {
		for (int j = 0; j < 6; ++j) pref[i+1][j] = pref[i][j];

		if (a[i] == 'A' && b[i] == 'C') ++pref[i+1][0];
		else if (a[i] == 'C' && b[i] == 'A') ++pref[i+1][1];
		else if (a[i] == 'C' && b[i] == 'T') ++pref[i+1][2];
		else if (a[i] == 'T' && b[i] == 'C') ++pref[i+1][3];
		else if (a[i] == 'T' && b[i] == 'A') ++pref[i+1][4];
		else if (a[i] == 'A' && b[i] == 'T') ++pref[i+1][5];
	}
}

int get_distance(int x, int y) {
	for (int i = 0; i < 6; ++i) pairs[i] = pref[y+1][i] - pref[x][i];
	
	if ((pairs[0] + pairs[5] == pairs[1] + pairs[4]) && (pairs[1] + pairs[2] == pairs[0] + pairs[3]) && (pairs[4] + pairs[3] == pairs[5] + pairs[2])) {
		int ret = 0, rem = 0;
		for (auto &i : {0, 2, 4}) {
			ret += std::min(pairs[i], pairs[i+1]);
			rem += pairs[i] + pairs[i+1] - 2*std::min(pairs[i], pairs[i+1]);
		}
		return ret + rem*2/3;
	}
	return -1;
}
