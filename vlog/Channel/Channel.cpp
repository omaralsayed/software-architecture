// Channel.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Channel.h"

ChannelBuilder::ChannelBuilder() {
	type = TYPES::BASIC_BUILD;
	email = "";
	password = "";
	identification_number = -1;
	credit_card = "";
}

void ChannelBuilder::SetType(TYPES channel_type) {
	this->type = channel_type;
}

void ChannelBuilder::SetEmail(std::string email) {
	this->email = email;
}

void ChannelBuilder::SetPassword(std::string password) {
	this->password = password;
}

void ChannelBuilder::SetID(int identification_number) {
	this->identification_number = identification_number;
}

void ChannelBuilder::SetCreditCardInfo(std::string credit_card_info) {
	this->credit_card = credit_card_info;
}

TYPES ChannelBuilder::GetType() {
	return this->type;
}

std::string ChannelBuilder::GetEmail() {
	return this->email;
}

std::string ChannelBuilder::GetPassword() {
	return this->password;
}

int ChannelBuilder::GetID() {
	return this->identification_number;
}

std::string ChannelBuilder::GetCreditCardInfo() {
	return this->credit_card;
}

Channel* ChannelBuilder::build() {
	if (this->type == TYPES::BASIC_BUILD) {
		if (email == "") {
			throw("You must provide an email address to continue.");
		}
		else {
			if (password == "") {
				throw("You must provide a valid password to continue.");
			}
			else {
				if (identification_number < 0) {
					throw ("You must provide a valid identification number to proceed with our Basic Plan.");
				}
			}
		}
	}
	else if (this->type == TYPES::PREMIUM_BUILD) {
		if (email == "") {
			throw("You must provide an email address to continue.");
		}
		else {
			if (password == "") {
				throw("You must provide a valid password to continue.");
			}
			else {
				if (credit_card == "") {
					throw ("You must provide a Credit Card number to proceed with our Premium Plan.");
				}
			}
		}
	}
	else {
		throw ("The requested channel tier is not available. We only offer Basic and Premium.");
	}
	return new Channel(this);
}

Channel::Channel(ChannelBuilder* c) {
	this->email = c->GetEmail();
	this->password = c->GetPassword();

	if (c->GetType() == TYPES::BASIC_BUILD) {
		this->id_number = c->GetID();
	}
	else {
		this->credit_card = c->GetCreditCardInfo();
	}
}

void Channel::addSubscriber(Subscriber* s) {
	set_subscriber.insert(s);
}

void Channel::removeSubscriber(Subscriber* s) {
	set_subscriber.erase(s);
}

void Channel::UploadNewVideo(std::string video) {
	std::cout << "Channel " + email + " uploaded a video.\n";

	for (std::set<Subscriber*>::iterator it = set_subscriber.begin(); it != set_subscriber.end(); ++it) {
		std::string subscriber_name = (*it)->getName();
		std::string message = "Hello " + subscriber_name + "! Channel " + email + " uploaded a new video. Check it out!";
		(*it)->update(message);
	}
}
