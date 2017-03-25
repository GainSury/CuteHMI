#ifndef CUTEHMI_LIBSTUPID_INCLUDE_STUPID_DATABASECONNECTIONDATA_HPP
#define CUTEHMI_LIBSTUPID_INCLUDE_STUPID_DATABASECONNECTIONDATA_HPP

#include <QString>

namespace cutehmi {
namespace stupid {

struct DatabaseConnectionData
{
	QString type;
	QString connectionName;
	QString hostName;
	int port;
	QString databaseName;
	QString userName;
	QString password;
};

}
}

#endif

//(c)MP: Copyright © 2016, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
