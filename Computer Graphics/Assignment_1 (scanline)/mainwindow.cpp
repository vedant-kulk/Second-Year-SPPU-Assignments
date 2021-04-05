#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
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
static int o;

void  MainWindow::dda(int x1,int y1,int x2,int y2){                //dda line drawing algorithm
    int length,i;
    float dx,dy,x,y;
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
        image.setPixel(int(x),int(y),qRgb(255,255,0));
         x+=dx;
         y+=dy;
         i=i+1;
        }
    ui->label->setPixmap(QPixmap:: fromImage(image));
}
struct cordinates{
    int x,y;
};
struct array{
    int xa;
    float m;
};
cordinates *arr;
array *d;

void MainWindow::on_pushButton_clicked()
{
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL))
        {
            ex.critical(0,"Null value","Enter the number of vertices");
            ex.setFixedSize(200,200);
            ex.exec();
        }


    int x,y,n;
    //static int i=0;

    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    n=ui->textEdit_3->toPlainText().toInt();
    if(o<n){
    if(x>799 or y>799 or x<0 or y<0 ){
        ex.critical(0,"Co-ordinates ","Out of Range (0,799)");
        ex.setFixedSize(200,200);
        ex.exec();
    }
    else{
        arr[o].x=x;
        arr[o].y=y;
        o++;
    }

    }
    else{
        ex.critical(0,"vertices","Exceding the number of vertices");
        ex.setFixedSize(200,200);
        ex.exec();
    }
    ui->textEdit->clear();
    ui->textEdit_2->clear();
}

void MainWindow::on_pushButton_2_clicked()

{
    QMessageBox ex;
     if(ui->textEdit_3->toPlainText().operator==(NULL))
        {
            ex.critical(0,"Null value","Enter the number of vertices");             //Expection handling
            ex.setFixedSize(200,200);
            ex.exec();
        }
     else if(o!=ui->textEdit_3->toPlainText().toInt()){
         ex.critical(0,"Missing values"," Enter remaining vertices");
         ex.setFixedSize(200,200);
         ex.exec();

     }
    else{
    int n;
    n=ui->textEdit_3->toPlainText().toInt();
    arr[n].x=arr[0].x;
    arr[n].y=arr[0].y;
    for (int k=0;k<n;k++){
        dda(arr[k].x,arr[k].y,arr[k+1].x,arr[k+1].y);
    }
}
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL))
        {
            ex.critical(0,"Null value","Enter the number of vertices");
            ex.setFixedSize(200,200);
            ex.exec();
        }

    else{
    int n;
    n=ui->textEdit_3->toPlainText().toInt();
    arr=new cordinates[n+1];
    //ui->textEdit_3->clear();
        }
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox ex;
        if(ui->textEdit_3->toPlainText().operator==(NULL))
        {
            ex.critical(0,"Null value","Enter the number of vertices");           //Expection handling
            ex.setFixedSize(200,200);
            ex.exec();
        }
        else if(o!=ui->textEdit_3->toPlainText().toInt()){
            ex.critical(0,"Missing values"," Enter remaining vertices");
            ex.setFixedSize(200,200);
            ex.exec();

        }
    else{
    int n,inter_x[50],i,k;
    int ymax=0;
    int ymin=799;                                                             //Scan Line algorithm
    n=ui->textEdit_3->toPlainText().toInt();
    d=new array[n+1];
    float dx,dy;

    for(int i=0;i<n;i++){
        if(arr[i].y>=ymax) ymax=arr[i].y;
        if(arr[i].y<=ymin) ymin=arr[i].y;
        dx=arr[i+1].x-arr[i].x;
        dy=arr[i+1].y-arr[i].y;
        if(dx==0)d[i].m=0;                                   //Slope is calculated for everyline and stored
        if(dy==0)d[i].m=1;
        if(dx!=0 and dy!=0)
        d[i].m=(float)dx/dy;
    }
    int cnt;
    for(int y=0;y<800;y++){
        cnt=0;
        for(i=0;i<n;i++){
            if((arr[i].y>y && arr[i+1].y<=y) || (arr[i].y<=y && arr[i+1].y>y)){      //intersection is calculated
                inter_x[cnt]=(arr[i].x+(d[i].m*(y-arr[i].y)));
                cnt++;
            }
        }
        for (k=0;k<cnt-1;k++){
            for(i=0;i<cnt-k-1;i++){
                if(inter_x[i]>inter_x[i+1]){
                    int temp=inter_x[i];                                            //Sorting of values
                    inter_x[i]=inter_x[i+1];
                    inter_x[i+1]=temp;

                }
            }
        }
        for(i=0;i<cnt-1;i+=2){
            dda(inter_x[i],y,inter_x[i+1]+1,y);                         //plotting the  points
        }

    }
}
}

void MainWindow::on_pushButton_5_clicked()
{
    QImage img(800,800,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
