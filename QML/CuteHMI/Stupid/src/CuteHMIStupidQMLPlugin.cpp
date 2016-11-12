#include "CuteHMIStupidQMLPlugin.hpp"

#include <stupid/DS18B20.hpp>
#include <stupid/DS18B20History.hpp>

#include <QtQml>

void CuteHMIStupidQMLPlugin::registerTypes(const char * uri)
{
	Q_ASSERT(uri == QLatin1String("CuteHMI.Stupid"));
	qmlRegisterType<cutehmi::stupid::DS18B20>(uri, 1, 0, "DS18B20");
	qmlRegisterType<cutehmi::stupid::DS18B20History>(uri, 1, 0, "DS18B20History");
}

//(c)MP: Copyright © 2016, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
