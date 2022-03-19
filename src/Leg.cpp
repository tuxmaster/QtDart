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
#include "Leg.h"

namespace Frank
{
Leg::Leg(QObject *parent) : QObject(parent)
{
	this->m_id=QUuid();
}
Leg::Leg(const QUuid id, QObject *parent): QObject(parent)
{
	this->m_id=id;
}
void Leg::setId(const QUuid id)
{
	if (this->m_id != id)
		this->m_id=id;
}
}
