#include <iostream>
#include <map>
int main(){
    std::map<int, int> mp {{'a',9}, {'b', 10}};
    std::cout << "Size: " << mp.size() << std::endl;
    // method-1: accessing elements in map
    // at will throw an exception if key not found
    std::cout << mp.at('a') << "\n";
    // method-2: accessing elements in map
    // using this method, if key not found then it will create an new entry 
    // with that key and returns and refence to it.
    std::cout << mp['b'] << "\n";
    std::cout << mp['c'] << "\n";
    //returns maximum number of elements it canhold
    // due to system or library implmentations.
    std::cout << "Max size: " << mp.max_size() << "\n";
    //-----------insert--------------
    std::map<std::string, float > heights;
    auto p = heights.insert({"narasimha", 5.9});
    std::cout << (p.second?"success":"Failes") << std::endl;
    p = heights.insert({"narasimha", 7.9});
    std::cout << (p.second?"success":"Failes") << std::endl;
    std::cout << heights["narasimha"] << "\n";

    std::map<std::string, float> heights2;
    std::cout <<"size of heights2: " << heights2.size() << '\n';
    heights2.insert(heights.begin(), heights.end());
    std::cout <<"size of heights2: " << heights2.size() << '\n';
    heights2.insert(std::begin(heights), std::end(heights));
    std::cout <<"size of heights2: " << heights2.size() << '\n';
}