#include "src/AbstractUser.h"
#include "src/AbstractChat.h"
#include "src/AbstractChatMediator.h"
#include "src/AbstractChatParticipant.h"

#include "src/Chat.h"
#include "src/User.h"
#include "src/ChatMediator.h"
#include "src/ChatParticipant.h"


int main() {
    std::shared_ptr<User> creator = std::make_shared<User>(1, "ChatCreator");

    Chat chat = { 1, creator  };

    std::shared_ptr<User> user1 = std::make_shared<User>(2, "Alice");
    std::shared_ptr<User> user2 = std::make_shared<User>(3, "Bob");
    std::shared_ptr<User> user3 = std::make_shared<User>(4, "Charlie");

    // Users - is just records in some database
    // only chatParticipant-s can send messages to each other


    // Mediator - our entry point, if we want to interact with the chat and its users - only through it
    // Assume, we use it in some UI
    std::shared_ptr<AbstractChatMediator> mediator = chat.getEntryPoint();

    mediator->addUser(user1);
    mediator->addUser(user2);
    mediator->addUser(user3);

    mediator->assign(4, Privilege::MODERATOR);

    mediator->sendMessage(2, "Hello everybody!");
    mediator->sendMessage(3, "Hi, Alice!");
    mediator->sendMessage(4, "Hi!");

    mediator->sendMessageTo(3, 4, "Pssss... Dude, I have something to say...");

    mediator->notifyEmpowered("ALARM!!! WAKE UP!!!");

    return 0;
}
