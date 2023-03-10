#include "keyfeaturesform.h"
#include "ui_keyfeaturesform.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSettings>
#include <QDebug>

KeyFeaturesForm::KeyFeaturesForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyFeaturesForm)
{
    ui->setupUi(this);

    ui->verticalSpacer->changeSize(10,10);
    ui->verticalSpacer_2->changeSize(10,10);
    ui->horizontalSpacer->changeSize(20,10);
    ui->horizontalSpacer_2->changeSize(20,10);

    loadData();
    checkState();

}

KeyFeaturesForm::~KeyFeaturesForm()
{
    delete ui;
}


void KeyFeaturesForm::checkState()
{
    QSettings CheckBox(QString("./CheckBox/%1.ini").arg("CheckStateFile"), QSettings::IniFormat);
    CheckBox.beginGroup("checking");
    ui->zoomInCheckBox->setChecked(CheckBox.value("checkState1").toBool());
    ui->zoomOutCheckBox->setChecked(CheckBox.value("checkState2").toBool());
    ui->leftRotateCheckBox->setChecked(CheckBox.value("checkState3").toBool());
    ui->rightRotateCheckBox->setChecked(CheckBox.value("checkState4").toBool());
    ui->brushCheckBox->setChecked(CheckBox.value("checkState5").toBool());
    ui->rectangleCheckBox->setChecked(CheckBox.value("checkState6").toBool());
    ui->triangleCheckBox->setChecked(CheckBox.value("checkState7").toBool());
    ui->ellipseCheckBox->setChecked(CheckBox.value("checkState8").toBool());
    ui->moveShapeCheckBox->setChecked(CheckBox.value("checkState9").toBool());
    ui->blendingCheckBox->setChecked(CheckBox.value("checkState10").toBool());
    ui->lengthMeasurementCheckBox->setChecked(CheckBox.value("checkState11").toBool());
    ui->angleMeasurementCheckBox->setChecked(CheckBox.value("checkState12").toBool());
    ui->brightnessCheckBox->setChecked(CheckBox.value("checkState13").toBool());
    ui->darknessCheckBox->setChecked(CheckBox.value("checkState14").toBool());
    ui->sharpenCheckBox->setChecked(CheckBox.value("checkState15").toBool());
    ui->contrastCheckBox->setChecked(CheckBox.value("checkState16").toBool());
    ui->inversionCheckBox->setChecked(CheckBox.value("checkState17").toBool());
    ui->horizontalFlipCheckBox->setChecked(CheckBox.value("checkState18").toBool());
    ui->verticalFlipCheckBox->setChecked(CheckBox.value("checkState19").toBool());
    ui->implantCheckBox->setChecked(CheckBox.value("checkState20").toBool());
    CheckBox.endGroup();
}


void KeyFeaturesForm::loadData()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "keyConnection");    // ????????????????????? ??????
    db.setDatabaseName("keyDBlist.db");                                         // DB?????? : keyDBlist
    if(db.open()) {                                                             // DB??? ??? ???
        QSqlQuery query(db);                                                    // DB??? ????????????

        /* ???????????? ???????????? 0~3????????? ?????? ????????? ??????????????????. */
        query.exec("CREATE TABLE IF NOT EXISTS KeyDB(id VARCHAR(20) Primary Key,"
                   "checking VARCHAR(20));");
        keyModel = new QSqlTableModel(this, db);
        keyModel->setTable("KeyDB");                                            // ???????????? : KeyDB
        keyModel->select();                                                     // keyModel??? ?????????
        /* ?????? tableView??? 0~1????????? ?????? ????????? ?????? */
        keyModel->setHeaderData(0, Qt::Horizontal, tr("DoctorID"));
        keyModel->setHeaderData(1, Qt::Horizontal, tr("Checking"));

        ui->tableView->setModel(keyModel);                                      // tableView??? ???????????? ?????? ????????? ?????? ????????? ???????????????.
    }
}



void KeyFeaturesForm::on_savePushButton_clicked()
{
#if 1
    QSettings CheckBox(QString("./CheckBox/%1.ini").arg("CheckStateFile"), QSettings::IniFormat);
    CheckBox.beginGroup("checking");
    CheckBox.setValue("checkState1", ui->zoomInCheckBox->isChecked());
    CheckBox.setValue("checkState2", ui->zoomOutCheckBox->isChecked());
    CheckBox.setValue("checkState3", ui->leftRotateCheckBox->isChecked());
    CheckBox.setValue("checkState4", ui->rightRotateCheckBox->isChecked());
    CheckBox.setValue("checkState5", ui->brushCheckBox->isChecked());
    CheckBox.setValue("checkState6", ui->rectangleCheckBox->isChecked());
    CheckBox.setValue("checkState7", ui->triangleCheckBox->isChecked());
    CheckBox.setValue("checkState8", ui->ellipseCheckBox->isChecked());
    CheckBox.setValue("checkState9", ui->moveShapeCheckBox->isChecked());
    CheckBox.setValue("checkState10", ui->blendingCheckBox->isChecked());
    CheckBox.setValue("checkState11", ui->lengthMeasurementCheckBox->isChecked());
    CheckBox.setValue("checkState12", ui->angleMeasurementCheckBox->isChecked());
    CheckBox.setValue("checkState13", ui->brightnessCheckBox->isChecked());
    CheckBox.setValue("checkState14", ui->darknessCheckBox->isChecked());
    CheckBox.setValue("checkState15", ui->sharpenCheckBox->isChecked());
    CheckBox.setValue("checkState16", ui->contrastCheckBox->isChecked());
    CheckBox.setValue("checkState17", ui->inversionCheckBox->isChecked());
    CheckBox.setValue("checkState18", ui->horizontalFlipCheckBox->isChecked());
    CheckBox.setValue("checkState19", ui->verticalFlipCheckBox->isChecked());
    CheckBox.setValue("checkState20", ui->implantCheckBox->isChecked());
    CheckBox.endGroup();

#else
    QString DoctorID;
    bool checking;

    checking = ui->zoomInCheckBox->isChecked();

    QSqlDatabase db = QSqlDatabase::database("keyConnection");
    if(db.isOpen() && DoctorID.length()) {                          // DB??? ??????
        QSqlQuery query(keyModel->database());
        query.prepare("INSERT INTO KeyDB VALUES(?, ?)");            // ClientDB ???????????? ????????? ????????? ???????????????.
        query.bindValue(0, DoctorID);                                   // 0???: ?????? ID
        query.bindValue(1, checking);                                   // 1???: ?????? ??????
        query.exec();                                                   // ?????? ??????

        keyModel->select();                                          // clientModel??? ?????????
    }
#endif
}




void KeyFeaturesForm::test(QString DoctorID)
{

}

