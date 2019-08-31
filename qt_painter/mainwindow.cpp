#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //标题
    setWindowTitle(tr("谢昕贝的画板"));

    //涂鸦
    setPalette(QPalette(Qt::white));
    draw = new myDraw;
    setCentralWidget(draw);
    createDrawToolBar();
    createPaintToolBar();
    ShowStyle();
    brushclr = Qt::yellow;
    style = Qt::SolidPattern;
    buttonclick();
    draw->setWidth(widthSpinBox->value());
    draw->setColor(Qt::black);

}
void MainWindow::createDrawToolBar()
{
    QToolBar *DrawtoolBar = addToolBar("DrawTool");

    //画笔风格
    styleLabel = new QLabel(tr("画笔风格:"));
    styleComboBox = new QComboBox;
    styleComboBox->addItem(tr("实线"),static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("短划线"),static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("点虚线"),static_cast<int>(Qt::DotLine));
    styleComboBox->addItem(tr("点虚线+短划线"),static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem(tr("短划线+点虚线"),static_cast<int>(Qt::DashDotDotLine));
    connect(styleComboBox,SIGNAL(activated(int)),this,SLOT(ShowStyle()));

    //线宽
    widthLabel = new QLabel(tr("线宽："));
    widthSpinBox = new QSpinBox;
    widthSpinBox->setValue(3);
    connect(widthSpinBox,SIGNAL(valueChanged(int)),draw,SLOT(setWidth(int)));

    DrawtoolBar->addWidget(styleLabel);
    DrawtoolBar->addWidget(styleComboBox);
    DrawtoolBar->addWidget(widthLabel);
    DrawtoolBar->addWidget(widthSpinBox);

}
void MainWindow::createPaintToolBar()
{
    //画刷风格
    brushStyleLabel =new QLabel(tr("画刷风格："));	//画刷风格选择下拉列表框
    brushStyleComboBox =new QComboBox;
    brushStyleComboBox->addItem(tr("SolidPattern"),
                                static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Dense1Pattern"),
                                static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense2Pattern"),
                                static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense3Pattern"),
                                static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense4Pattern"),
                                static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense5Pattern"),
                                static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense6Pattern"),
                                static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense7Pattern"),
                                static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr("HorPattern"),
                                static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("VerPattern"),
                                static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("CrossPattern"),
                                static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("BDiagPattern"),
                                static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("FDiagPattern"),
                                static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("DiagCrossPattern"),
                                static_cast<int>(Qt:: DiagCrossPattern));
    brushStyleComboBox->addItem(tr("LinearGradientPattern"),
                                static_cast<int>(Qt:: LinearGradientPattern));
    brushStyleComboBox->addItem(tr("ConicalGradientPattern"),
                                static_cast<int>(Qt:: ConicalGradientPattern));
    brushStyleComboBox->addItem(tr("RadialGradientPattern"),
                                static_cast<int>(Qt:: RadialGradientPattern));
    brushStyleComboBox->addItem(tr("TexturePattern"),
                                static_cast<int>(Qt::TexturePattern));
    connect(brushStyleComboBox,SIGNAL(activated(int)),this,SLOT (ShowBrush(int)));

    //画笔颜色
    colorBtn = new QToolButton;
    colorBtn->setIcon(QIcon("d:/qt/image/color.png"));
    colorBtn->setCheckable(true);
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(brushcolor()));

    //更改
    click = new QToolButton;
    click->setText("更改");
    connect(click,SIGNAL(clicked()),this,SLOT(buttonclick()));

    ui->toolBar->addWidget(brushStyleLabel);
    ui->toolBar->addWidget(brushStyleComboBox);
    ui->toolBar->addWidget(colorBtn);
    ui->toolBar->addWidget(click);

}


//清除画板
void MainWindow::on_ClearAction_triggered()
{
    draw->clear();

}
//画笔颜色
void MainWindow::on_PenColorAction_triggered()
{
    QColor color = QColorDialog::getColor(Qt::red,this);

    if(color.isValid())
    {
        draw->setColor(color);
    }
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_OpenAction_triggered()
{
    draw->openimg();
}

void MainWindow::on_SaveAction_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                        "保存图片",
                                        "/qt/image/new.jpg",
                                        "Image (*.jpg *.png *.bmp)");
    if (filename.length() > 0)
    {
        QPixmap pixmap(size());
        QPainter painter(&pixmap);
        painter.fillRect(QRect(0, 0, size().width(), size().height()), Qt::white);
        this->render((&painter));
        pixmap.copy(QRect(0,100,size().width(),size().height()-120)).save(filename);
        //菜单栏30，带图片工具栏40，不带图片工具栏30，状态栏20
    }
}

void MainWindow::on_DrawAction_triggered()
{
    draw->setDraw();
}

void MainWindow::on_RectAction_triggered()
{
    draw->setrect();
}

void MainWindow::on_EslAction_triggered()
{
    draw->setellipse();
}

void MainWindow::on_BufAction_triggered()
{
    draw->setbutt();
}
void MainWindow::ShowStyle()
{
    draw->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(),Qt::UserRole).toInt());
}
void MainWindow::brushcolor()
{
    QColor color = QColorDialog::getColor(Qt::red,this);

    if(color.isValid())
    {
        brushclr = color;
    }
}
void MainWindow::ShowBrush(int value)
{
    style = Qt::BrushStyle(brushStyleComboBox->itemData(value,Qt::UserRole).toInt());
}
void MainWindow::buttonclick()
{
    if(style == Qt::LinearGradientPattern)
    {
        QLinearGradient linearGradient(0,0,400,400);
        linearGradient.setColorAt(0.0,Qt::white);
        linearGradient.setColorAt(0.2,brushclr);
        linearGradient.setColorAt(1.0,Qt::black);
        linearGradient.setSpread(spread);
        draw->setBrush(linearGradient);
    }
    else if(style == Qt::RadialGradientPattern)
    {
        QRadialGradient radialGradient(200,200,150,150,100);
        radialGradient.setColorAt(0.0,Qt::white);
        radialGradient.setColorAt(0.2,brushclr);
        radialGradient.setColorAt(1.0,Qt::black);
        radialGradient.setSpread(spread);
        draw->setBrush(radialGradient);
    }
    else if(style == Qt::ConicalGradientPattern)
    {
        QConicalGradient conicalGradient(200,200,30);
        conicalGradient.setColorAt(0.0,Qt::white);
        conicalGradient.setColorAt(0.2,brushclr);
        conicalGradient.setColorAt(1.0,Qt::black);
        draw->setBrush(conicalGradient);
    }
    else if(style == Qt::TexturePattern)
    {
        draw->setBrush(QBrush(QPixmap("d:/qt/image/image.png")));
    }
    else
    {
        draw->setBrush(QBrush(brushclr,style));
    }
}


void MainWindow::on_NewAction_triggered()
{
    MainWindow *newMainWindow = new MainWindow;
    newMainWindow->show();
}
