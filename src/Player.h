/*
	Copyright (C) 2019 Frank Büttner tuxmaster@users.noreply.github.com

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
#ifndef PLAYER_H
#define PLAYER_H

#include <QtCore>
#include <QtQml/qqmlregistration.h>

class Player : public QObject
{
		Q_OBJECT
		Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
		Q_PROPERTY(QUuid id READ getId WRITE setId NOTIFY idChanged)
		QML_ELEMENT
	public:
		explicit		Player(QObject *parent = nullptr);
		explicit		Player(const QString &name, QObject *parent = nullptr);
		explicit		Player(const QString &name, const QUuid &id, QObject *parent = nullptr);
		void			setName(const QString &name);
		void			setId(const QUuid &id);
		const QString&	getName() const { return m_name;}
		const QUuid&	getId() const { return m_id;}

	Q_SIGNALS:
		void			nameChanged(const QString&);
		void			idChanged(const QUuid&);

	private:
		QUuid			m_id;
		QString			m_name;

};

#endif // PLAYER_H
