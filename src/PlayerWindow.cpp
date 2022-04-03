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
#include "PlayerWindow.h"
#include <QtWidgets>
#include "Controller.h"
#include "PlayerModel.h"

namespace Frank {
Q_LOGGING_CATEGORY(LOG_CAT_PLAYERWINDOW, LOG_CAT_PLAYERWINDOW_TEXT)
PlayerWindow::PlayerWindow(Controller* controller, QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	m_controller = controller;
	m_PlayerModel = new PlayerModel(m_controller->players(), this);
	connect(m_PlayerModel, &PlayerModel::playerAdded, this, &PlayerWindow::playerAdded);
	tvPlayer->setModel(m_PlayerModel);

	m_PlayerModel->addPlayer("Hans");
	m_PlayerModel->addPlayer("Egon");
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
	m_PlayerModel->addPlayer(leName->text());
}
void PlayerWindow::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
		return;
	QDialog::keyPressEvent(event);
}
void PlayerWindow::showEvent(QShowEvent *e)
{
	leName->clear();
	e->accept();
}
void PlayerWindow::playerAdded()
{
	tvPlayer->resizeColumnToContents(0);
	tvPlayer->horizontalHeader()->setStretchLastSection(true);
}

void PlayerWindow::on_tvPlayer_clicked(const QModelIndex &index)
{
	qCDebug(LOG_CAT_PLAYERWINDOW)<<"Selected player to remove row"<<index.row()<<"cloumn"<<index.column();
	if(index.column()==0)
	{
		qCDebug(LOG_CAT_PLAYERWINDOW)<<"Player in row"<<index.row()<<"with name"<<m_PlayerModel->data(m_PlayerModel->index(index.row(),1))<<"will removed";
	}
}
} // namespace Frank
