#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <QRect>
#include <QPainter>

class CustomWidget : public QLabel {
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = nullptr);

    void setEnableSelection(bool enable);

signals:
    void startPointChanged(const QPoint &point);
    void endPointChanged(const QPoint &point);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint startPoint;
    QPoint endPoint;
    QRect selectionRect;
    QPainter *painter;
    bool isSelecting;
    bool enableSelection;
};



#endif // CUSTOMWIDGET_H
