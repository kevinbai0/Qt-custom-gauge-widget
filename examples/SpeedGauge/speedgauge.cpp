#include "speedgauge.h"
#include <QDebug>

SpeedGauge::SpeedGauge(QObject *parent)
{
    QcBackgroundItem *bkgItem = this->addBackground(99);
    bkgItem->clearrColors();
    bkgItem->addColor(1.0, Qt::white);

    // this->addDegrees(62)->setValueRange(0,80); // for the big ticks
    degreeTicks = this->addDegrees(90); // for small ticks
    degreeTicks->setStep(10);
    degreeTicks->setWidth(0.02);
    degreeTicks->setLength(0.05);
    degreeTicks->setColor(QColor(210, 210, 210));
    degreeTicks->setValueRange(0, 300);

    positionIndicator = this->addDynamicArc(88);
    positionIndicator->setColor(QColor(59, 255, 180));
    auto colors = {std::pair<qreal, QColor>(0.0, QColor(59, 255, 180)),
                   std::pair<qreal, QColor>(0.233, QColor(59, 255, 180)),
                   std::pair<qreal, QColor>(0.433, QColor(139, 239, 52)),
                   std::pair<qreal, QColor>(0.566, QColor(139, 239, 52)),
                   std::pair<qreal, QColor>(0.766, QColor(247, 247, 89)),
                   std::pair<qreal, QColor>(0.800, QColor(247, 247, 89)),
                   std::pair<qreal, QColor>(0.900, QColor(250, 77, 77)),
                  };
    positionIndicator->setColor(colors);
    positionIndicator->setWidth(0.1);

    this->degreesLabels = this->addValues(70);
    this->degreesLabels->setValueRange(0, maxValue);
    this->degreesLabels->setFont(QFont("Avenir Next", 14, QFont::Light));

    auto * temp = this->addBackground(35);
    temp->clearrColors();
    temp->addColor(1.0, Qt::white);

    this->unitsLabel = this->addLabel(20);
    this->unitsLabel->setText("km/h");
    this->unitsLabel->setFont(QFont("Avenir Next", 16, QFont::Bold));
    this->unitsLabel->setColor(QColor(190, 190, 190));

    this->valueLabel = this->addLabel(0);
    valueLabel->setText("0");
    valueLabel->setFont(QFont("Avenir Next", 24, QFont::Bold));

    // drop shadow
    this->dropShadow = new QGraphicsDropShadowEffect(parent);
    this->setDropShadow(25.0, QColor(0,0,0,40), QPointF(1, 2));
    this->setGraphicsEffect(dropShadow);
}

void SpeedGauge::setLabel(QString text) {
    this->unitsLabel->setText(text);
    update();
}

void SpeedGauge::setMaxValue(qreal speed, qreal step) {
    if (speed > 0) {
        qreal convertedSpeed = speed;
        this->maxValue = convertedSpeed;
        this->degreesLabels->setValueRange(0, convertedSpeed);
        this->degreesLabels->setStep(step);
        this->degreeTicks->setStep(step / 5);
    }
}

void SpeedGauge::setMaxValue(qreal value) {
    if (value > 0) {
        qreal convertedSpeed = value;
        this->maxValue = value;
        this->degreesLabels->setValueRange(0, convertedSpeed);

        qreal convertedSteps = round(convertedSpeed / 100) * 10;
        this->degreesLabels->setStep(convertedSteps);
        this->degreeTicks->setStep(convertedSpeed / 10);
    }
}

void SpeedGauge::setValue(qreal value) {
    //speedNeedle->setCurrentValue(ceil(speed / 100.0 * maxSpeed));
    valueLabel->setText(QString::number(ceil(value / 99.0 * maxValue)));
    positionIndicator->setPercentage(value / 99.0);
}

void SpeedGauge::setDropShadow(qreal blurRadius, QColor color, QPointF offset) {
    this->dropShadow->setBlurRadius(blurRadius);
    this->dropShadow->setColor(color);
    this->dropShadow->setOffset(offset);
}
