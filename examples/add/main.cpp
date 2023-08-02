#include <cge/cge.h>

#include <iostream>

int main(int, char*[])
{
    auto sum = cge::add(1, 1);
    std::cout << sum << std::endl;
    return 0;
}
