import qbs

import cutehmi

Project {
	name: "CuteHMI.Examples.Modbus.ClientServer.1"

	cutehmi.Extension {
		name: parent.name

		vendor: "CuteHMI"

		domain: "cutehmi.kde.org"

		friendlyName: "Modbus Client and Server Example"

		description: "Example allowing one to interact with Modbus client and server over Modbus TCP protocol."

		files: [
         "CoilControl.qml",
         "DeviceControl.qml",
         "DiscreteInputControl.qml",
         "GridLayoutModel.qml",
         "HoldingRegisterControl.qml",
         "InputRegisterControl.qml",
         "LICENSE",
         "View.qml",
         "README.md",
         "ServiceControl.qml",
         "TCPClientConfiguration.qml",
         "TCPServerConfiguration.qml",
     ]

		Depends { name: "cutehmi.doxygen" }
		cutehmi.doxygen.useDoxyqml: true

		Depends { name: "cutehmi.qmldir" }

		Depends { name: "cutehmi.qmltypes" }

		Depends { name: "cutehmi.view.4" }

		Depends { name: "CuteHMI.Modbus.2" }
	}
}

//(c)C: Copyright © 2020, Michał Policht <michal@policht.pl>. All rights reserved.
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
