#include <gtest/gtest.h>
#include "../lib/stringprocessor.h" // Подключите заголовочный файл, содержащий MyClass

// Предположим, что StringProcessor - это имя вашего тестируемого класса
class StringProcessorTest : public ::testing::Test {
protected:
    StringProcessor myProcessor; // Экземпляр вашего тестируемого класса
};

TEST_F(StringProcessorTest, HandlesEmptyString) {
    QString result = myProcessor.removeLastOperator("");
    ASSERT_EQ(result, "");
}

TEST_F(StringProcessorTest, NoOperatorAtEnd) {
    QString result = myProcessor.removeLastOperator("123");
    ASSERT_EQ(result, "123");
}

TEST_F(StringProcessorTest, OperatorPlusAtEnd) {
    QString result = myProcessor.removeLastOperator("1+1+");
    ASSERT_EQ(result, "1+1");
}

TEST_F(StringProcessorTest, OperatorAsteriskAtEnd) {
    QString result = myProcessor.removeLastOperator("1*1*");
    ASSERT_EQ(result, "1*1");
}

TEST_F(StringProcessorTest, OperatorSlashAtEnd) {
    QString result = myProcessor.removeLastOperator("1/1/");
    ASSERT_EQ(result, "1/1");
}

TEST_F(StringProcessorTest, OperatorMinusAtEnd) {
    QString result = myProcessor.removeLastOperator("1-1-");
    ASSERT_EQ(result, "1-1");
}
