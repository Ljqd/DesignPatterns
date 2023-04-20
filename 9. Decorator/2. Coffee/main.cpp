#include <iostream>

#include "src/Beverage.h"
#include "src/DarkRoast.h"
#include "src/Decaf.h"
#include "src/Espresso.h"

#include "src/BaseBeverageDecorator.h"
#include "src/MilkDecorator.h"
#include "src/SugarDecorator.h"
#include "src/CreamDecorator.h"
#include "src/MilkCreamDecorator.h"

int main()
{
    //Espresso with two sugars.
    Beverage* espresso = new Espresso(30);
    BaseBeverageDecorator* milkCreamEspresso = new MilkCreamDecorator(espresso);
    BaseBeverageDecorator* milkCreamAndSugarEspresso = new SugarDecorator(milkCreamEspresso);
    BaseBeverageDecorator* milkCreamAndDoubleSugarEspresso = new SugarDecorator(milkCreamAndSugarEspresso);

    std::cout << milkCreamAndDoubleSugarEspresso->description() << std::endl;

    //Black coffee with milk cream and two portions of sugar.
    Beverage* blackCoffee = new DarkRoast(40);
    BaseBeverageDecorator* milkBlackCoffee = new MilkDecorator(blackCoffee);
    BaseBeverageDecorator* milkAndSugarBlackCoffee = new SugarDecorator(milkBlackCoffee);
    BaseBeverageDecorator* milkAndDoubleSugarBlackCoffee = new SugarDecorator(milkAndSugarBlackCoffee);

    std::cout << milkAndDoubleSugarBlackCoffee->description() << std::endl;

    //Black coffee with cream and a portion of sugar.
    Beverage* blackCoffee2 = new DarkRoast(40);
    BaseBeverageDecorator* creamBlackCoffee2 = new CreamDecorator(blackCoffee2);
    BaseBeverageDecorator* creamAndSugarBlackCoffee2 = new SugarDecorator(creamBlackCoffee2);

    std::cout << creamAndSugarBlackCoffee2->description() << std::endl;

    
    //Decaffeinated coffee with milk and two sugars.
    Beverage* decaf = new Decaf(50);
    BaseBeverageDecorator* milkDecaf = new MilkCreamDecorator(decaf);
    BaseBeverageDecorator* milkAndSugarDecaf = new SugarDecorator(milkDecaf);
    BaseBeverageDecorator* milkAndDoubleSugarDecaf = new SugarDecorator(milkAndSugarDecaf);

    std::cout << milkAndDoubleSugarDecaf->description() << std::endl;
}