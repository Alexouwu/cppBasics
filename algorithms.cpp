// Merge sort
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

void printArray(const std::vector<int>& array) {
    std::cout << "[";
    if (array.size() > 0) {
        std::cout << array[0];
        for (int i = 1; i < array.size(); i++) {
            std::cout << ", " << array[i];
        }
    }
    std::cout << "]" << std::endl;
}

void cvt(std::string& s) { std::replace(s.begin(), s.end(), '\\', '/'); }

void splitArray(const std::vector<int>& array, std::vector<int>& out1,
                std::vector<int>& out2) {
    if (array.size() < 1) {
        return;
    } else {
        int i = 0;
        for (; i < array.size() / 2; i++) {
            out1.push_back(array[i]);
        }
        for (; i < array.size(); i++) {
            out2.push_back(array[i]);
        }
    }

    return;
}

void mergeSort(const std::vector<int>& array, std::vector<int>& out) {
    // std::cout<<"MergeSort for"<<std::endl;
    if (array.size() < 2) {
        out = array;
        return;
    }
    if (array.size() == 2) {
        out = array;
        if (array[0] < array[1]) {
            return;
        }
        std::swap(out[0], out[1]);
        return;
    }
    std::vector<int> outS1, outS2, out1, out2;
    splitArray(array, outS1, outS2);
    mergeSort(outS1, out1);
    mergeSort(outS2, out2);
    int i{}, j{};
    for (int k = 0; k < array.size(); k++) {
        if (i >= out1.size()) {
            out.push_back(out2[j]);
            j++;
        } else if (j >= out2.size()) {
            out.push_back(out1[i]);
            i++;
        } else if (out1[i] < out2[j]) {
            out.push_back(out1[i]);
            i++;
        } else {
            out.push_back(out2[j]);
            j++;
        }
    }
    return;
}

int main() {
    std::vector<int> myVector = {11, 80, 3,  4, 5, 6,  1, 10,
                                 15, 2,  12, 8, 6, 20, 13};
    std::vector<int> myVec = {8, 9, 60, 7};
    std::vector<int> out1, out;
    std::vector<int> out2;
    mergeSort(myVector, out);
    printArray(out);
    return 0;
}
