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
#include "PlayerModel.h"

namespace Frank {
PlayerModel::PlayerModel(const QHash<QUuid, Player*>* data, QObject *parent) : QAbstractListModel(parent)
{
	m_data = data;
}
int PlayerModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_data->size();
}
QVariant PlayerModel::data(const QModelIndex &index, int role) const
{
	Q_UNUSED(index);
	Q_UNUSED(role);
	return QVariant();
}
} // namespace Frank
