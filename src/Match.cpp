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
#include "Match.h"
#include "Leg.h"
#include "Player.h"

namespace Frank {
Q_LOGGING_CATEGORY(LOG_CAT_MATCH, LOG_CAT_MATCH_TEXT)
Match::Match(QObject *parent):QObject(parent)
{
}
Match::Match(const quint8 &legs, QObject *parent):QObject(parent)
{
	for(quint8 l=0;l<legs;l++)
		m_legs->append(new Leg(this));
}
void Match::start()
{
	m_start = QDateTime::currentDateTimeUtc();
	qCDebug(LOG_CAT_MATCH)<<"stated at"<<m_start;
}
void Match::end()
{
	m_end = QDateTime::currentDateTimeUtc();
}
} // namespace Frank
