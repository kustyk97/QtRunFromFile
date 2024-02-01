#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(int argc, char *argv[], QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->lineEdit->setText(QString("text"));

    if(argc >= 2)
    {
        std::cout << "Run app with arguments." << std::endl;
        std::string path = argv[1];

        std::cout << "Path " << path << std::endl;

        std::string text;
        std::ifstream file;
        file.open(path);
        std::getline(file, text);
        file.close();
        ui->lineEdit->setText(QString::fromStdString(text));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSave_clicked()
{
    std::string text = ui->lineEdit->text().toStdString();
    std::ofstream file;
    file.open("test.xd");
    file << text;
    file.close();
}

