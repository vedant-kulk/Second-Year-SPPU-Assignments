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

class transform{
public:
    double matrix[20][3];
    int v;

    transform operator *(transform a){
        transform b;
        for(int i=0;i<20;++i){
            for(int j=0;j<3;++j){
                b.matrix[i][j]=0;
                for(int k=0;k<3;++k){
                    b.matrix[i][j] +=matrix[i][k]*a.matrix[k][j];
                }
            }
        }
        return b;
    }

};

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
void MainWindow::mousePressEvent(QMouseEvent *ev){
    if(start){

        int p=ev->pos().x();
        int q=ev->pos().y();
        a[j]=p;
        b[j]=q;
        //c=c+1;

        if(ev->button()==Qt::RightButton)
        {
            dda(a[j-1],b[j-1],a[0],b[0]);
            start=false;
        }
        else{
            if(j>0){
                dda(a[j-1],b[j-1],a[j],b[j]);

        }
        }
        j++;
    }

}
void MainWindow::form_matrix(){
    for(int i=0;i<j;++i){
        matrix[i][0]=a[i];
        matrix[i][1]=b[i];
        matrix[i][2]=1;
    }
}

void MainWindow::translation(double tx,double ty){
    transform matrix1,matrix2,result;
    double tran_mat[3][3]={{1,0,0},
                        {0,1,0},
                        {tx,ty,1}};
    for(int i=0;i<j;++i){
        for(int j=0;j<3;++j){
            matrix1.matrix[i][j]=matrix[i][j];
        }
    }
    for(int i=0;i<j;++i){
        for(int j=0;j<3;++j){
            matrix2.matrix[i][j]=tran_mat[i][j];
        }
    }
   result = matrix1*matrix2;



    for(int i=0;i<j-1;i++){
    dda(result.matrix[i][0],result.matrix[i][1],result.matrix[i+1][0],result.matrix[i+1][1]);
}
    dda(result.matrix[j-1][0],result.matrix[j-1][1],result.matrix[0][0],result.matrix[0][1]);

  }
void MainWindow::on_pushButton_clicked()
{
    double tx=ui->textEdit->toPlainText().toInt();
    double ty=ui->textEdit_2->toPlainText().toInt();
    form_matrix();
    translation(tx,ty);
}
