#include <iostream>

#include "src/BasePrintableString.h"

#include "src/PostComaDecorator.h"
#include "src/PostEndlDecorator.h"
#include "src/PostExclaimDecorator.h"
#include "src/PostSpaceDecorator.h"
#include "src/PostWordDecorator.h"
#include "src/PreWordDecorator.h"

int main()
{
    BasePrintableString* cout = new BasePrintableString("");

    cout = new PreWordDecorator(cout);
    cout = new PostComaDecorator(cout);
    cout = new PostSpaceDecorator(cout);
    cout = new PostWordDecorator(cout);
    cout = new PostExclaimDecorator(cout);
    cout = new PostEndlDecorator(cout);

    cout->print();
}
