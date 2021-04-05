#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QMessageBox>
#include "QMouseEvent"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start=true;
    j=0;
    k=0;
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
void MainWindow::rectangle(int x,int y,int w,int h){
    dda(x,y,x+w,y);
    dda(x,y,x,y+h);
    dda(x+w,y,x+w,y+h);                                        //This is a function to draw rectangle
    dda(x,y+h,x+w,y+h);
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

struct line{
    //int x,y;
    int code[4];
};
line l[20];
void MainWindow::mousePressEvent(QMouseEvent *ev){
    if(start){

        int p=ev->pos().x();
        int q=ev->pos().y();
        a[j]=p;
        b[j]=q;
        c=c+1;

        if(ev->button()==Qt::RightButton)
        {
            start=false;
        }
        else{
            if(c==2){
                dda(a[j-1],b[j-1],a[j],b[j]);
                c=0;
}
        }
        j++;
    }

}
void MainWindow::bit_code(int c,int d){
    int x,y,w,h,x_min,y_min,x_max,y_max;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    w=ui->textEdit_3->toPlainText().toInt();
    h=ui->textEdit_4->toPlainText().toInt();
    x_min=x;
    y_min=y;
    x_max=x+w;
    y_max=y+h;
    if(c<x_min){
        l[k].code[3]=1;
    }
    else{
        l[k].code[3]=0;
        }

    if(c>x_max){
        l[k].code[2]=1;
    }
    else{
        l[k].code[2]=0;
        }
    if(d<y_min){
        l[k].code[0]=1;
    }
    else{
        l[k].code[0]=0;
        }
    if(d>y_max){
        l[k].code[1]=1;
    }
    else{
        l[k].code[1]=0;
    }
    k=k+1;

}
int MainWindow::check(int c,int d){
    int j, temp;
    line ltemp;
    temp=0;
    for(j=0;j<4;j++){
        if(l[c].code[j]==l[d].code[j]){
            if(l[c].code[j]==0)
                temp++;
        }

    }
    if(temp==4)
            return 0;
    else{
        for(j=0;j<4;j++){
            if(l[c].code[j]==l[d].code[j] && l[c].code[j]==1 && l[d].code[j]==1){
                ltemp.code[j]=1;
            }
            else{
                 ltemp.code[j]=0;
            }
        }
        temp=0;
        for(j=0;j<4;j++){
            if(ltemp.code[j]==0){
                temp++;
            }
        }


    }
    if(temp<4){
        return 1;
    }
    else{
        return 2;
    }


}
void MainWindow::clipping(int c,int d){
    int u,xx,yy;
    u=check(0,1);
    switch(u){
    case 0:
        dda(a[0],b[0],a[1],b[1]);

    case 1:
        return;

    case 2:


}








void MainWindow::on_pushButton_2_clicked()
{
   //QImage image(800,800,QImage :: Format_RGB888);
   //ui->label->clear();
   image.fill(0);
   int x,y,w,h;
   x=ui->textEdit->toPlainText().toInt();
   y=ui->textEdit_2->toPlainText().toInt();
   w=ui->textEdit_3->toPlainText().toInt();
   h=ui->textEdit_4->toPlainText().toInt();
   rectangle(x,y,w,h);
   bit_code(a[0],b[0]);
   bit_code(a[1],b[1]);
   clipping(0,1);


}
