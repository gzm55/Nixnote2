/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2013 Randy Baumgarte

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
***********************************************************************************/

#include "widgetpanel.h"
#include <QVBoxLayout>
#include <QStyleOption>
#include <QStyle>
#include <QPainter>
#include <QScrollArea>


WidgetPanel::WidgetPanel(QWidget *parent) :
    QWidget(parent)
{
    vboxLayout = new QVBoxLayout();
    this->setLayout(vboxLayout);
    vboxLayout->setSpacing(10);
    vboxLayout->setSizeConstraint(QLayout::SetNoConstraint);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    this->setStyleSheet("QTreeView {background:transparent; border:none; margin:0px; padding: 0px;} ");
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
}

WidgetPanel::~WidgetPanel() {
    delete vboxLayout;
}

void WidgetPanel::addWidget(QWidget *widget) {
    vboxLayout->addWidget(widget);
}




void WidgetPanel::paintEvent(QPaintEvent *e)
 {
    //Suppress unused
    Q_UNUSED(e);
    return;
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }



QSize WidgetPanel::sizeHint() {
    return minimumSizeHint();
}
