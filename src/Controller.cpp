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
#include "Controller.h"
#include "Player.h"
#include "Match.h"

namespace Frank {
Q_LOGGING_CATEGORY(LOG_CAT_CONTROLLER, LOG_CAT_CONTROLLER_TEXT)
Controller::Controller(QObject *parent) : QObject(parent)
{
	m_players = new QList<Player*>;
	m_matches = new QList<Match*>;
}
Controller::~Controller()
{
	for(Player* p:*m_players)
		p->deleteLater();
	for(Match* m:*m_matches)
		m->deleteLater();
	delete m_players;
	delete m_matches;
}
void Controller::newGame()
{
	Q_EMIT(getPlayers());
}
void Controller::newLegs()
{
	if(!m_players->isEmpty())
	{
		qCDebug(LOG_CAT_CONTROLLER)<<"Player list are not empty, so we can get the legs";
		Q_EMIT(getLegs());
	}
	else
		qCDebug(LOG_CAT_CONTROLLER)<<"Player list is empty, stopping here";
}
void Controller::newMatch()
{
	m_matches->append(new Match(this));
	m_matches->last()->start();
}
Match* Controller::currentMatch()
{
	if(m_matches->last()->getEnd().isValid())
	{
		qCDebug(LOG_CAT_CONTROLLER)<<"The last match was endet, returnung nullptr";
		return nullptr;
	}
	return m_matches->last();
}
} // namespace Frank
