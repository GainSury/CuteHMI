#ifndef CUTEHMI_LIBSTUPID_SRC_STUPID_COMMUNICATIONTHREAD_HPP
#define CUTEHMI_LIBSTUPID_SRC_STUPID_COMMUNICATIONTHREAD_HPP

#include <QThread>
#include <QAtomicInt>

namespace cutehmi {
namespace stupid {

class Client;

class CommunicationThread:
	public QThread
{
	Q_OBJECT
	typedef QThread Parent;

	public:
		explicit CommunicationThread(Client * client);

	public:
		unsigned long sleep() const;

		void setSleep(unsigned long sleep);

		void run() override;

	public slots:
		void start();

		void stop();

	private:
		QAtomicInt m_run;
		unsigned long m_sleep;
		Client * m_client;
};

}
}

#endif

//(c)MP: Copyright © 2016, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
