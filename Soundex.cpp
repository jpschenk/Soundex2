//
// Created by justinschenk on 12/13/2018.
//

#include "Soundex.h"
#include <unordered_map>

    string Soundex::zeroPad(const string& word) const
    {
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + string(zerosNeeded, '0');
    }

    string Soundex::encode(const string& word) const
    {
        return zeroPad(upperFront(head(word)) + encodeDigits(tail(word)));
    }

string Soundex::head(const string &word) const
{
    return word.substr(0, 1);
}

string Soundex::tail(const string &word) const
{
    return word.substr(1);
}

string Soundex::encodeDigits(const string &word) const
{
    string encoding;

    for (auto letter : word)
    {
        if (isComplete(encoding))
        {
            break;
        }

        auto digit = encodeDigit(letter);
        if (digit != NotADigit && digit != lastDigit(encoding))
        {
            encoding += encodeDigit(letter);
        }
    }

    return encoding;
}

bool Soundex::isComplete(const string &encoding) const
{
    return encoding.length() == MaxCodeLength - 1;
}

string Soundex::encodeDigit(char letter) const
{
    const unordered_map<char, string> encoding
    {
            {'b', "1"},
            {'f', "1"},
            {'p', "1"},
            {'v', "1"},
            {'c', "2"},
            {'g', "2"},
            {'j', "2"},
            {'k', "2"},
            {'q', "2"},
            {'s', "2"},
            {'x', "2"},
            {'z', "2"},
            {'d', "3"},
            {'t', "3"},
            {'l', "4"},
            {'m', "5"},
            {'n', "5"},
            {'r', "6"}
    };

    auto it = encoding.find(lower(letter));
    return it == encoding.end() ? NotADigit : encoding.find(letter)->second;
}

string Soundex::lastDigit(const string &encoding) const
{
    if (encoding.empty())
    {
        return NotADigit;
    }
    return std::string(1, encoding.back());
}

string Soundex::upperFront(const string &word) const
{
    return std::string(1, toupper(static_cast<unsigned char>(word.front())));
}

//char Soundex::lower(char c) const
//{
//    return tolower(static_cast<unsigned char>(c));
//}



