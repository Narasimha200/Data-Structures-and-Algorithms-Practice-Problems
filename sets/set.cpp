#include <iostream>
#include <map>
#include <set>

int main(){
    std::map<int, int> m = {{10,20}};
    std::set<int> s = {1, 2, 3, (4), {5},{6}};
    s.insert(1);
    s.insert(5);
    s.insert({10,20,30,50,1});
    s.insert(50.0);
    int arr[] = {1, 100, 200 , 300};
    s.insert(std::begin(arr), std::end(arr));
    std::cout << s.size() << std::endl;
    for(auto it = s.begin(); it!=s.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    s.erase(s.begin());
    for(auto it = s.begin(); it!=s.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}