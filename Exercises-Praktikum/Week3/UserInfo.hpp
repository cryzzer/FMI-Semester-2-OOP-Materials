#pragma once
#ifndef usrInfo
#define usrInfo 1

class UserInfo{
private:
	char username[200];
	char password[200];

public:
	UserInfo(const char username_[] = "Enter username:", const char pass[] = "Enter password:");
	UserInfo(const UserInfo& rhs);

	char* getUsername();
	char* getPass();
};

#endif // !usrInfo


