#include <iostream>
#include <memory>

#include "src/CoffeeShop.h"

int main()
{
    std::unique_ptr<CoffeeShop> shop = std::unique_ptr<CoffeeShop>();
    shop->start();
}
