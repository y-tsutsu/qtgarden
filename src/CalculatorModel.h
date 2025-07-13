#pragma once

#include <QObject>

class CalculatorModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int hight READ hight WRITE setHight NOTIFY hightChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int area READ area NOTIFY areaChanged)
    Q_PROPERTY(bool continuousCalculate READ continuousCalculate WRITE setContinuousCalculate NOTIFY continuousCalculateChanged)

public:
    explicit CalculatorModel(QObject *parent = nullptr);

    int hight() const;
    void setHight(int value);

    int width() const;
    void setWidth(int value);

    int area() const;

    bool continuousCalculate() const;
    void setContinuousCalculate(bool enabled);

    Q_INVOKABLE void calculateArea();

signals:
    void hightChanged();
    void widthChanged();
    void areaChanged();
    void continuousCalculateChanged();

private:
    int m_hight = 0;
    int m_width = 0;
    int m_area = 0;
    bool m_continuousCalculate = false;

    void updateAreaIfNeeded();
};
