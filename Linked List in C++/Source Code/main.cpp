#include <iostream>
#include <numeric>
#include "list.hpp"

template<typename T> void TestFunction(const List<T>& L){
    for(auto ItrL = L.cbegin(); ItrL != L.cend(); ++ItrL)
        std::cout << (*ItrL) << ' ';
    std::cout << '\n';
    return;
}

int main() {
    List<int> Example{1,2,3,6};
    
    for(auto it: Example)
        std::cout << it << ' ';
    std::cout << '\n';

    std::cout << std::accumulate(Example.cbegin(), Example.cend(), 0) << '\n';

    return 0;
}