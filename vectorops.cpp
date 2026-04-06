// vectorops.cpp -- Implementation of vector operations

#include "vectorops.h"
#include "iostream"
#include "algorithm"
#include <fstream>

namespace vectorops {
    void display(const std::vector<int>& v) {
        std::for_each(v.begin(), v.end(), [](int num){
            std::cout << num << " ";
        });

        std::cout << std::endl;
    }

    //------
    SortOrder::SortOrder(bool asc): ascending(asc) {}
    bool SortOrder::operator()(int a, int b) const {
        if (ascending) {
            return a < b;
        } else {
            return a > b;
        }
    }
    void sortVector(std::vector<int>& v, bool ascending) {
        std::sort(v.begin(), v.end(), SortOrder(ascending));
    }

    //------
    AddValue::AddValue(int val): amount(val) {}
    int AddValue::operator()(int num) const {
        return num + amount;
    }
    void addToEach(std::vector<int>& v, int value) {
        std::transform(v.begin(), v.end(), v.begin(), AddValue(value));
    }

    //------
    int countGreaterThan(const std::vector<int>& v, int threshold) {
        int count = std::count_if(v.begin(), v.end(), [threshold](int num){
            return num > threshold;
        });
        return count;
    }


    //------
    bool saveToFile(const std::vector<int>& v, const std::string& filename) {
        try
        {
            std::ofstream outFile(filename);
            if (!outFile) {
                std::cerr << "Error opening file for writing: " << filename << std::endl;
                return false;
            }

            for (const int& num : v) {
                outFile << num << " ";
            }

            outFile.close();
            return true;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception occurred while saving to file: " << e.what() << std::endl;
            return false;
        }
        
    }

    //------
    std::vector<int> loadFromFile(const std::string& filename) {
        std::vector<int> v;
        try
        {
            std::ifstream inFile(filename);
            if (!inFile) {
                std::cerr << "Error opening file for reading: " << filename << std::endl;
                return v; // return empty vector
            }

            int num;
            while (inFile >> num) {
                v.push_back(num);
            }

            inFile.close();
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception occurred while loading from file: " << e.what() << std::endl;
        }
        
        return v;
    }


}