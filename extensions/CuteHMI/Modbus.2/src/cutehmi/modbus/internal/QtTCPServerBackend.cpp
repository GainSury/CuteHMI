#include <cutehmi/modbus/internal/QtTCPServerBackend.hpp>
#include <cutehmi/modbus/internal/functions.hpp>

#include <QThread>
#include <QJsonArray>

namespace cutehmi {
namespace modbus {
namespace internal {

QtTCPServerBackend::QtTCPServerBackend(TCPServerConfig * config,
		QtTCPServer::CoilDataContainer * coilData,
		QtTCPServer::DiscreteInputDataContainer * discreteInputData,
		QtTCPServer::HoldingRegisterDataContainer * holdingRegisterData,
		QtTCPServer::InputRegisterDataContainer * inputRegisterData,
		QObject * parent):
	QtServerBackend(std::make_unique<QtTCPServer>(coilData, discreteInputData, holdingRegisterData, inputRegisterData), parent),
	m(new Members{config})
{
}

int QtTCPServerBackend::slaveId() const
{
	return m->config->slaveAddress();
}

void QtTCPServerBackend::configureConnection()
{
	qServer()->setConnectionParameter(QModbusDevice::NetworkAddressParameter, m->config->host());
	qServer()->setConnectionParameter(QModbusDevice::NetworkPortParameter, m->config->port());

	CUTEHMI_DEBUG("Server configured on '" << m->config->host() << ":" << m->config->port() << "'.");
}

}
}
}

//(c)MP: Copyright © 2019, Michal Policht <michpolicht@gmail.com>. All rights reserved.
//(c)MP: This file is a part of CuteHMI.
//(c)MP: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)MP: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)MP: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
