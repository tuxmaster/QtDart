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
#include "Player.h"
namespace Frank
{
Player::Player(QObject *parent) : QObject(parent)
{
	this->setName(QString());
	this->setId(QUuid());
}
Player::Player(const QString &name,QObject *parent) : QObject(parent)
{
	this->setName(name);
	this->setId(QUuid());
}
Player::Player(const QString &name, const QUuid &id,QObject *parent) : QObject(parent)
{
	this->setName(name);
	this->setId(id);
}
void Player::setName(const QString &name)
{
	if (name != m_name)
		m_name=name;
}
void Player::setId(const QUuid &id)
{
	if (id != m_id)
		m_id=id;
}
}
