#include "mainwindow.h"
#include "ui_mainwindow.h"
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
        image.setPixel(int(x),int(y),qRgb(255,0,0));
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

void MainWindow::triangle(int x,int y,int r){
    int x1,y1,x2,y2,x3,y3;
    x1=x;
    y1=y-r;
    x2=int(x-(r*0.86602));                                             //This is a function to draw triangle using DDA line drawing alogorithm.
    y2=int(y+(r*0.5));
    x3=int(x+(r*0.86602));
    y3=y2=int(y+(r*0.5));
    dda(x1,y1,x2,y2);
    dda(x1,y1,x3,y3);
    dda(x2,y2,x3,y3);
}

void MainWindow::on_pushButton_clicked()
{
    int x,y,r;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();



    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL) or ui->textEdit_2->toPlainText().operator==(NULL) or ui->textEdit->toPlainText().operator==(NULL) )
        {
            ex.critical(0,"Null value","Enter values");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if( x>800 or x <0 or y>800 or y<0 or r>800 or r<0 or r<0 or y+r>800 or x+r>800 or y-r<0 or x-r<0){
            ex.critical(0,"Error ","Out of range");
            ex.setFixedSize(200,200);
            ex.exec();
        }
    else{
    circle(x,y,r);                                      //This push button is used to draw complete pattern at once
    triangle(x,y,r);
    int r_in=int(r/2);
    circle(x,y,r_in);
}
}

void MainWindow::on_pushButton_2_clicked()
{

    int x,y,r;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();     //This push button is used to draw outer circle
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL) or ui->textEdit_2->toPlainText().operator==(NULL) or ui->textEdit->toPlainText().operator==(NULL) )
        {
            ex.critical(0,"Null value","Enter values");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if( x>800 or x <0 or y>800 or y<0 or r>800 or r<0 or r<0 or y+r>800 or x+r>800 or y-r<0 or x-r<0){
            ex.critical(0,"Error ","Out of range");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else{
    circle(x,y,r);
}
}

void MainWindow::on_pushButton_3_clicked()
{
    int x,y,r;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();     //This push button is used to draw triangle
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL) or ui->textEdit_2->toPlainText().operator==(NULL) or ui->textEdit->toPlainText().operator==(NULL) )
        {
            ex.critical(0,"Null value","Enter values");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if( x>800 or x <0 or y>800 or y<0 or r>800 or r<0 or r<0 or y+r>800 or x+r>800 or y-r<0 or x-r<0 ){
            ex.critical(0,"Error ","Out of range");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else{
    triangle(x,y,r);
        }
}



void MainWindow::on_pushButton_4_clicked()
{
    int x,y,r;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();    //This push button is used to draw inner circle
    r=ui->textEdit_3->toPlainText().toInt();
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL) or ui->textEdit_2->toPlainText().operator==(NULL) or ui->textEdit->toPlainText().operator==(NULL) )
        {
            ex.critical(0,"Null value","Cannot be Empty");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if( x>800 or x <0 or y>800 or y<0 or r>800 or r<0 or y+r>800 or x+r>800 or y-r<0 or x-r<0){
            ex.critical(0,"Error ","Out of range");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else{
    int r_in=int(r/2);
    circle(x,y,r_in);
}

}



void MainWindow::on_pushButton_5_clicked()
{
    QImage image(800,800,QImage :: Format_RGB888);
    ui->label->setPixmap(QPixmap:: fromImage(image));

}
