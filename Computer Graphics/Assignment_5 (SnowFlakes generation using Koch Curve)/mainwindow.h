#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool start;
    int j,k;
    float a[20],b[20];
private slots:

    void dda(int x1,int y1,int x2,int y2);
     void mousePressEvent(QMouseEvent *ev);
     void koch(int x1,int y1 ,int x2,int y2,int it);



     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
