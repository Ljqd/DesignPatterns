#pragma once

#include "Button.h"

#include "CheckboxButton.h"
#include "DropdownButton.h"
#include "ImageButton.h"
#include "RadioButton.h"

#include "SmallButtonSize.h"
#include "MediumButtonSize.h"
#include "LargeButtonSize.h"
#include "CustomButtonSize.h"

class Canvas
{
public:
    void run() {
        // unique_ptr is more appropriate, but this is just a Bridge pattern demonstration
        ButtonSize* size1 = new SmallButtonSize();
        ButtonSize* size2 = new MediumButtonSize();
        ButtonSize* size3 = new LargeButtonSize();
        ButtonSize* size4 = new CustomButtonSize();

        Button* checkboxButton = new CheckboxButton();
        checkboxButton->setSize(size1);
        checkboxButton->draw(this);

        Button* radioButton = new RadioButton();
        radioButton->setSize(size2);
        radioButton->draw(this);

        Button* dropdownButton = new DropdownButton();
        dropdownButton->setSize(size3);
        dropdownButton->draw(this);

        Button* imageButton = new ImageButton();
        imageButton->setSize(size4);
        imageButton->draw(this);
    }
};