#ifndef SPEEDGAUGE_H
#define SPEEDGAUGE_H

#include "../../source/qcgaugewidget.h"
#include <QGraphicsDropShadowEffect>

class SpeedGauge: public QcGaugeWidget
{
public:
    SpeedGauge(QObject *parent);

    /**
     * @brief setLabel Set text of the label
     * @param text QString
     */
    void setLabel(QString text);

    /**
     * @brief setMaxValue set the max value for gauge to display
     * @param speed
     * @param step # of steps for each degree label
     */
    void setMaxValue(qreal value, qreal step);

    /**
     * @brief setMaxValue set the max value for gauge to display
     * @param speed
     */
    void setMaxValue(qreal value);

    /**
     * @brief setValue set value of the gauge
     * @param value
     */
    void setValue(qreal value);

    /**
     * @brief Configure drop shadow
     * @param blurRadius
     * @param color
     * @param offset
     */
    void setDropShadow(qreal blurRadius, QColor color, QPointF offset);
private:
    /**
     * @brief maxValue The maximum value that the gauge shows
     */
    qreal maxValue = 80;
    /**
     * @brief speedNeedle Needle in center of gauge that visually shows where gauge is at
     */
    QcNeedleItem *speedNeedle;
    /**
     * @brief valueLabel Label that displays the current value of the gauge
     */
    QcLabelItem *valueLabel;
    /**
     * @brief unitsLabel Label that displays the units of the gauge
     */
    QcLabelItem *unitsLabel;
    /**
     * @brief degreesLabels Labels of all the ticks
     */
    QcValuesItem *degreesLabels;
    /**
     * @brief degreeTicks Ticks along the outside of the gauge
     */
    QcDegreesItem *degreeTicks;
    /**
     * @brief dropShadow Drop shadow effect on entire widget
     */
    QGraphicsDropShadowEffect *dropShadow;
    /**
     * @brief positionIndicator Indicates realtime value along the circumference of the gauge
     */
    QcDynamicArcItem *positionIndicator;
};

#endif // SPEEDGAUGE_H
