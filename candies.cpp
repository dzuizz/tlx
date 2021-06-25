#include "candies.h"

#include <vector>

std::vector<int> distribute_candies(std::vector<int> c, std::vector<int> l,
                                    std::vector<int> r, std::vector<int> v) {
    int n = c.size();
    std::vector<int> s(n);
    for(int j=0;j<=v.size();j++){
        if(v[j] > 0){
            for(int k=l[j];k<=r[j];k++){
                s[k] = std::min(c[k], s[k]+v[j]);
            }
        }else{
            for(int k=l[j];k<=r[j];k++){
                s[k] = std::max(0, s[k]+v[j]);
            }
        }
    }
    return s;
}
