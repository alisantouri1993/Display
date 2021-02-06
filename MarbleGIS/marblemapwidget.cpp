#include "marblemapwidget.h"
#include "ui_marblemapwidget.h"
#include <QDebug>

MarbleMapWidget::MarbleMapWidget(QWidget *parent)
    : Marble::MarbleWidget(parent)
    , ui(new Ui::MarbleMapWidget)
{
    ui->setupUi(this);
    init();
    connectObjects();
}

MarbleMapWidget::~MarbleMapWidget()
{
    delete ui;
}

void MarbleMapWidget::init()
{
    this->setProjection(Marble::Mercator);
    this->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
    this->setShowCompass(false);
    this->setShowOverviewMap(false);
    this->setShowScaleBar(false);

    for (Marble::AbstractFloatItem* floatItem : this->floatItems())
    {
        if (floatItem->nameId() == "navigation"|| floatItem->nameId() == "license")
            floatItem->hide();
    }
    this->inputHandler()->setMouseButtonPopupEnabled(Qt::RightButton , false);
    this->inputHandler()->setInertialEarthRotationEnabled(false);
}


QString MarbleMapWidget::convertDMS2DD(const QString& pos)
{
    QString remain = pos.contains("°") ? pos : pos.toLatin1();
    QStringList strList = remain.split("°"); // '\u00b0' "°"
    QString part = strList.first();
    double result = part.toDouble();

    remain = strList.last();
    strList = remain.split("'");
    part = strList.first();
    result += part.toDouble()/60;

    remain = strList.last();
    strList = remain.split("\"");
    part = strList.first();
    result += part.toDouble()/3600;

    return QString::number(result, 'f', 4);
}

void MarbleMapWidget::connectObjects()
{
    connect(this ,&MarbleMapWidget::mouseMoveGeoPosition,this,[this](const QString& Position){

        QStringList posList = Position.split(",");
        QString lblString = QString("Longitude(%1) - Latitude(%2)").arg(convertDMS2DD(posList.first())).arg(convertDMS2DD(posList.last()));
        ui->labelGeoData->setText(lblString);

        centerLong = centerLongitude();
        centerLat  = centerLatitude();

        qDebug() << "Center Long :" << centerLongitude() << "Center Lat :" << centerLatitude();
    });

//    connect(this , &MarbleMapWidget::mouseClickGeoPosition,this , [this](qreal lon, qreal lat, Marble::GeoDataCoordinates::Unit)
//    {
//        //Unit is Radian

//        double lon_degree = lon * RAD2DEG_COEF;
//        double lat_degree = lat * RAD2DEG_COEF;

//        qDebug() << lon_degree << "---" << lat_degree;
//    });
}

