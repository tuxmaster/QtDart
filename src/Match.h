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
#ifndef FRANK_MATCH_H
#define FRANK_MATCH_H

#include <QtCore>
#include "Params.h"


namespace Frank
{
class Leg;
class Player;
class Type;

Q_DECLARE_LOGGING_CATEGORY(LOG_CAT_MATCH)
class Match: public QObject
{
		Q_OBJECT
	public:
		explicit			Match(QObject *parent = nullptr);
		explicit			Match(const quint8 &legs, QObject *parent = nullptr);
		explicit			Match(const quint8 &legs, const Type *type, QObject *parent = nullptr);
		const QDateTime&	getStart() const {return m_start; }
		const QDateTime&	getEnd() const { return m_end; }
		const Type*			getType() const { return m_type; }
	public Q_SLOTS:
		void				start();
		void				end();
	private:
		QList<Leg*>*		m_legs;
		QList<Player*>*		m_players;
		QDateTime			m_start;
		QDateTime			m_end;
		const Type*			m_type;
};
} // namespace Frank

#endif // FRANK_MATCH_H
