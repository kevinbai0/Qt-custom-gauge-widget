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

    this->degreesLabels = this->addValues(70);
    this->degreesLabels->setValueRange(0,maxSpeed);
    this->degreesLabels->setFont(QFont("Nunito Sans", 12, QFont::Light));

    this->speedNeedle = this->addNeedle(60);
    this->speedNeedle->setColor(QColor(38, 38, 38));
    this->speedNeedle->setValueRange(0,maxSpeed);

    auto * temp = this->addBackground(35);
    temp->clearrColors();
    temp->addColor(1.0, Qt::white);

    this->unitsLabel = this->addLabel(20);
    this->unitsLabel->setText("km/h");
    this->unitsLabel->setFont(QFont("Nunito Sans", 16, QFont::Bold));
    this->unitsLabel->setColor(QColor(190, 190, 190));

    QcLabelItem *lab = this->addLabel(0);
    lab->setText("0");
    lab->setFont(QFont("Nunito Sans", 18, QFont::Bold));

    this->speedNeedle->setLabel(lab);

    // drop shadow
    this->dropShadow = new QGraphicsDropShadowEffect(parent);
    this->setDropShadow(25.0, QColor(0,0,0,40), QPointF(1, 2));
    this->setGraphicsEffect(dropShadow);
}

void SpeedGauge::setMaxValue(qreal speed, qreal step) {
    if (speed > 0) {
        qreal convertedSpeed = speed + floor(speed / 100);
        this->maxSpeed = convertedSpeed;
        this->speedNeedle->setValueRange(0, convertedSpeed);
        this->degreesLabels->setValueRange(0, convertedSpeed);
        this->degreesLabels->setStep(step);
        this->degreeTicks->setStep(step / 5);
    }
}

void SpeedGauge::setMaxValue(qreal speed) {
    if (speed > 0) {
        qreal convertedSpeed = speed + floor(speed / 100);
        this->maxSpeed = speed;
        this->speedNeedle->setValueRange(0, convertedSpeed);
        this->degreesLabels->setValueRange(0, convertedSpeed);

        qreal convertedSteps = round(convertedSpeed / 100) * 10;
        this->degreesLabels->setStep(convertedSteps);
        this->degreeTicks->setStep(convertedSpeed / 10);
    }
}

void SpeedGauge::setValue(qreal speed) {
    speedNeedle->setCurrentValue(ceil(speed / 100.0 * maxSpeed));
}

void SpeedGauge::setDropShadow(qreal blurRadius, QColor color, QPointF offset) {
    this->dropShadow->setBlurRadius(blurRadius);
    this->dropShadow->setColor(color);
    this->dropShadow->setOffset(offset);
}
