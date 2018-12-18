//
// Created by justinschenk on 12/18/2018.
//

#include "TweetTest.h"
#include "Tweet.h"
#include <gmock/gmock.h>

using namespace std;
using namespace ::testing;

TEST(ATweet, DefaultUserNotNullWhenNotProvided)
{
    Tweet tweet("msg");
    ASSERT_THAT(tweet.getUser(), Eq("@null"));
}

TEST(ATweet, IsEqual)
{
    Tweet tweet("message", "user");
    Tweet tweet2("message", "user");
    ASSERT_TRUE(tweet == tweet2);
}

TEST(ATweet, NotEqual)
{
    Tweet tweet("message", "user");
    Tweet tweet2("message", "test");
    ASSERT_TRUE(tweet != tweet2);
}