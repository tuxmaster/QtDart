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
#include <QtWidgets>
#include "PlayerModel.h"
#include "Player.h"

namespace Frank {
Q_LOGGING_CATEGORY(LOG_CAT_PLAYERMODEL, LOG_CAT_PLAYERMODEL_TEXT)
PlayerModel::PlayerModel(QList<Player*>* data, QObject *parent) : QAbstractListModel(parent)
{
	if(PlayerModel::iconDelete.isNull())
		PlayerModel::iconDelete = qApp->style()->standardIcon(QStyle::SP_TrashIcon);
	m_data = data;
}
int PlayerModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	qCDebug(LOG_CAT_PLAYERMODEL) << m_data->size() << "players in the model";
	return m_data->size();
}
QVariant PlayerModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();
	switch (role)
	{
		case Qt::DisplayRole:
			qCDebug(LOG_CAT_PLAYERMODEL) << "displayRole for player" <<index.row();
			return m_data->at(index.row())->getName();
		case Qt::DecorationRole:
			qCDebug(LOG_CAT_PLAYERMODEL) << "decorationRole for player" <<index.row();
			return QIcon::fromTheme("edit-delete", PlayerModel::iconDelete);
		default:
			return QVariant();
	}
}
void PlayerModel::addPlayer(const QString &name)
{
	qCDebug(LOG_CAT_PLAYERMODEL)<<"try to add player"<<name;
	bool playerExits = false;

	for(Player *p:*m_data)
	{
		if(name == p->getName())
		{
			qCDebug(LOG_CAT_PLAYERMODEL)<<"Player"<<name<<"alrady exists, add will ignored.";
			playerExits=true;
			break;
		}
	}
	if(!playerExits)
	{
		qCDebug(LOG_CAT_PLAYERMODEL)<<"Add player"<<name;
		beginInsertRows(index(m_data->size()),m_data->size()+1, m_data->size() +1);
		m_data->append(new Player(name, this));
		endInsertRows();
	}
}
QIcon PlayerModel::iconDelete = QIcon();
} // namespace Frank
