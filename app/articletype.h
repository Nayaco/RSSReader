#ifndef ARTICLETYPE_H
#define ARTICLETYPE_H

#include <QMetaType>
#include <QString>

typedef struct {
    QString from;
    QString image;
    QString title;
    QString description;
} ArticleData;

Q_DECLARE_METATYPE(ArticleData)

#endif // ARTICLETYPE_H
