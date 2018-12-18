//
// Created by justinschenk on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_TWEET_H
#define FIRSTEXAMPLE_TWEET_H


#include <iostream>
using namespace std;

class Tweet
{
public:
    const string &getUser() const;

private:
    string message;
    string user;
public:
    static const string NULL_USER;
    Tweet(const string& msg = "", const string& user = Tweet::NULL_USER);
    bool operator < (const Tweet &rhs)const;

    bool operator==(const Tweet &rhs) const;

    bool operator!=(const Tweet &rhs) const;
};


#endif //FIRSTEXAMPLE_TWEET_H
