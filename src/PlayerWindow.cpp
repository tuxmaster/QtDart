#include "PlayerWindow.h"
#include <QtWidgets>

namespace Frank {
Q_LOGGING_CATEGORY(LOG_CAT_PLAYERWINDOW, LOG_CAT_PLAYERWINDOW_TEXT)
PlayerWindow::PlayerWindow(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
}
void PlayerWindow::changeEvent(QEvent *e)
{
	QDialog::changeEvent(e);
	switch (e->type())
	{
		case QEvent::LanguageChange:
				retranslateUi(this);
			break;
		default:
			break;
	}
}
void PlayerWindow::on_pbAdd_clicked(bool checked)
{
	qCDebug(LOG_CAT_PLAYERWINDOW) << "add new player";
	Q_UNUSED(checked);
	if(leName->text().isEmpty())
		return;
}
void PlayerWindow::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
		return;
	QDialog::keyPressEvent(event);
}
} // namespace Frank
