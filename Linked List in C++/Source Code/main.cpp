#include <iostream>
#include "list.hpp"


int main() {
    List<int> A;
    List<int> B({1,2,3,4});
    List<std::string> C{"Hello", "There"};

    A.PopFront();

    A.PushFront(5);
    A.PushFront(23);
 
    B.PushFront(5);
    B.PushFront(23);
    B.PushFront(2);


    std::cout << (B == A) << '\n';

    B.DisplayList();
    C.DisplayList();
    
    std::cout << A.Size() << '\n';

    return 0;
}