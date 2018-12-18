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
    Tweet tweet("message", "@user");
    Tweet tweet2("message", "@user");
    ASSERT_TRUE(tweet == tweet2);
}

TEST(ATweet, NotEqual)
{
    Tweet tweet("message", "@user");
    Tweet tweet2("message", "@test");
    ASSERT_TRUE(tweet != tweet2);
}

TEST(ATweet, IsLessThanWhenUserAndMessageAre)
{
    Tweet tweet("message", "@user");
    Tweet tweet2("message", "@user2");
    ASSERT_TRUE(tweet < tweet2);
}

TEST(ATweet, IsLessThan)
{
    Tweet tweet("messageA", "@user");
    Tweet tweet2("messageB", "@user");
    ASSERT_TRUE(tweet < tweet2);
}

TEST(ATweet, CanCopyConstructed)
{
    Tweet tweet("messageA", "@user");
    Tweet tweet2(tweet);
    ASSERT_TRUE(tweet == tweet2);
}

TEST(ATweet, RequireUserToStartWithAtSign)
{
    string invalidUser("notStartingWith@");
    ASSERT_THROW(Tweet tweet("msg", invalidUser), InvalidUserException);
}

TEST(ATweet, RequireUserToStartWithAtSign2)
{
    string invalidUser("notStartingWith@");
    try
    {
        Tweet tweet("msg", invalidUser);
        FAIL();
    }
    catch (const InvalidUserException& expected) {}
}