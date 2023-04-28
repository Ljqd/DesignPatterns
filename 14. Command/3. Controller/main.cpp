#include <iostream>
#include <memory>
#include <vector>

#include "src/Device.h"
#include "src/TV.h"
#include "src/Radio.h"

#include "src/Command.h"
#include "src/CommandAllOn.h"
#include "src/CommandAllOff.h"

#include "src/Controller.h"


int main() {
    auto tv = std::make_shared<TV>();
    auto radio = std::make_shared<Radio>();

    std::vector<std::shared_ptr<Device>> devices{ tv, radio };

    auto turnOffAllDevicesCommand = std::make_unique<CommandAllOn>(devices);

    Controller remoteControl;
    remoteControl.setCommand(std::move(turnOffAllDevicesCommand));
    remoteControl.pressButton();

    return 0;
}