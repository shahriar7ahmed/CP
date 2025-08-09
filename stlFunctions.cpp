//STL function implementations
#include<bits/stdc++.h>
using namespace std;
// stl basic functions
void stlBasicFunctions() {
    // Example of using STL vector
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Vector elements: ";
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;

    map<string, int> m;
    m["apple"] = 1;
    m["banana"] = 2;
    m["cherry"] = 3;
    
    cout << "Map elements:\n";
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;
}
// stl sort function
void stlSortFunction() {
    vector<int> vec = {5, 2, 9, 1, 5, 6};
    cout << "Before sorting: ";
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end());

    cout << "After sorting: ";
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;
}
int main() {
    cout << "STL Basic Functions:\n";
    stlBasicFunctions();
    
    cout << "\nSTL Sort Function:\n";
    stlSortFunction();

    return 0;
}   