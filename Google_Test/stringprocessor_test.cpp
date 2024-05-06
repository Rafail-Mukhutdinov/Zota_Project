#include <gtest/gtest.h>
#include "../lib/stringprocessor.h"

class StringProcessorTest : public ::testing::Test
{
protected:
    StringProcessor myProcessor;
};

TEST_F(StringProcessorTest, HandlesEmptyString)
{
    QString result = myProcessor.removeLastOperator("");
    ASSERT_EQ(result, "");
}

TEST_F(StringProcessorTest, NoOperatorAtEnd)
{
    QString result = myProcessor.removeLastOperator("123");
    ASSERT_EQ(result, "123");
}

TEST_F(StringProcessorTest, OperatorPlusAtEnd)
{
    QString result = myProcessor.removeLastOperator("1+1+");
    ASSERT_EQ(result, "1+1");
}

TEST_F(StringProcessorTest, OperatorAsteriskAtEnd)
{
    QString result = myProcessor.removeLastOperator("1*1*");
    ASSERT_EQ(result, "1*1");
}

TEST_F(StringProcessorTest, OperatorSlashAtEnd)
{
    QString result = myProcessor.removeLastOperator("1/1/");
    ASSERT_EQ(result, "1/1");
}

TEST_F(StringProcessorTest, OperatorMinusAtEnd)
{
    QString result = myProcessor.removeLastOperator("1-1-");
    ASSERT_EQ(result, "1-1");
}

TEST_F(StringProcessorTest, LeadingZerosAfterOperator)
{
    QString result1 = myProcessor.removeLeadingZeroAfterOperator("2+2/02");
    ASSERT_EQ(result1, "2+2/2");

    QString result2 = myProcessor.removeLeadingZeroAfterOperator("2+2/003*530");
    ASSERT_EQ(result2, "2+2/3*530");

    QString result3 = myProcessor.removeLeadingZeroAfterOperator("2+2/202");
    ASSERT_EQ(result3, "2+2/202");

    QString result4 = myProcessor.removeLeadingZeroAfterOperator("003");
    ASSERT_EQ(result4, "3");
}

// Тест на замену последнего оператора
TEST_F(StringProcessorTest, ReplaceLastOperator)
{
    EXPECT_EQ(myProcessor.replaceLastOperator("2+2-", '+'), "2+2+");
    EXPECT_EQ(myProcessor.replaceLastOperator("2+2*", '-'), "2+2-");
    EXPECT_EQ(myProcessor.replaceLastOperator("2+2/", '*'), "2+2*");
    EXPECT_EQ(myProcessor.replaceLastOperator("2+2+", '/'), "2+2/");
    EXPECT_EQ(myProcessor.replaceLastOperator("2+2", '+'), "2+2+");
    EXPECT_EQ(myProcessor.replaceLastOperator("", '-'), "-");
}

// Тест на сохранение последнего оператора, если он не является оператором
TEST_F(StringProcessorTest, KeepLastNonOperatorCharacter)
{
    EXPECT_EQ(myProcessor.replaceLastOperator("123", '+'), "123+");

}

// Тест на добавление оператора, если строка пуста
TEST_F(StringProcessorTest, AddOperatorIfEmpty)
{
    EXPECT_EQ(myProcessor.replaceLastOperator("", '+'), "+");
}

// Тест на корректную работу с пустой строкой
TEST_F(StringProcessorTest, CorrectWorkWithEmptyString)
{
    EXPECT_EQ(myProcessor.replaceLastOperator("-", '+'), "+");
}
