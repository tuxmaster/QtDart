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
#include "MainWindow.h"
#include "Controller.h"
#include "PlayerWindow.h"
#include <QtWidgets>

namespace Frank
{
Q_LOGGING_CATEGORY(LOG_CAT_MAINWINDOW, LOG_CAT_MAINWINDOW_TEXT)
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	setupUi(this);
	this->setWindowTitle(qAppName());
	m_controller = new Controller(this);
	m_playerWindow = new PlayerWindow(m_controller, this);
	connect(m_controller, &Controller::getPlayers, this, &MainWindow::getPlayers);
	connect(m_controller, &Controller::getLegs, this, &MainWindow::getLegs);
}

void MainWindow::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
	switch (e->type())
	{
		case QEvent::LanguageChange:
			retranslateUi(this);
			break;
		default:
			break;
	}
}
void MainWindow::on_pb_NewGame_clicked(bool checked)
{
	Q_UNUSED(checked);
	qCDebug(LOG_CAT_MAINWINDOW) << "New game selected";
	m_controller->newGame();
}
void MainWindow::getPlayers()
{
	m_playerWindow->open();
}
void MainWindow::getLegs()
{
	qCDebug(LOG_CAT_MAINWINDOW)<<"Players are know, now how many legs.";
	bool ok;
	quint8 legs = QInputDialog::getInt(this, tr("How many legs?"), tr("How many legs(rounds) will you play with the %n player(s)?","",m_controller->players()->size()),
									   3,1,std::numeric_limits<quint8>::max(),1,&ok);
	if(ok)
	{
		qCDebug(LOG_CAT_MAINWINDOW)<<"Start an game for"<<m_controller->players()->size()<<"players, playing"<<legs<<"legs.";
	}
}
}
