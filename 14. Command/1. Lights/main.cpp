#include <iostream>
#include <memory>
#include <vector>

#include "src/Light.h"
#include "src/Controller.h"

#include "src/Command.h"
#include "src/CommandAllOff.h"
#include "src/CommandAllOn.h"

int main()
{
    auto light1 = std::make_shared<Light>(1);
    auto light2 = std::make_shared<Light>(2);
    auto light3 = std::make_shared<Light>(3);

    std::vector<std::shared_ptr<Light>> lights = { light1, light2, light3 };

    auto turnAllLightsOnCommand = std::make_unique<CommandAllOn>(lights);
    auto turnAllLightsOffCommand = std::make_unique<CommandAllOff>(lights);

    Controller remoteControl;
    remoteControl.setCommand(std::move(turnAllLightsOnCommand));
    remoteControl.pressButton();

    remoteControl.setCommand(std::move(turnAllLightsOffCommand));
    remoteControl.pressButton();

    return 0;
}
