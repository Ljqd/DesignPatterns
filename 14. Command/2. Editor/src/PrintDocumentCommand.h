#pragma once

#include <memory>
#include "Document.h"
#include "Command.h"

class PrintDocumentCommand : public Command
{
public:
    explicit PrintDocumentCommand(std::shared_ptr<Document> document) : document(std::move(document)) {}

    void execute() override {
        document->print();
    }

private:
    std::shared_ptr<Document> document;
};