#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

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
    void addItem(QListWidget * listWidget, QString jmeno);

private slots:
    void on_registr_itemClicked(QListWidgetItem *item);

    void on_btn_odstranit_clicked();

    void on_btn_prejmenovat_clicked();

    void on_registr_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_btn_pridat_clicked();

    void on_registr_itemActivated(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
