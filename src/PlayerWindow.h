#ifndef FRANK_PLAYERWINDOW_H
#define FRANK_PLAYERWINDOW_H

#include "ui_PlayerWindow.h"
#include <QtCore>
#include <Params.h>

namespace Frank {
Q_DECLARE_LOGGING_CATEGORY(LOG_CAT_PLAYERWINDOW)
class PlayerWindow : public QDialog, private Ui::PlayerWindow
{
		Q_OBJECT
	public:
		explicit	PlayerWindow(QWidget *parent = nullptr);
	protected:
		void		changeEvent(QEvent *e) override;
		void		keyPressEvent(QKeyEvent *e) override;
	private Q_SLOTS:
		void		on_pbAdd_clicked(bool checked);
};
} // namespace Frank
#endif // FRANK_PLAYERWINDOW_H
