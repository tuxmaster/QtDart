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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"
#include <QtCore>
#include <Params.h>

namespace Frank
{
class Controller;
class PlayerWindow;
Q_DECLARE_LOGGING_CATEGORY(LOG_CAT_MAINWINDOW)
class MainWindow : public QMainWindow, private Ui::MainWindow
{
		Q_OBJECT
	public:
		explicit		MainWindow(QWidget *parent = nullptr);
	protected:
		void			changeEvent(QEvent *e) override;
	private Q_SLOTS:
		void			on_pb_NewGame_clicked(bool checked);
		void			getPlayers();
		void			getLegs();
	private:
		Controller*		m_controller;
		PlayerWindow*	m_playerWindow;
};
}
#endif // MAINWINDOW_H
