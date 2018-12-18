//
// Created by justinschenk on 12/17/2018.
//

#include "Tweet.h"

const std::string Tweet::NULL_USER("@null");

Tweet::Tweet(const string &msg, const string &userName)
{
    message = msg;
    user = userName;
}

bool Tweet::operator<(const Tweet &rhs) const
{
    if(message < rhs.message)
        return true;
    if(rhs.message < message)
        return false;

    return user < rhs.user;
}

const string &Tweet::getUser() const {
    return user;
}

bool Tweet::operator==(const Tweet &rhs) const {
    return message == rhs.message &&
           user == rhs.user;
}

bool Tweet::operator!=(const Tweet &rhs) const {
    return !(rhs == *this);
}
