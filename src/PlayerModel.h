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
#ifndef FRANK_PLAYERMODEL_H
#define FRANK_PLAYERMODEL_H

#include <QtGui>
#include "Params.h"

namespace Frank {
class Player;

Q_DECLARE_LOGGING_CATEGORY(LOG_CAT_PLAYERMODEL)
class PlayerModel : public QAbstractListModel
{
		Q_OBJECT
	public:
		explicit				PlayerModel(QList<Player *> *data, QObject *parent = nullptr);
		virtual int				rowCount(const QModelIndex &parent = QModelIndex()) const override;
		virtual QVariant		data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
		void					addPlayer(const QString &name);
	private:
		QList<Player*>*			m_data;
		static QIcon			iconDelete;
};
} // namespace Frank
#endif // FRANK_PLAYERMODEL_H
