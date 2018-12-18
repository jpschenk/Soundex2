//
// Created by justinschenk on 12/17/2018.
//

#include "RetweetCollectionTest.h"
#include <gmock/gmock.h>
#include "RetweetCollection.h"
using namespace testing;

class ARetweetCollection: public testing::Test
{
public:
    RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated)
{
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated)
{
    ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded)
{
    collection.add(Tweet());
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero)
{
    ASSERT_THAT(collection.size(), Eq(0u));
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, IsNotEmptyWhenItsSizeIsNotZero)
{
    collection.add(Tweet());
    ASSERT_THAT(collection.size(), Gt(0u));
    ASSERT_FALSE(collection.isEmpty());
}

//TEST_F(ARetweetCollection, IgnoreDuplicateTweetAdded)
//{
//    Tweet tweet("msg", "@user");
//    Tweet duplicate(tweet);
//
//    collection.add(tweet);
//    collection.add(duplicate);
//
//    ASSERT_THAT(collection.size(), Eq(1u));
//}

class ARetweetCollectionWithOneTweet : public Test
{
        public:
    RetweetCollection collection;
    Tweet *tweet;

    void SetUp() override
    {
        tweet = new Tweet("msg", "@user");
        collection.add(*tweet);
    };

    void TearDown() override
    {
        delete tweet;
        tweet = nullptr;
    }

};

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmpty)
{
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeOfOne)
{
    ASSERT_THAT(collection.size(), Eq(1u));
}
