#ifndef LEG_H
#define LEG_H

#include <QtCore>

class Leg : public QObject
{
		Q_OBJECT
	public:
		explicit		Leg(QObject *parent = nullptr);
		explicit		Leg(const QUuid id, QObject *parent = nullptr);
		void			setId(const QUuid id);
		const QUuid&	getId() const { return m_id;}
	private:
		QUuid			m_id;

};

#endif // LEG_H
