#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QMainWindow>

#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QColorDialog>
#include <QPainter>
#include <QMouseEvent>
#include <QGridLayout>
#include <QToolButton>
#include <QToolButton>

#include "mydraw.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

public:
    void createDrawToolBar();//涂鸦工具栏
    void createPaintToolBar();//画图形工具栏

private:
    myDraw *draw;
    //画笔
    QLabel *styleLabel;
    QComboBox *styleComboBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    //画刷
    QLabel *brushColorLabel;
    QFrame *brushColorFrame;
    QLabel *brushStyleLabel,*spreadLabel;
    QComboBox *brushStyleComboBox,*spreadComboBox;
    QGradient::Spread spread;
    QToolButton *colorBtn;
    QColor brushclr;
    Qt::BrushStyle style;
    QToolButton *click;


public slots:
    void ShowStyle(); //画笔类型
    void on_PenColorAction_triggered();//画笔颜色
    void on_ClearAction_triggered();//清除
    void ShowBrush(int value); //画刷风格
    void brushcolor();
    void buttonclick();

private slots:
    void on_OpenAction_triggered();
    void on_SaveAction_triggered();
    void on_DrawAction_triggered();
    void on_RectAction_triggered();
    void on_EslAction_triggered();
    void on_BufAction_triggered();
    void on_NewAction_triggered();
};

#endif // MAINWINDOW_H
