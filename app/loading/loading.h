#ifndef RSSReader_Loading
#define RSSReader_Loading

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QMap>

struct Location {
public:
    explicit Location(float _x, float _y) {x = _x; y = _y;}
    float x;
    float y;
};

class Loading : public QWidget {
    Q_OBJECT
public:
    explicit Loading(QWidget* parent = nullptr);
    void setDotCount(int);
    void setDotColor(const QColor&);
    void start();
    void setMaxDiameter(float);
    void setMinDiameter(float);

private:
    int _index, _count, _i, _interval;
    QColor _dotColor;
    QTimer timer;
    float _minDiameter, _maxDiameter;
    void paintDot(QPainter&);
    float _squareWidth,  _centerDistance;
    QList<float> radiiList;
    QList<Location> locationList;

    void caculate();

protected:
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);
signals:

public slots:

private slots:
    void refresh();
};

#endif
