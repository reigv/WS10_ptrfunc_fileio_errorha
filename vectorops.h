// vectorops.h -- A header file for vector operations
#ifndef VECTOROPS_H_
#define VECTOROPS_H_

#include <vector>
#include <string>

namespace vectorops {
    void display(const std::vector<int>& v);

    // sort asd or desc --------- functor --------- create a class that overloads
    class SortOrder {
    private:
        bool ascending; // the internal state of the functor, determines sorting order

    public:
        SortOrder(bool asc);
        bool operator()(int a, int b) const;
    };

    void sortVector(std::vector<int>& v, bool ascending);


    // add to each element
    class AddValue {
    private:
        int amount;
    public:
        AddValue(int val);
        int operator()(int num) const;
    };
    void addToEach(std::vector<int>& v, int value);


    // count greater than a value
    int countGreaterThan(const std::vector<int>& v, int threshold);


    // save to file
    bool saveToFile(const std::vector<int>& v, const std::string& filename);


    // load from file
    std::vector<int> loadFromFile(const std::string& filename);
    
}


#endif // VECTOROPS_H_