#ifndef RSSReader_Articles
#define RSSReader_Articles
#include <QPainter>
#include <QtDebug>
#include "articles.h"
#include "articletype.h"

Articles::Articles(QObject *parent) : QStyledItemDelegate(parent = nullptr) {

}

void Articles::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if(index.isValid()) {
        painter->save();
        QVariant var = index.data(Qt::UserRole + 1);
        ArticleData curData = var.value<ArticleData>();

        QRectF rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.rect.width() - 1);
        rect.setHeight(option.rect.height() - 1);

        QPainterPath path;
        path.moveTo(rect.topRight());
        path.lineTo(rect.topLeft());
        path.quadTo(rect.topLeft(), rect.topLeft());
        path.lineTo(rect.bottomLeft());
        path.quadTo(rect.bottomLeft(), rect.bottomLeft());
        path.lineTo(rect.bottomRight());
        path.quadTo(rect.bottomRight(), rect.bottomRight());
        path.lineTo(rect.topRight());
        path.quadTo(rect.topRight(), rect.topRight());

        if (option.state.testFlag(QStyle::State_MouseOver)) {
//            painter->setPen(QPen(QColor("#ebeced")));
//            painter->setBrush(QColor("#ebeced"));
            painter->drawPath(path);
        }
        if (option.state.testFlag(QStyle::State_Selected)) {
//            painter->setPen(QPen(QColor("#e3e3e5")));
//            painter->setBrush(QColor("#e3e3e5"));
            painter->drawPath(path);
        }

        QRectF iconRect = QRect(rect.left() + 5, rect.top() + 5, 40, 40);
        QRectF titleRect = QRect(iconRect.right() + 5, iconRect.top(), rect.width() - 10 - iconRect.width(), 20);
        QRectF descRect = QRect(titleRect.left(), titleRect.bottom() + 5, rect.width() - 10 - iconRect.width(), 20);

        painter->drawImage(iconRect, curData.img.toImage());
        painter->setPen(QPen(Qt::white));
        painter->drawText(titleRect, curData.title);

        painter->setPen(QPen(Qt::red));
        painter->drawText(descRect, curData.description);

        painter->restore();
    }
}

QSize Articles::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(index)
    return QSize(option.rect.width(), 100);
}
#endif
