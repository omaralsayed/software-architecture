// Subscriber.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Subscriber.h"

void Subscriber::update(std::string video) {
	std::cout << video << "\n";
}

Subscriber::Subscriber(std::string account_name) {
	name = account_name;
}

std::string Subscriber::getName() {
	return name;
}
