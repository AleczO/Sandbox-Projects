#include <iostream>
#include "list.hpp"


int main() {
    List<int> Example;

    std::cout << "List is initially empty thus, Example.Empty() returns " << Example.Empty() << '\n';

    Example.PushFront(10);

    std::cout << "Now list has element " << Example.Empty() << '\n';

    return 0;
}