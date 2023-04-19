#include "BeverageType.h"

class Black : public BeverageType
{
public:
    std::string getName() const override {
        std::cout << "BeverageType: black;" << std::endl;
        return "BeverageType: black;";
    }
};