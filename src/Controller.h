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
#ifndef FRANK_CONTROLLER_H
#define FRANK_CONTROLLER_H

#include <QtCore>
#include <Params.h>

namespace Frank {
class Player;
class Match;
Q_DECLARE_LOGGING_CATEGORY(LOG_CAT_CONTROLLER)
class Controller : public QObject
{
		Q_OBJECT
	public:
		explicit				Controller(QObject *parent = nullptr);
								~Controller();
		QList<Player*>*			players() { return m_players; }
		void					newMatch();
		Match*					currentMatch();
	public Q_SLOTS:
		void					newGame();
		void					newLegs();
	Q_SIGNALS:
		void					getPlayers();
		void					getLegs();
	private:
		QList<Player*>*			m_players;
		QList<Match*>*			m_matches;
};
} // namespace Frank

#endif // FRANK_CONTROLLER_H
