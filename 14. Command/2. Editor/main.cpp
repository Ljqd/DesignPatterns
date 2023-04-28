#include <iostream>

#include "src/Document.h"

#include "src/Command.h"
#include "src/CreateDocumentCommand.h"
#include "src/PrintDocumentCommand.h"
#include "src/SaveDocumentCommand.h"

#include "src/Controller.h"


void keyboardShortcut(std::unique_ptr<Command> command) {
    command->execute();
}

int main() {
    std::shared_ptr<Document> document = std::make_shared<Document>();

    auto createDocumentCommand = std::make_unique<CreateDocumentCommand>(document);
    auto saveDocumentCommand = std::make_unique<SaveDocumentCommand>(document);
    auto printDocumentCommand = std::make_unique<PrintDocumentCommand>(document);

    Controller controller = {};
    // or we can create separaet controllers, for each command (each of them are just Controller)

    controller.setCommand(std::move(createDocumentCommand));
    controller.onClick();

    controller.setCommand(std::move(saveDocumentCommand));
    controller.onClick();

    controller.setCommand(std::move(printDocumentCommand));
    controller.onClick();

    // Simulate a keyboard shortcut
    auto saveShortcutCommand = std::make_unique<SaveDocumentCommand>(document);
    keyboardShortcut(std::move(saveShortcutCommand)); // Document saved
}