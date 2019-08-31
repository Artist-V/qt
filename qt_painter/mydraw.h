#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H
#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QtGui>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QColor>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPalette>
#include <QFileDialog>
#include <QPen>
#include <QBrush>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

class myDraw : public QWidget
{
    Q_OBJECT
public:
    explicit myDraw(QWidget *parent = 0);

public:
    void paintEvent(QPaintEvent *); //窗体重绘
    void mousePressEvent(QMouseEvent *);//鼠标按下
    void mouseMoveEvent(QMouseEvent *);//鼠标移动
    void resizeEvent(QResizeEvent *);//改变窗口大小

    enum Shape{Line,Rectangle,Ellipse,Text,Pixmap};
    void clear();//清除
    void openimg();//打开

public slots:
    void setStyle(int);
    void setWidth(int);
    void setColor(QColor);
    void setBrush(QBrush);

//涂鸦
private:
    QPixmap *pix;
    QPoint startPos;
    QPoint endPos;
    int style;
    int weight;
    QColor color;
    QBrush brush;
    QColor bcolor;


//标识
private:
    int flag_open;//打开
    int flag_line;
    int flag_rect;
    int flag_ellipse;
    int flag_butt;
    int flag_left;

public :
    void setDraw();
    void setrect();
    void setellipse();
    void setbutt();


};

#endif // DRAWWIDGET_H
