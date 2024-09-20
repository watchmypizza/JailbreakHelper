#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrl>
#include <QDebug>
#include <QProcess>
#include <QTimer>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), curlProcess(new QProcess(this))
{
    ui->setupUi(this);
    connect(curlProcess, &QProcess::finished, this, &MainWindow::handleCurlResponse);
}

void MainWindow::on_Disclaimer_toggled(bool checked)
{
    disclaimerChecked = checked;
    qDebug() << (checked ? "Disclaimer checked!" : "Disclaimer unchecked");
}

bool downloaded = false;

void MainWindow::on_Confirm_clicked()
{
    qDebug() << (disclaimerChecked ? "Button clicked!" : "You didn't agree");

    if (disclaimerChecked) {
        if (!downloaded) {
            qDebug() << "Starting jailbreaking process...";

            QProcess *process = new QProcess(this);
            connect(process, &QProcess::finished, this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
                if (exitStatus == QProcess::NormalExit && exitCode == 0) {
                    qDebug() << "Palera1n downloaded successfully.";
                    ui->outputConsole->setText("Downloaded palera1n.");
                    downloaded = true;
                } else {
                    qDebug() << "Palera1n download failed with exit code:" << exitCode;
                    QString errorMsg = QString("Palera1n download failed with exit code: %1").arg(exitCode);
                    ui->outputConsole->setText(errorMsg);
                }
            });

            connect(process, &QProcess::readyReadStandardOutput, [process, this]() {
                QByteArray output = process->readAllStandardOutput();
                ui->outputConsole->append(QString(output));

                if (QString(output).contains("/var/run/usbmuxd not found")) {
                    qDebug() << "Warning detected. Restarting usbmuxd...";
                    process->kill();
                    QProcess::execute("sudo systemctl restart usbmuxd");
                    startLiveOutput();
                }
            });

            connect(process, &QProcess::readyReadStandardError, [process, this]() {
                QByteArray errorOutput = process->readAllStandardError();
                ui->outputConsole->append(QString(errorOutput));
            });

            QString command = "sudo";
            QStringList arguments;
            arguments << "/bin/sh" << "-c" << "curl -fsSL https://static.palera.in/scripts/install.sh | sh";
            process->start(command, arguments);
        } else {
            startLiveOutput();
        }
    }
}

bool usbmuxdWarningDetected = false;

void MainWindow::startLiveOutput()
{
    qDebug() << "Executing live output command...";
    QProcess *liveProcess = new QProcess(this);

    connect(liveProcess, &QProcess::readyReadStandardOutput, [liveProcess, this]() {
        QByteArray output = liveProcess->readAllStandardOutput();
        ui->outputConsole->append(QString(output));

        if (QString(output).contains("Booting Kernel...")) {
            ui->outputConsole->clear();
            ui->outputConsole->append("-- JAILBREAK OUTPUT CONSOLE --");
            ui->outputConsole->append("iPhoneOS: ");
            ui->outputConsole->append("iPhone Model: ");
            ui->outputConsole->append("-- IF EMPTY THERE IS NO JAILBREAK FOUND FOR YOUR PHONE --");
            ui->outputConsole->append("Jailbreak: ");
            ui->outputConsole->append("-- THIS WILL DELETE AND DISPLAY OUTPUT ONCE STARTED --");
        } else if (QString(output).contains("Press Enter when ready for DFU mode")) {
            qDebug() << "Get ready to follow instructions...";
            ui->outputConsole->append("Get ready to follow instructions...");

            QTimer::singleShot(3000, [liveProcess]() {
                qDebug() << "Pressing Enter...";
                liveProcess->write("\n");
            });
        } else if (QString(output).contains("/var/run/usbmuxd not found") && !usbmuxdWarningDetected) {
            qDebug() << "Warning detected. Restarting usbmuxd...";
            usbmuxdWarningDetected = true;
            liveProcess->kill();
            QProcess::execute("sudo systemctl restart usbmuxd");
            startLiveOutput();
        } else if (!QString(output).contains("/var/run/usbmuxd not found")) {
            usbmuxdWarningDetected = false;
        }
    });

    connect(liveProcess, &QProcess::readyReadStandardError, [liveProcess, this]() {
        QByteArray errorOutput = liveProcess->readAllStandardError();
        ui->outputConsole->append(QString(errorOutput));
    });

    QString liveCommand = "sudo";
    QStringList liveArguments;
    liveArguments << "palera1n" << "-l";
    liveProcess->start(liveCommand, liveArguments);
}

void MainWindow::on_Check_clicked()
{
    QString iPhoneModel = ui->iPhoneModel->text();
    QString iPhoneOS = ui->iPhoneOS->text();

    QUrl url(QString("https://api.appledb.dev/compat/%1/%2.json").arg(iPhoneModel).arg(iPhoneOS));
    QString encodedUrl = url.toString(QUrl::FullyEncoded);

    QString command = QString("curl -s \"%1\"").arg(encodedUrl);
    qDebug() << "Executing command:" << command;

    curlProcess->start("/bin/bash", QStringList() << "-c" << command);
}

void MainWindow::handleCurlResponse(int exitCode, QProcess::ExitStatus exitStatus)
{
    QByteArray response = curlProcess->readAllStandardOutput();
    QByteArray errorOutput = curlProcess->readAllStandardError();

    qDebug() << "Raw response:" << response;

    if (exitStatus == QProcess::NormalExit && exitCode == 0) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        if (jsonDoc.isArray()) {
            QJsonArray jsonArray = jsonDoc.array();
            QJsonArray namesArray;

            for (int i = 0; i < qMin(jsonArray.size(), 8); ++i) {
                QJsonObject jsonObject = jsonArray[i].toObject();
                QString name = jsonObject.value("name").toString();
                namesArray.append(name);
            }

            QJsonObject resultObject;
            resultObject["jailbreaks"] = QJsonValue(namesArray);

            QJsonDocument resultDoc(resultObject);
            qDebug() << "Extracted names in JSON format:";
            qDebug().noquote() << resultDoc.toJson(QJsonDocument::Indented);
            ui->outputConsole->setText(resultDoc.toJson(QJsonDocument::Indented) + "AUTOSELECTED IS PALERA1N, INSTALL TROLLSTORE TO ADD JAILBREAKS.");
        } else {
            qDebug() << "Error: Expected an array in the JSON response, but received:";
            qDebug().noquote() << jsonDoc.toJson(QJsonDocument::Indented);
        }
    } else {
        qDebug() << "CURL process failed!";
        qDebug() << "Error output:" << errorOutput;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete curlProcess;
}
