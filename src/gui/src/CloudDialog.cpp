#include "CloudDialog.h"

#include "CoreInterface.h"

#include "ui_CloudDialogBase.h"

#include <QCryptographicHash>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

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
	const QString email = ui->m_pEmailLineEdit->text();
	const QString password = ui->m_pPasswordLineEdit->text();

	if (!email.isEmpty() && !password.isEmpty()) {
		CoreInterface coreInterface;
		QString credentials(email + ":" + hash(password) + "\n");
		QString result = coreInterface.loginAuth(credentials);

		// need to refactor this json parse into a class
		qDebug() << result;

		QJsonObject jsonObj;
		QJsonDocument jsonDoc = QJsonDocument::fromJson(result.toUtf8());
		if(!jsonDoc.isNull()) {
			if(jsonDoc.isObject())
			{
				jsonObj = jsonDoc.object();
			}
			else
			{
				qDebug() << "Document is not an object" << endl;
			}
		}

		bool loginResult = jsonObj["result"].toBool();
		if (loginResult) {
			ui->m_pEmailLineEdit->hide();
			ui->m_pPasswordLineEdit->hide();
			ui->m_pLoginButton->hide();
			qDebug() << "Valid login" << endl;
			// start doing the connect in the background

			// when all sucesses, show the disconnect button
		}
		else {

			qDebug() << "Invalid login" << endl;
		}

	}
}

QString CloudDialog::hash(const QString& string)
 {
	QByteArray data = string.toUtf8();
	QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Md5);
	return hash.toHex();
 }
