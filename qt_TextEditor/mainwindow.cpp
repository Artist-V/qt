#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗口标题
    setWindowTitle(tr("文本编辑器"));

    //字体工具条
    fontToolBar =addToolBar("Font");

    //在工具栏上嵌入控件
    //设置字体
    fontLabel1 =new QLabel(tr("字体:"));
    fontComboBox =new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontLabel2 =new QLabel(tr("字号:"));
    sizeSpinBox =new QSpinBox;
    fontToolBar->addWidget(fontLabel1);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontLabel2);
    fontToolBar->addWidget(sizeSpinBox);

    //关联信号和槽函数
    connect(fontComboBox,SIGNAL(activated(QString)),this,SLOT(ShowFontComboBox(QString)));
    connect(sizeSpinBox,SIGNAL(valueChanged(int)),this,SLOT(ShowSizeSpinBox(int)));

    //状态栏信息
    statusBar()->showMessage(tr("状态栏(= W =)"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newAction_triggered()
{
    MainWindow *newWin=new MainWindow;
    newWin->show();
}

void MainWindow::on_openAction_triggered()
{
    filename=QFileDialog::getOpenFileName(this,
                                "打开文件",
                                "/qt",
                                "C++ file(*.cpp);;head file(*.h);;text file(*.txt)");
    if(!filename.isEmpty())
    {
        QFile aFile(filename);  //以文件方式读出
        if (aFile.open(QIODevice::ReadWrite | QIODevice::Text))//读写、文本方式
        {
            QTextStream aStream(&aFile); //用文本流读取文件
            while (!aStream.atEnd())
            ui->textEdit->append(aStream.readLine()); //读取一个文本行
        }
        aFile.close();
    }
}



void MainWindow::on_bldAction_triggered(bool checked)
{
    QTextCharFormat fmt;

    fmt=ui->textEdit->currentCharFormat();
    if(checked)
    {
       fmt.setFontWeight(QFont::Bold);
    }
    else
    {
       fmt.setFontWeight(QFont::Normal);
    }
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_itlAction_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_underAction_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_fontAction_triggered()
{
    bool ok;
    QFont f=QFontDialog::getFont(&ok);
    if(ok)
    {
        ui->textEdit->setFont(f);
    }
}

void MainWindow::on_colorAction_triggered()
{
    QColor color=QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        ui->textEdit->mergeCurrentCharFormat(fmt);
    }

}
void MainWindow::ShowFontComboBox(QString comboStr)//设置字体
{
    QTextCharFormat fmt; //创建一个QTextCharFormat对象
    fmt.setFontFamily(comboStr); //选择的字体名称设置给QTextCharFormat对象
    ui->textEdit->mergeCurrentCharFormat(fmt);  //将新的格式应用到光标选区内的字符
}

void MainWindow::ShowSizeSpinBox(int spinValue)//设置字号
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue);
    ui->textEdit->mergeCurrentCharFormat(fmt);
 }

