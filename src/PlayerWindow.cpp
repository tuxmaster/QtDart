#include "PlayerWindow.h"

namespace Frank {

	PlayerWindow::PlayerWindow(QWidget *parent) :
		QDialog(parent)
	{
		setupUi(this);
	}

	void PlayerWindow::changeEvent(QEvent *e)
	{
		QDialog::changeEvent(e);
		switch (e->type()) {
			case QEvent::LanguageChange:
				retranslateUi(this);
				break;
			default:
				break;
		}
	}

} // namespace Frank
