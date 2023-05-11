#pragma once

class SpyVisitor;


class MilitaryObject
{
public:
    virtual void accept(SpyVisitor& visitor) = 0;
};