#include "stdafx.h"
#include "../file_processor.h"
#include "../dictionary.h"

BOOST_AUTO_TEST_SUITE(IsWordInDictionary_function)
    BOOST_AUTO_TEST_CASE(word_is_in_dictionary)
    {
        Dictionary dictionary = {
            {"apple", "������"}
        };

        BOOST_CHECK(IsWordInDictionary("apple", dictionary));
    }

    BOOST_AUTO_TEST_CASE(word_is_not_in_dictionary)
    {
        Dictionary dictionary = {
            {"watermelon", "�����"},
            {"strawberry", "��������"}
        };

        BOOST_CHECK(!IsWordInDictionary("banana", dictionary));
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetWordTranslationFromDictionary_function)
    BOOST_AUTO_TEST_CASE(get_some_translation)
    {
        Dictionary dictionary = {
            {"skyscraper", "��������"}
        };

        BOOST_CHECK(GetWordTranslationFromDictionary("skyscraper", dictionary) == "��������");
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(InsertTranslationIntoDictionary_function)
    BOOST_AUTO_TEST_CASE(insert_some_translation)
    {
        Dictionary dictionary = {
            {"word", "�����"}
        };

        InsertTranslationIntoDictionary("sparrow", "�������", dictionary);

        Dictionary newDictionary = {
            {"word", "�����"},
            {"sparrow", "�������"}
        };

        BOOST_CHECK(dictionary == newDictionary);
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetDictionaryFromFile_function)
    BOOST_AUTO_TEST_CASE(get_dictionary_from_empty_file)
    {
        Dictionary dictionary;
        BOOST_CHECK(dictionary == GetDictionaryFromFile("empty-file.txt"));
    }

    BOOST_AUTO_TEST_CASE(get_some_dictionary_from_file)
    {
        Dictionary dictionary = {
            {"cat", "�����"},
            {"dog", "������"},
            {"lemon", "�����"}
        };

        BOOST_CHECK(dictionary == GetDictionaryFromFile("some-dictionary-file.txt"));
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SaveDictionaryInFile_function)
    BOOST_AUTO_TEST_CASE(saving_changes_to_dictionary)
    {
        remove("dictionary-changes.txt");
        std::ofstream file("dictionary-changes.txt");

        Dictionary dictionary1 = {
            {"average", "�������"},
            {"big", "�������"},
            {"small", "���������"}
        };

        SaveDictionaryInFile(file, dictionary1);
        Dictionary dictionary2 = GetDictionaryFromFile("dictionary-changes.txt");
        BOOST_CHECK(dictionary1 == dictionary2);
    }
BOOST_AUTO_TEST_SUITE_END()
