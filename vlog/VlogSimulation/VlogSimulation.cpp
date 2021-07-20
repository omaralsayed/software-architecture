#include <iostream>
#include "../Channel/Channel.h"
#include "../Subscriber/Subscriber.h"

int main(void) {
    Subscriber subscriber1("John");
    Subscriber subscriber2("Jane");

    ChannelBuilder builder;
    builder.SetType(TYPES::PREMIUM_BUILD);
    builder.SetCreditCardInfo("[credCardId]");
    builder.SetEmail("[username]@domain.com");
    builder.SetPassword("[password]");

    Channel* channel = builder.build();
    channel->addSubscriber(&subscriber1);
    channel->addSubscriber(&subscriber2);
    channel->UploadNewVideo("Today's Travel Episode!");
}
