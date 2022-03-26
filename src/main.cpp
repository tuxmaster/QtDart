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
#include <QtCore>
#include <QApplication>
#include <QtGui>
#include <QtWidgets>
#include <Params.h>
#include "MainWindow.h"
Q_DECLARE_LOGGING_CATEGORY(LOG_CAT_MAIN)
Q_LOGGING_CATEGORY(LOG_CAT_MAIN, LOG_CAT_MAIN_TEXT)
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setApplicationName(APP_NAME);
	app.setApplicationVersion(APP_VERSION);
	app.setOrganizationName(ORG_NAME);

	QIcon icon=QIcon(":/img/Dartboard.svg");
	app.setWindowIcon(icon);

	QString translationPath=QLibraryInfo::path(QLibraryInfo::TranslationsPath);
	QTranslator tr_qt;
	QTranslator tr_app;

	qCDebug(LOG_CAT_MAIN) << "try to load qt translation from "<< translationPath;
	if (tr_qt.load(QString("qt_%1").arg(QLocale::system().name()),translationPath))
	{
		qCDebug(LOG_CAT_MAIN) << "found Qt translation";
		QString appTranslationName = QString("%1_%2").arg(app.applicationName(), QLocale::system().name());
		qCDebug(LOG_CAT_MAIN) << "try to load app transalation" << appTranslationName;
		if(!tr_app.load(appTranslationName, translationPath))
		{
			qCDebug(LOG_CAT_MAIN) << "failed load app translation from Qt path, try next the current path";
			if(tr_app.load(QString("%1_%2").arg(app.applicationName(), QLocale::system().name())))
				qCDebug(LOG_CAT_MAIN) << "app tranlation found";
		}
	}
	if(!tr_app.isEmpty() and !tr_qt.isEmpty())
	{
		app.installTranslator(&tr_qt);
		app.installTranslator(&tr_app);
	}

	QList<QByteArray> formats = QImageReader::supportedImageFormats();
	if(!formats.contains("svg"))
	{
		qCDebug(LOG_CAT_MAIN) << "supported image formats" << formats;
		QMessageBox::critical(nullptr,  QCoreApplication::translate("main","Error"), QCoreApplication::translate("main", "The SVG part of Qt is missing."));
		return 1;
	}

	Frank::MainWindow mw;
	mw.show();
	return app.exec();
}
