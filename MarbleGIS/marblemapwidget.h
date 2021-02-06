#ifndef MARBLEMAPWIDGET_H
#define MARBLEMAPWIDGET_H

#include <QWidget>
#include <MarbleWidget.h>
#include <AbstractFloatItem.h>
#include <MarbleWidgetInputHandler.h>

#define RAD2DEG_COEF (180.0/M_PI)

QT_BEGIN_NAMESPACE
namespace Ui { class MarbleMapWidget; }
QT_END_NAMESPACE

class MarbleMapWidget : public Marble::MarbleWidget
{
    Q_OBJECT

public:
    MarbleMapWidget(QWidget *parent = nullptr);
    ~MarbleMapWidget() override;

private:
    void init();
    void connectObjects();

    QString convertDMS2DD(const QString& pos);
private:
    Ui::MarbleMapWidget *ui;

    qreal centerLong = 0;
    qreal centerLat  = 0;
};
#endif // MARBLEMAPWIDGET_H
