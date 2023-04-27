//
// Created by teena on 21.02.2023.
//

#pragma once
#include <QMainWindow>
#include <QtWidgets/QLineEdit>


class Calculator : public QMainWindow
{
    Q_OBJECT
public:
    QLineEdit* lineEdit = nullptr;

    Calculator(QWidget* parent = nullptr) : QMainWindow(parent) {};

    void addNumber(QChar number) const;

    void addArithmeticSymbol(const QString &symbol) const;

    QString calculate() const;

public slots:
    void add0() const;

    void add1() const;

    void add2() const;

    void add3() const;

    void add4() const;

    void add5() const;

    void add6() const;

    void add7() const;

    void add8() const;

    void add9() const;

    void addDot() const;

    void plus() const;

    void minus() const;

    void multiply() const;

    void divide() const;

    void backspace() const;

    void clearLine() const;

    void getResult() const;
};

bool findArithmeticSymbols(QString& str);