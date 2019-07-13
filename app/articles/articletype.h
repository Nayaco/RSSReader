#ifndef ARTICLETYPE_H
#define ARTICLETYPE_H

#include <QMetaType>
#include <QString>
#include <QPixmap>

typedef struct {
    QString description;
    QString title;
    QString link;
    QPixmap img;
} ArticleData;

Q_DECLARE_METATYPE(ArticleData)

#endif // ARTICLETYPE_H
