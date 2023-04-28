#pragma once

#include <memory>
#include "Document.h"
#include "Command.h"

class SaveDocumentCommand : public Command
{
public:
    explicit SaveDocumentCommand(std::shared_ptr<Document> document) : document(std::move(document)) {}

    void execute() override {
        document->save();
    }

private:
    std::shared_ptr<Document> document;
};