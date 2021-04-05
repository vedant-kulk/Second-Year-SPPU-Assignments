#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include<QMessageBox>
#include <QColorDialog>
#include<cmath>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start=true;
    j=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
QImage image(900,800,QImage :: Format_RGB888);


void  MainWindow::dda(int x1,int y1,int x2,int y2){
    int length,i;
    float dx,dy,x,y;                                         //This is function to implement dda dda drawing alorithm
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

void MainWindow::mousePressEvent(QMouseEvent *ev){
    QMessageBox ex;
    if(start){

        int p=ev->pos().x();
        int q=ev->pos().y();
        if(p>800 or q>800){                                                   //mouse event

            ex.critical(0,"Out of range","Click mouse inside the label");
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else{
        a[j]=p;
        b[j]=q;

        if(ev->button()==Qt::RightButton)
        {
            dda(a[j-1],b[j-1],a[0],b[0]);
            start=false;
        }
        else{
            if(j>0){
                dda(a[j-1],b[j-1],a[j],b[j]);
        }
            j++;
        }


    }
    }

}
void MainWindow::koch(int x1,int y1 ,int x2,int y2,int i){

    float angle=(60 * M_PI)/180;
    int x3=((2*x1)+x2)/3;
    int y3=((2*y1)+y2)/3;
    int x4=((2*x2)+x1)/3;
    int y4=((2*y2)+y1)/3;


    int x=x3 + ((x4-x3)*cos(angle)) - ((y4-y3)*sin(angle));
    int y=y3 + ((x4-x3)*sin(angle)) + ((y4-y3)*cos(angle));



    if(i>0)
    {
        koch(x1,y1,x3,y3,i-1);
        koch(x3,y3,x,y,i-1);
        koch(x,y,x4,y4,i-1);
        koch(x4,y4,x2,y2,i-1);
    }
    else
    {
        dda(x1,y1,x3,y3);
        dda(x3,y3,x,y);
        dda(x,y,x4,y4);
        dda(x4,y4,x2,y2);
    }
}
void MainWindow::on_pushButton_clicked()
{
    image.fill(0);
    int n=ui->textEdit->toPlainText().toInt();
    QMessageBox ex;
        if(ui->textEdit->toPlainText().operator==(NULL)   )
        {
            ex.critical(0,"Null value","Enter values");
            ex.setFixedSize(200,200);
            ex.exec();
            //return;
        }

        else if(n<0 or n>=7){
            ex.critical(0,"Out of range","Enter in range(0-6)");
            ex.setFixedSize(200,200);
            ex.exec();
            //return;

        }
        else{

        try {
            for(QChar ch:ui->textEdit->toPlainText())
            {
                if(!ch.isDigit() && ch!='.')
                {
                    throw ch;
                }
            }


            if(j==2){
            koch(a[0],b[0],a[1],b[1],n);
        }


        else{
            for(int i=0;i<=j-2;i++){


                koch(a[i],b[i],a[i+1],b[i+1],n);

            }
             koch(a[j-1],b[j-1],a[0],b[0],n);

        }
        }
        catch(...)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Enter a Integer");
            messageBox.setFixedSize(200,200);
            return;
        }
        }



}

void MainWindow::on_pushButton_2_clicked()
{
    image.fill(0);
    j=0;
    start=true;
    ui->label->setPixmap(QPixmap:: fromImage(image));
    ui->label->show();

}
