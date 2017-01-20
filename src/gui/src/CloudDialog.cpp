#include "CloudDialog.h"
#include "ui_CloutDialogBase.h"

CloudDialog::CloudDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CloutDialog)
{
	ui->setupUi(this);
}

CloudDialog::~CloudDialog()
{
	delete ui;
}
