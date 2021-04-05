#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>
#include<QtWidgets>
#include <QThread>
#include<QDialog>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QImage image(800,800,QImage :: Format_RGB888);


void  MainWindow::dda(int x1,int y1,int x2,int y2){
    int length,i;
    float dx,dy,x,y;                                         //This is function to implement dda line drawing alorithm
    if(abs(x2-x1)>=abs(y2-y1))
        length=abs(x2-x1);
    else
        length=abs(y2-y1);
    dx=(x2-x1)/float(length);
    dy=(y2-y1)/float(length);
    x=x1+0.5;
    y=y1+0.5;
    i=0;
    while(i<=length)
       {
        image.setPixel(int(x),int(y),qRgb(220,20,60));
         x+=dx;
         y+=dy;
         i=i+1;
        }
    ui->label->setPixmap(QPixmap:: fromImage(image));
}
void disp(int x1,int y1,int x,int y){

    image.setPixel(x1+x,y1+y,qRgb(255,255,0));
    image.setPixel(x1+x,y-y1,qRgb(255,255,0));
    image.setPixel(x-x1,y1+y,qRgb(255,255,0));            // This is a function to use 8 sided symmetry ro draw circle
    image.setPixel(x-x1,y-y1,qRgb(255,255,0));
    image.setPixel(x+y1,y+x1,qRgb(255,255,0));
    image.setPixel(x+y1,y-x1,qRgb(255,255,0));
    image.setPixel(x-y1,y+x1,qRgb(255,255,0));
    image.setPixel(x-y1,y-x1,qRgb(255,255,0));

}

void MainWindow::circle(int x, int y, int rad){
    float s;
    int x1,y1;
    x1=0;
    y1=rad;
    s=3-2*rad;
    while(x1<=y1){
        if(s<0){
            s+=(4*x1)+6;
        }                                                            //This is a function to implement breshman circle drawing algorithm
        else{
            s+=4*(x1-y1)+10;
            y1--;
        }
        x1++;
        disp(x1,y1,x,y);
    }

    ui->label->setPixmap(QPixmap:: fromImage(image));

}
void MainWindow::rectangle(int x,int y,int w,int h){
    dda(x,y,x+w,y);
    dda(x,y,x,y+h);
    dda(x+w,y,x+w,y+h);                                        //This is a function to draw rectangle
    dda(x,y+h,x+w,y+h);
}
void MainWindow::rhombus(int x,int y,int w,int h){
    int a=(2*x+w)/2;
    int b=(2*y+h)/2;
    dda(a,y,x,b);                                             //This is a function to draw rhombus
    dda(x,b,a,y+h);
    dda(a,y+h,x+w,b);
    dda(x+w,b,a,y);

}
void MainWindow::on_pushButton_clicked()
{
    int x,y,w,h;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();                 //Pushbutton to draw rectangle
    w=ui->textEdit_3->toPlainText().toInt();
    h=ui->textEdit_4->toPlainText().toInt();
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL) or ui->textEdit_2->toPlainText().operator==(NULL) or ui->textEdit->toPlainText().operator==(NULL) or ui->textEdit_4->toPlainText().operator==(NULL) )
        {
            ex.critical(0,"Null value","Enter values");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if(x>800 or x<0 or y>800 or y<0 or x+w>800 or w<0 or y+h>800 or y<0 ){
            ex.critical(0,"Error ","Out of range(0,800)");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else{
    rectangle(x,y,w,h);
}
}

void MainWindow::on_pushButton_2_clicked()
{
    int x,y,w,h;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();             //Pushbutton to draw rhombus
    w=ui->textEdit_3->toPlainText().toInt();
    h=ui->textEdit_4->toPlainText().toInt();
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL) or ui->textEdit_2->toPlainText().operator==(NULL) or ui->textEdit->toPlainText().operator==(NULL) or ui->textEdit_4->toPlainText().operator==(NULL) )
        {
            ex.critical(0,"Null value","Enter values");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if(x>800 or x<0 or y>800 or y<0 or x+w>800 or w<0 or y+h>800 or y<0 ){
            ex.critical(0,"Error ","Out of range(0,800)");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else{
    rhombus(x,y,w,h);
}
}

void MainWindow::on_pushButton_3_clicked()
{
    int x,y,w,h;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    w=ui->textEdit_3->toPlainText().toInt();            //Pushbutton to draw circle
    h=ui->textEdit_4->toPlainText().toInt();
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL) or ui->textEdit_2->toPlainText().operator==(NULL) or ui->textEdit->toPlainText().operator==(NULL) or ui->textEdit_4->toPlainText().operator==(NULL) )
        {
            ex.critical(0,"Null value","Enter values");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if(x>800 or x<0 or y>800 or y<0 or x+w>800 or w<0 or y+h>800 or y<0 ){
            ex.critical(0,"Error ","Out of range(0,800)");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else{
    int x_c,y_c,r_c;
    x_c=x+(w/2);
    y_c=y+(h/2);
    r_c=((h*w))/(2*pow((pow(h,2)+pow(w,2)),0.5));
    circle(x_c,y_c,r_c);
}

}

void MainWindow::on_pushButton_4_clicked()
{
    int x,y,w,h;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    w=ui->textEdit_3->toPlainText().toInt();
    h=ui->textEdit_4->toPlainText().toInt();       //Pushbutton  to draw whole figure at once
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL) or ui->textEdit_2->toPlainText().operator==(NULL) or ui->textEdit->toPlainText().operator==(NULL) or ui->textEdit_4->toPlainText().operator==(NULL) )
        {
            ex.critical(0,"Null value","Cannot be Empty");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if(x>800 or x<0 or y>800 or y<0 or x+w>800 or w<0 or y+h>800 or y<0 ){
            ex.critical(0,"Error ","Out of range(0,800)");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else{
    int x_c,y_c,r_c;
    x_c=x+(w/2);
    y_c=y+(h/2);
    r_c=((h*w))/(2*pow((pow(h,2)+pow(w,2)),0.5));
    rectangle(x,y,w,h);
    rhombus(x,y,w,h);
    circle(x_c,y_c,r_c);

}
}

void MainWindow::on_pushButton_5_clicked()
{
    QImage image(800,800,QImage :: Format_RGB888);
    ui->label->setPixmap(QPixmap:: fromImage(image));
}
