#ifndef ARTICLES_H
#define ARTICLES_H

#include <QStyledItemDelegate>

class Articles : public QStyledItemDelegate
{
public:
    Articles(QObject *parent = nullptr);

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // ARTICLES_H
