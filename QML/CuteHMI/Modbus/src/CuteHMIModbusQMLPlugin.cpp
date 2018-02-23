#include "CuteHMIModbusQMLPlugin.hpp"
#include "cutehmi/modbus/qml/CoilController.hpp"
#include "cutehmi/modbus/qml/DiscreteInputController.hpp"
#include "cutehmi/modbus/qml/HoldingRegisterController.hpp"
#include "cutehmi/modbus/qml/InputRegisterController.hpp"

#include <cutehmi/modbus/HoldingRegister.hpp>
#include <cutehmi/modbus/InputRegister.hpp>
#include <cutehmi/modbus/DiscreteInput.hpp>
#include <cutehmi/modbus/Coil.hpp>
#include <cutehmi/modbus/Client.hpp>

#include <QtQml>

void CuteHMIModbusQMLPlugin::registerTypes(const char * uri)
{
	Q_ASSERT(uri == QLatin1String("CuteHMI.Modbus"));

	qmlRegisterType<cutehmi::modbus::InputRegister>(uri, 1, 0, "InputRegister");
	qmlRegisterType<cutehmi::modbus::HoldingRegister>(uri, 1, 0, "HoldingRegister");
	qmlRegisterType<cutehmi::modbus::DiscreteInput>(uri, 1, 0, "DiscreteInput");
	qmlRegisterType<cutehmi::modbus::Coil>(uri, 1, 0, "Coil");
	qmlRegisterType<cutehmi::modbus::AbstractDevice>();
	qmlRegisterType<cutehmi::modbus::Client>();

	qmlRegisterType<cutehmi::modbus::qml::HoldingRegisterController>(uri, 1, 0, "HoldingRegisterController");
	qmlRegisterType<cutehmi::modbus::qml::InputRegisterController>(uri, 1, 0, "InputRegisterController");
	qmlRegisterType<cutehmi::modbus::qml::DiscreteInputController>(uri, 1, 0, "DiscreteInputController");
	qmlRegisterType<cutehmi::modbus::qml::CoilController>(uri, 1, 0, "CoilController");
}

//(c)MP: Copyright © 2017, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
