#ifndef CLOUDDIALOGLOG_H
#define CLOUDDIALOGLOG_H

#include <QDialog>

namespace Ui {
class CloudDialog;
}

class CloudDialog : public QDialog
{
	Q_OBJECT

public:
	CloudDialog(QWidget *parent = 0);
	~CloudDialog();

private slots:
	void on_m_pLoginButton_clicked();

private:
	Ui::CloudDialog *ui;
};

#endif // CLOUDDIALOGLOG_H
