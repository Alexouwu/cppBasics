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

void mergeSort(const std::vector<int>& array, std::vector<int>& out) {
    // Base cases for 2 and 1 elements
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
    // If not base case create out arrays and split array
    std::vector<int> out1, out2;
    std::vector<int> outS1(array.begin(), array.begin() + array.size() / 2);
    std::vector<int> outS2(array.begin() + array.size() / 2, array.end());

    // Merge sort the sub arrays
    mergeSort(outS1, out1);
    mergeSort(outS2, out2);

    // Merge the sorted arrays
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
    std::cout << "This is the original list:" << std::endl;
    printArray(myVector);
    std::vector<int> out;
    mergeSort(myVector, out);
    std::cout << "This is the sorted list:" << std::endl;
    printArray(out);
    return 0;
}
