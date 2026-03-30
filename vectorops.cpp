// vectorops.cpp -- Implementation of vector operations

#include "vectorops.h"
#include "iostream"
#include "algorithm"

namespace vectorops {
    void display(const std::vector<int>& v) {
        std::for_each(v.begin(), v.end(), [](int num){
            std::cout << num << " ";
        });

        std::cout << std::endl;
    }

    void sortVector(std::vector<int>& v, bool ascending) {
        if (ascending) {
            std::sort(v.begin(), v.end(), [](int a, int b) {
                return a < b;
            });
        } else {
            std::sort(v.begin(), v.end(), [](int a, int b) {
                return a > b;
            });

        }
    }


}