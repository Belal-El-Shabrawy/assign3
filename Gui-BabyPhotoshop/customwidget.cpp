#include "customwidget.h"
#include"mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
#include <QWidget>
#include <QLabel>

CustomWidget::CustomWidget(QWidget *parent) : QLabel(parent), isSelecting(false), enableSelection(true) {}

void CustomWidget::setEnableSelection(bool enable) {
    enableSelection = enable;
    startPoint = QPoint();
    endPoint = QPoint();
    update();
}

void CustomWidget::mousePressEvent(QMouseEvent *event) {
    if (enableSelection && event->button() == Qt::LeftButton) {
        startPoint = event->pos();
        endPoint = startPoint;
        isSelecting = true;
        update();
    }
    QLabel::mousePressEvent(event);
}

void CustomWidget::mouseMoveEvent(QMouseEvent *event) {
    if (enableSelection && isSelecting) {
        endPoint = event->pos();
        update();
    }
    QLabel::mouseMoveEvent(event);
}

void CustomWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (enableSelection && event->button() == Qt::LeftButton && isSelecting) {
        endPoint = event->pos();
        isSelecting = false;
        emit startPointChanged(startPoint);
        emit endPointChanged(endPoint);
    }
    QLabel::mouseReleaseEvent(event);
}

void CustomWidget::paintEvent(QPaintEvent *event) {
    QLabel::paintEvent(event);
    if (enableSelection && isSelecting) {
        QPainter painter(this);
        painter.setPen(QPen(Qt::red, 2));
        selectionRect = QRect(startPoint, endPoint).normalized();
        painter.drawRect(selectionRect);
    }
}
