//
// Created by justinschenk on 12/17/2018.
//

#include "RetweetCollection.h"

bool RetweetCollection::isEmpty() const
{
    return 0 == size();
}

unsigned int RetweetCollection::size() const
{
    return count;
}

void RetweetCollection::add(const Tweet& tweet)
{
    tweets.insert(tweet);
    count++;
}


