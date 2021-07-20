// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SUBSCRIBER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SUBSCRIBER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SUBSCRIBER_EXPORTS
#define SUBSCRIBER_API __declspec(dllexport)
#else
#define SUBSCRIBER_API __declspec(dllimport)
#endif
#pragma once
#include <iostream>
// This class is exported from the dll
class SUBSCRIBER_API Subscriber {
private:
	std::string name;
public:
	/// Constructor of Subscriber with one string parameter.
	/// 
	/// 
	/// @param account_name is the name of this subscriber
	Subscriber(std::string account_name);

	/// Return the name of this subscriber
	/// 
	///
	std::string getName();

	/// Update function for subscriber. 
	/// When a video is uploaded, it will use this function to update all subscribers.
	/// 
	/// 
	/// @param new_video is the message sent by the channel to its subscribers
	void update(std::string new_video);
};


