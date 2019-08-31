#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QLabel>
#include <QFontComboBox>
#include <QSpinBox>

#pragma execution_character_set("utf-8")



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

    QLabel *fontLabel1,*fontLabel2;    //fontLabel1“字体”、“fontLabel2字号”
    QFontComboBox *fontComboBox;
    QSpinBox *sizeSpinBox;
    QToolBar *fontToolBar;   //字体工具栏

private slots:
    void on_openAction_triggered();

    void on_newAction_triggered();

    void on_bldAction_triggered(bool checked);

    void on_itlAction_triggered(bool checked);

    void on_underAction_triggered(bool checked);

    void on_fontAction_triggered();

    void on_colorAction_triggered();

    void ShowSizeSpinBox(int spinValue);
    void ShowFontComboBox(QString comboStr);

    void on_cutAction_triggered();

private:
    QString filename;
};

#endif // MAINWINDOW_H
