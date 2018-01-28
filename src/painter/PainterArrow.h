/*
 * Copyright (C) 2017 Damir Porobic <https://github.com/damirporobic>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef PAINTERARROW_H
#define PAINTERARROW_H

#include "PainterLine.h"

class PainterArrow : public PainterLine
{
public:
    PainterArrow(const QPointF &pos, const QPen &attributes);
    PainterArrow(const PainterArrow& other);
    virtual QRectF boundingRect() const override;
    virtual void addPoint(const QPointF &pos, bool modifier = 0) override;
    virtual void moveTo(const QPointF &newPos) override;

private:
    int       mArrowHeadLength;
    int       mArrowHeadMid;
    int       mArrowHeadWidth;
    int       mScale;
    QPolygonF mArrow;

    virtual void updateShape() override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    bool isLineToShort() const;
    void updateArrow();
    QPolygonF createArrow() const;
    QPolygonF positionAndRotateArrow(const QPolygonF& arrowHead) const;
};

#endif // PAINTERARROW_H