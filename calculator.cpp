//
// Created by teena on 24.02.2023.
//

#include <cmath>
#include "calculator.h"

bool findArithmeticSymbols(QString& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (i > 0 && (str[i] == "+" || str[i] == "-" || str[i] == "*" || str[i] == "/"))
            return true;
    }
    return false;
}

void Calculator::addNumber(QChar number) const
{
    if (lineEdit->text().isEmpty() || lineEdit->text() == "0" || lineEdit->text() == "ERROR")
        lineEdit->setText(number);
    else
        lineEdit->setText(lineEdit->text() + number);
}

void Calculator::addArithmeticSymbol(const QString &symbol) const
{
    QString text = lineEdit->text();
    if (text.isEmpty())
    {
        if (symbol == " - ")
            lineEdit->setText(lineEdit->text() + "-");
        else
            lineEdit->setText("0" + symbol);
        return;
    }
    if (findArithmeticSymbols(text))
    {
        text = calculate();
        if (calculate() == "ERROR")
            lineEdit->setText(calculate());
        else
            lineEdit->setText(calculate() + symbol);
        return;
    }
    if (text[text.length() - 1] == ".")
        backspace();
    lineEdit->setText(lineEdit->text() + symbol);
}

QString Calculator::calculate() const
{
    QString text = lineEdit->text();
    if (!findArithmeticSymbols(text)) return text;
    QString sFirst, sSecond;
    char symbol;
    int position = 0;
    while (text[position] != " ")
    {
        sFirst += text[position];
        ++position;
    }
    symbol = text[++position].toLatin1();
    position += 2;
    while (position < text.length())
    {
        sSecond += text[position];
        ++position;
    }
    if (sSecond.isEmpty()) return sFirst;
    double nFirst = sFirst.toDouble(), nSecond = sSecond.toDouble(), result;
    if (nFirst < (-1.7e+308) || nFirst > 1.7e+308 || nSecond < (-1.7e+308) || nSecond > 1.7e+308)
        return "ERROR";
    switch (symbol)
    {
        case '+':
            result = nFirst + nSecond;
            break;
        case '-':
            result = nFirst - nSecond;
            break;
        case '*':
            result = nFirst * nSecond;
            break;
        case '/':
            if (nSecond == 0)
                return "ERROR";
            else
                result = nFirst / nSecond;
            break;
    }
    if (result < (-1.7e+308) || result > 1.7e+308)
        return "ERROR";
    std::string strResult = std::to_string(result);
    if (result - floor(result) == 0)
        strResult = strResult.substr(0, strResult.find_last_not_of('0'));
    else
        strResult = strResult.substr(0, strResult.find_last_not_of('0') + 1);
    return QString::fromStdString(strResult);
}

void Calculator::add0() const
{
    addNumber('0');
}

void Calculator::add1() const
{
    addNumber('1');
}

void Calculator::add2() const
{
    addNumber('2');
}

void Calculator::add3() const
{
    addNumber('3');
}

void Calculator::add4() const
{
    addNumber('4');
}

void Calculator::add5() const
{
    addNumber('5');
}

void Calculator::add6() const
{
    addNumber('6');
}

void Calculator::add7() const
{
    addNumber('7');
}

void Calculator::add8() const
{
    addNumber('8');
}

void Calculator::add9() const
{
    addNumber('9');
}

void Calculator::addDot() const
{
    if (lineEdit->text() == "" || lineEdit->text() == "ERROR")
        lineEdit->setText("0.");
    else
        lineEdit->setText(lineEdit->text() + ".");
}

void Calculator::plus() const
{
    addArithmeticSymbol(" + ");
}

void Calculator::minus() const
{
    addArithmeticSymbol(" - ");
}

void Calculator::multiply() const
{
    addArithmeticSymbol(" * ");
}

void Calculator::divide() const
{
    addArithmeticSymbol(" / ");
}

void Calculator::backspace() const
{
    QString text = lineEdit->text();
    text.remove(text.length() - 1, 1);
    lineEdit->setText(text);
}

void Calculator::clearLine() const
{
    lineEdit->setText("");
}

void Calculator::getResult() const
{
    lineEdit->setText(calculate());
}