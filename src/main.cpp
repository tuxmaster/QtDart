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
#include <QtCore>
#include <QApplication>
#include "Params.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setApplicationName(APP_NAME);

	QString translationPath=QLibraryInfo::path(QLibraryInfo::TranslationsPath);
	QTranslator tr_qt;
	QTranslator tr_app;
	if (tr_qt.load(QString("qt_%1").arg(QLocale::system().name()),translationPath))
	{
			if(tr_app.load(QString("%1_%2").arg(app.applicationName(), QLocale::system().name()),translationPath))
			{
				app.installTranslator(&tr_qt);
				app.installTranslator(&tr_app);
			}
	}
	return app.exec();
}
