#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "fronta.h"
#include "osoba.h"
#include "zasobnik.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_pridej_clicked();

private:
    Ui::MainWindow *ui;
    Fronta * p_fronta;
    Zasobnik * p_prepazka1;
    Zasobnik * p_prepazka2;
    Zasobnik * p_prepazka3;
};
#endif // MAINWINDOW_H
