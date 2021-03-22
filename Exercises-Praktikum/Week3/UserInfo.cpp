#include "UserInfo.hpp"
#include "HelpfulFuncs.hpp"

UserInfo::UserInfo(const char username[], const char pass[]){
	int sizeUser = myStrlen(username);
	myStrcpy(this->username, username, sizeUser);

	int sizePass = myStrlen(pass);
	myStrcpy(this->password, pass, sizePass);
}

UserInfo::UserInfo(const UserInfo& rhs) {
	int size1 = myStrlen(rhs.username);
	myStrcpy(this->username, rhs.username,size1);
	int size2 = myStrlen(rhs.password);
	myStrcpy(this->password, rhs.password, size2);
}

char* UserInfo::getUsername() {
	return this->username;
}
char* UserInfo::getPass() {
	return this->password;
}
