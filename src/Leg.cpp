#include "Leg.h"

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
