#include <iostream>
#include "list.hpp"


int main() {
    List<int> Example{1,2,3};

    Example.Display();

    Example.PopFront();

    Example.Display();
}