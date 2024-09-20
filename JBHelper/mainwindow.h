#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

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
    void on_Disclaimer_toggled(bool checked);
    void on_Confirm_clicked();
    void on_Check_clicked();
    void handleCurlResponse(int exitCode, QProcess::ExitStatus exitStatus);

private:
    Ui::MainWindow *ui;
    bool disclaimerChecked;
    QProcess *curlProcess;
    void startLiveOutput();
};

#endif // MAINWINDOW_H
