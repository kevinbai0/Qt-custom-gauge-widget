#ifndef SPEEDGAUGE_H
#define SPEEDGAUGE_H

#include "../../source/qcgaugewidget.h"
#include <QGraphicsDropShadowEffect>

class SpeedGauge: public QcGaugeWidget
{
public:
    SpeedGauge(QObject *parent);

    /**
     * @brief setMaxValue set the max value for gauge to display
     * @param speed
     * @param step # of steps for each degree label
     */
    void setMaxValue(qreal speed, qreal step);

    /**
     * @brief setMaxValue set the max value for gauge to display
     * @param speed
     */
    void setMaxValue(qreal speed);

    /**
     * @brief setValue set value of the gauge
     * @param speed
     */
    void setValue(qreal speed);

    /**
     * @brief Configure drop shadow
     * @param blurRadius
     * @param color
     * @param offset
     */
    void setDropShadow(qreal blurRadius, QColor color, QPointF offset);
private:
    qreal maxSpeed = 80;
    QcNeedleItem *speedNeedle;
    QcLabelItem *unitsLabel;
    QcValuesItem *degreesLabels;
    QcDegreesItem *degreeTicks;
    QGraphicsDropShadowEffect *dropShadow;
};

#endif // SPEEDGAUGE_H
