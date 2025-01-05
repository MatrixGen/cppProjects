#ifndef USER_AUTH_H
#define USER_AUTH_H

#include <string>

bool registerUser(const std::string& filename);
bool loginUser(const std::string& filename);

#endif // USER_AUTH_H
