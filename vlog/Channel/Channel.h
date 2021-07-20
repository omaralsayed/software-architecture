// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CHANNEL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CHANNEL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CHANNEL_EXPORTS
#define CHANNEL_API __declspec(dllexport)
#else
#define CHANNEL_API __declspec(dllimport)
#endif

#pragma once
#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include "../Subscriber/Subscriber.h"

class CHANNEL_API Channel;
class CHANNEL_API ChannelBuilder;

enum TYPES {
	PREMIUM_BUILD, ///< A Build mode requiring valid email, password and credit card information.
	BASIC_BUILD ///< A Build mode requiring valid email, password and identification number.
};

class CHANNEL_API ChannelBuilder {
private:

	TYPES type;
	std::string email;
	std::string password;
	int identification_number;
	std::string credit_card;
public:	
	/// <summary>
	/// Default constructor of ChannelBuilder.
	/// </summary>
	ChannelBuilder();

	/// Set the type of the channel we are going to build into either <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::BASIC_BUILD</a> or <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::PREMIUM_BUILD</a>
	/// 
	/// @param channel_type is either <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::BASIC_BUILD</a> or <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::PREMIUM_BUILD</a>
	void SetType(TYPES channel_type);

	/// Set the email of the channel we are going to build.
	/// 
	/// 
	/// @param email the email string of the channel
	void SetEmail(std::string email);

	/// Set the password of the channel we are going to build.
	/// 
	/// 
	/// @param password the password string of the channel
	void SetPassword(std::string password);

	/// Set the identification number of the channel we are going to build.
	/// 
	/// If the channel's type is <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::PREMIUM_BUILD</a>, this method is not required
	/// @param identification is the integer representing ID such as Driver License or Passport.
	void SetID(int identification_number);

	/// Set the Credit Card information of the channel we are going to build.
	/// 
	/// If the channel's type is TYPES::BASIC, this method is not required
	/// @param credit_card_info is a string representing your credit card information
	void SetCreditCardInfo(std::string credit_card_info);

	/// Get the current type of the channel we are going to build.
	/// 
	/// Return value is either <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::BASIC_BUILD</a> or <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::PREMIUM_BUILD</a>
	TYPES GetType();

	/// Get the current email of the channel we are going to build in form of a string.
	/// 
	///
	std::string GetEmail();


	/// Get the current password of the channel we are going to build in form of a string.
	/// 
	///
	std::string GetPassword();


	/// Get the current identification_number of the channel we are going to build in form of an integer.
	/// 
	///
	int GetID();

	/// Get the current credit card information of the channel we are going to build in form of a string.
	/// 
	///
	std::string GetCreditCardInfo();

	/// Get the pointer of a new built channel.
	/// 
	/// Depends on channel types, some parameters are required while some are not.
	///
	/// For example, with <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::BASIC_BUILD</a>, email, password, and identification number are required but not credit card information.
	/// The other possibility is with <a href = "./_channel_8h.html#aacb79576e5cf053ee9c93cb9d665e32b">TYPES::PREMIUM_BUILD</a>. Email, password, and credit card information are required but not identification number.
	/// If there is any missing required parameter, the function will throw an exception.
	Channel* build();
};

class CHANNEL_API Channel {
private:
	std::string email;
	std::string password;
	int id_number;
	std::string credit_card;
	std::set <Subscriber*> set_subscriber;

public:
	/// Constructor of Channel.
	/// 
	/// 
	/// @param c is the ChannelBuilder holding parameter for Channel Constructor
	Channel(ChannelBuilder* c);

	/// Add the subscriber to the collection inside Channel.
	/// 
	/// 
	/// @param s is the pointer to a Subsciber. When called, the addSubscriber will add that pointer to its set
	void addSubscriber(Subscriber* s);

	/// Remove the subscriber to the collection inside Channel.
	/// 
	/// @param s is the pointer to the Subscriber we want to remove. When called, the removeSubscriber will remove that pointer from its set. If the Subscriber is not there even before the call, nothing will happen
	/// 
	void removeSubscriber(Subscriber* s);

	/// Upload the new video to the channel.
	/// 
	/// This function will call the update function from all subscribers within its set of subscribers
	void UploadNewVideo(std::string video);
};

