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
#ifndef LEG_H
#define LEG_H

#include <QtCore>
namespace Frank
{
class Leg : public QObject
{
		Q_OBJECT
	public:
		explicit		Leg(QObject *parent = nullptr);
		explicit		Leg(const QUuid id, QObject *parent = nullptr);
		void			setId(const QUuid id);
		const QUuid&	getId() const { return m_id;}
	public Q_SLOTS:
		void			start();
		void			end();
	private:
		QUuid			m_id;
		QDateTime		m_start;
		QDateTime		m_end;
};
}
#endif // LEG_H
