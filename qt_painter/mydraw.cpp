#include "mydraw.h"
#include <QtGui>
#include <QPen>

myDraw::myDraw(QWidget *parent) : QWidget(parent)
{
    pix = new QPixmap(size());
    pix->fill(Qt::white);

    //标识
    //flag_open = 0;
    flag_line = 0 ;
    flag_rect = 0;
    flag_ellipse = 0;
    flag_butt = 0;
}
//标志
void myDraw::setDraw()
{
    flag_line = 1;
    flag_rect = 0;
    flag_ellipse = 0;
    flag_butt = 0;
}
void myDraw::setrect()
{
    flag_rect = 1;
    flag_line = 0;
    flag_ellipse = 0;
    flag_butt = 0;
}
void myDraw::setellipse()
{
    flag_ellipse = 1;
    flag_rect = 0;
    flag_line = 0;
    flag_butt = 0;
}
void myDraw::setbutt()
{
    flag_butt = 1;
    flag_rect = 0;
    flag_line = 0;
    flag_ellipse = 0;
}

//画笔
void myDraw::setStyle(int s)
{
    style = s;
}

void myDraw::setWidth(int w)
{
    weight = w;
}
void myDraw::setColor(QColor c)
{
    color = c;
}
void myDraw::setBrush(QBrush b)
{
    brush = b;
    update();
}


//重绘
void myDraw::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = *pix;
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),pixmap);

}

//鼠标按下
void myDraw::mousePressEvent(QMouseEvent *e)
{
    startPos = e->pos();

    if(flag_rect)
    {
        QPainter *painter = new QPainter;
        QPen pen;
        pen.setStyle((Qt::PenStyle)style);
        pen.setWidth(weight);
        pen.setColor(color);
        pen.setBrush(brush);

        painter->begin(pix);
        painter->setPen(pen);
        //painter->setBrush(brush);
        painter->drawRect(startPos.x(),startPos.y(),200,100);
        painter->end();

        update();
    }
    if(flag_ellipse)
    {
        QPainter *painter = new QPainter;
        QPen pen;
        pen.setStyle((Qt::PenStyle)style);
        pen.setWidth(weight);
        pen.setColor(color);

        painter->begin(pix);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawEllipse(startPos,100,80);
        painter->end();

        update();
    }
    if(flag_butt)
    {
        QPixmap pixmap;
        pixmap.load("d:/qt/image/image.png");//图片加载到画布
        QPainter painter(pix);
        painter.drawPixmap(startPos.x(),startPos.y(),pixmap.width(),pixmap.height(),pixmap);//贴画布

        update();
    }
}

//鼠标移动
void myDraw::mouseMoveEvent(QMouseEvent *e)
{
    if(flag_line)
    {
        QPainter *painter = new QPainter;
        QPen pen;
        pen.setStyle((Qt::PenStyle)style);
        pen.setWidth(weight);
        pen.setColor(color);

        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(startPos,e->pos());
        painter->end();

        startPos = e->pos();
        update();
    }
}

//窗口大小改变
void myDraw::resizeEvent(QResizeEvent *event)
{
    if(height()>pix->height()||width()>pix->width())
    {
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}

//清除
void myDraw::clear()
{
    QPixmap *clearPix =new QPixmap(size());
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();
}

//打开图片
void myDraw::openimg()
{
    QString filename=QFileDialog::getOpenFileName(this,
                                        "打开图片",
                                        "/qt/image",
       "Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
    if(!filename.isEmpty())
    {
        QPixmap pixmap;
        pixmap.load(filename);//图片加载到画布
        QPainter painter(pix);
        painter.drawPixmap(0,0,pixmap);//贴画布
        flag_open = 1;
        update();
    }
}
