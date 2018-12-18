//
// Created by justinschenk on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_RETWEETCOLLECTION_H
#define FIRSTEXAMPLE_RETWEETCOLLECTION_H

#include <set>
#include "Tweet.h"
using namespace std;


class RetweetCollection
{
    unsigned int count = 0;
    set<Tweet> tweets;
public:
    bool isEmpty() const;
    unsigned int size() const;
    void add(const Tweet& tweet);

};


#endif //FIRSTEXAMPLE_RETWEETCOLLECTION_H
