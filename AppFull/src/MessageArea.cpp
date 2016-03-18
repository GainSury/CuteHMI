#include "MessageArea.hpp"
#include "MessageEvent.hpp"

#include <QMutexLocker>
#include <QMessageBox>
#include <QCoreApplication>

#include <iostream>

namespace cutehmi {

//static
//void MessageArea::Append(const char * msg)
//{
//	static QMutex mutex;
//	QMutexLocker locker(&mutex);

//	if (MessageArea::MsgHandler != 0)
//		QCoreApplication::postEvent(MessageArea::MsgHandler, new MessageEvent(msg));
//	else
//		std::cerr << msg << "\n";
//}

MessageArea::MessageArea(QWidget * parent):
	QTextEdit(parent)
{
}

MessageArea::MessageArea(const QString & text, QWidget * parent):
	QTextEdit(text, parent)
{
}

void MessageArea::postMsgEvent(QtMsgType type, const QString & msg)
{
	QString qmsg(msg);
	switch (type) {
		case QtDebugMsg:
			break;
		case QtWarningMsg:
			qmsg.prepend("<font color=\"#FF0000\">");
			qmsg.append("</font>");
			break;
		case QtCriticalMsg:
			if (QMessageBox::critical(this,
					tr("Critical error - %1").arg(QCoreApplication::applicationName()),
					qmsg,
					QMessageBox::Ignore,
					QMessageBox::Abort,
					QMessageBox::NoButton) == QMessageBox::Abort)
				abort(); // core dump
			qmsg.prepend("<b><font color=\"#FF0000\">");
			qmsg.append("</font></b>");
			break;
		case QtFatalMsg:
			QMessageBox::critical(this,
					tr("Fatal error - %1").arg(QCoreApplication::applicationName()),
					qmsg,
					QMessageBox::Ok,
					QMessageBox::NoButton,
					QMessageBox::NoButton);
			abort(); // deliberately core dump
		default:
			break;
	}
	//it's impossible to change GUI directly from thread other than the main thread
	//so post message encapsulated by MessageEvent to the main thread's event queue
	QCoreApplication::postEvent(this, new MessageEvent(qmsg));
}

void MessageArea::customEvent(QEvent * event)
{
	if (event->type() == MessageEvent::EventType())
		append(dynamic_cast<MessageEvent * >(event)->msg);
}

}

//(c)MP: Copyright © 2016, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
