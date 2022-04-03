/*
	Copyright (C) 2022 Frank Büttner tuxmaster@users.noreply.github.com

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#ifndef FRANK_PLAYERWINDOW_H
#define FRANK_PLAYERWINDOW_H

#include "ui_PlayerWindow.h"
#include <QtCore>
#include <Params.h>

namespace Frank {
Q_DECLARE_LOGGING_CATEGORY(LOG_CAT_PLAYERWINDOW)
class Controller;
class PlayerModel;
class PlayerWindow : public QDialog, private Ui::PlayerWindow
{
		Q_OBJECT
	public:
		explicit		PlayerWindow(Controller* controller, QWidget *parent = nullptr);
	protected:
		void			changeEvent(QEvent* e) override;
		void			keyPressEvent(QKeyEvent* e) override;
		void			showEvent(QShowEvent* e) override;
	private Q_SLOTS:
		void			on_pbAdd_clicked(bool checked);
		void			on_tvPlayer_clicked(const QModelIndex &index);
		void			playerAdded();
	private:
		PlayerModel*	m_PlayerModel;
		Controller*		m_controller;
};
} // namespace Frank
#endif // FRANK_PLAYERWINDOW_H
