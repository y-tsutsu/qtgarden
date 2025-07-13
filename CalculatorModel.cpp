#include "CalculatorModel.h"

CalculatorModel::CalculatorModel(QObject *parent) : QObject(parent)
{
}

int CalculatorModel::hight() const
{
    return m_hight;
}

void CalculatorModel::setHight(int value)
{
    if (m_hight != value)
    {
        m_hight = value;
        emit hightChanged();
        updateAreaIfNeeded();
    }
}

int CalculatorModel::width() const
{
    return m_width;
}

void CalculatorModel::setWidth(int value)
{
    if (m_width != value)
    {
        m_width = value;
        emit widthChanged();
        updateAreaIfNeeded();
    }
}

int CalculatorModel::area() const
{
    return m_area;
}

bool CalculatorModel::continuousCalculate() const
{
    return m_continuousCalculate;
}

void CalculatorModel::setContinuousCalculate(bool enabled)
{
    if (m_continuousCalculate != enabled)
    {
        m_continuousCalculate = enabled;
        emit continuousCalculateChanged();
        updateAreaIfNeeded();
    }
}

void CalculatorModel::calculateArea()
{
    int newArea = m_hight * m_width;
    if (m_area != newArea)
    {
        m_area = newArea;
        emit areaChanged();
    }
}

void CalculatorModel::updateAreaIfNeeded()
{
    if (m_continuousCalculate)
    {
        calculateArea();
    }
}
