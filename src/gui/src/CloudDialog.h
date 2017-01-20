#ifndef CLOUTDIALOGLOG_H
#define CLOUTDIALOGLOG_H

#include <QDialog>

namespace Ui {
class CloutDialog;
}

class CloudDialog : public QDialog
{
	Q_OBJECT

public:
	CloudDialog(QWidget *parent = 0);
	~CloudDialog();

private:
	Ui::CloutDialog *ui;
};

#endif // CLOUTDIALOGLOG_H
