#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFontDialog>
#include <QInputDialog>
#include <QFileDialog>

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
    void on_btn_messagebox_clicked();

    void on_btn_font_clicked();

    void on_btn_getItem_clicked();

    void on_btn_saveInfo_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
