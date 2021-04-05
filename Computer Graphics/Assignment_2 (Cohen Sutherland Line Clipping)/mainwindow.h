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
    int c=0;
private slots:
    void bit_code(int c,int d);
    int check(int c,int d);
    void dda(int x1,int y1,int x2,int y2);
    void rectangle(int x,int y,int w,int h);
    void on_pushButton_clicked();
    void mousePressEvent(QMouseEvent *ev);
    void clipping(int c,int d);
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
