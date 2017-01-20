#include "CloudDialog.h"
#include "ui_CloudDialogBase.h"

CloudDialog::CloudDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CloudDialog)
{
	ui->setupUi(this);
}

CloudDialog::~CloudDialog()
{
	delete ui;
}

void CloudDialog::on_m_pLoginButton_clicked()
{

}
