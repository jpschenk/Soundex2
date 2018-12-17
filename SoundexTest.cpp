#include "Soundex.h"
#include "gmock/gmock.h"
using ::testing::Eq;

class SoundexEncoding: public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
   ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroesToEnsure3Digits)
{
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits)
{
    ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
    ASSERT_THAT(soundex.encode("Ac"), Eq("A200"));
    ASSERT_THAT(soundex.encode("Ad"), Eq("A300"));
    ASSERT_THAT(soundex.encode("Al"), Eq("A400"));
    ASSERT_THAT(soundex.encode("Am"), Eq("A500"));
    ASSERT_THAT(soundex.encode("Ar"), Eq("A600"));
}

TEST_F(SoundexEncoding, IgnoreSpecialCharacters)
{
    ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A000"));
}
