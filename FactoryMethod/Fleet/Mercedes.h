#pragma once

#include <iostream>
#include <string>


class Mercedes
{
    int factoryId;
    std::string factoryTitle;

public:
    Mercedes() = delete;
    Mercedes(int factoryId, const std::string& factoryTitle);

    std::string getFactoryTitle() const;
    int getFactoryId() const;

    void setFactoryId(int factoryId);
    void setFactoryTitle(const std::string& factoryTitle);
};