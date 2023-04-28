#pragma once

#include <memory>
#include "Document.h"
#include "Command.h"

class CreateDocumentCommand : public Command
{
public:
    explicit CreateDocumentCommand(std::shared_ptr<Document> document) : document(std::move(document)) {}

    void execute() override {
        document->create();
    }

private:
    std::shared_ptr<Document> document;
};