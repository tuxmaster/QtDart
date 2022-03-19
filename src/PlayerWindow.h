#ifndef FRANK_PLAYERWINDOW_H
#define FRANK_PLAYERWINDOW_H

#include "ui_PlayerWindow.h"

namespace Frank {

	class PlayerWindow : public QDialog, private Ui::PlayerWindow
	{
			Q_OBJECT

		public:
			explicit PlayerWindow(QWidget *parent = nullptr);

		protected:
			void changeEvent(QEvent *e);
	};


} // namespace Frank
#endif // FRANK_PLAYERWINDOW_H
