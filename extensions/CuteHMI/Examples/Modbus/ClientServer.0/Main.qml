import QtQml 2.2
import QtQuick 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

import CuteHMI.Modbus 2.0
import CuteHMI.Services 2.0

Item {
	Service {
		id: serverService

		name: "TCP Server"

		TCPServer {
			id: server
		}
	}

	Service {
		id: clientService

		name: "TCP Client"

		TCPClient {
			id: client
		}
	}

	ColumnLayout {
		anchors.centerIn: parent
		spacing: 20

		RowLayout {
			id: serverLayout

			spacing: 20

			ColumnLayout {
				spacing: 20

				ServiceControl {
					service: serverService
				}

				DeviceControl {
					device: server
					configurationItem: TCPServerConfiguration {
						server: server
					}
				}
			}

			GridLayout {
				id: serverControllersLayout

				rows: 3
				flow: GridLayout.TopToBottom

				Label {
					Layout.alignment: Qt.AlignRight

					text: qsTr("Register type:")
				}

				Label {
					Layout.alignment: Qt.AlignRight

					text: qsTr("Address:")
				}

				Label {
					Layout.alignment: Qt.AlignRight

					text: qsTr("Value:")
				}

				CoilControl {
					layout: serverControllersLayout

					controller: CoilController {
						device: server
					}
				}

				DiscreteInputControl {
					layout: serverControllersLayout

					controller: DiscreteInputController {
						device: server
					}
				}

				HoldingRegisterControl {
					layout: serverControllersLayout

					controller: HoldingRegisterController {
						device: server
					}
				}

				InputRegisterControl {
					layout: serverControllersLayout

					controller: InputRegisterController {
						device: server
					}
				}
			}
		}

		RowLayout {
			id: clientLayout

			spacing: 20

			ColumnLayout {
				spacing: 20

				ServiceControl {
					service: clientService
				}

				DeviceControl {
					device: client
					configurationItem: TCPClientConfiguration {
						client: client
					}
				}
			}

			GridLayout {
				id: clientControllersLayout

				rows: 3
				flow: GridLayout.TopToBottom

				Label {
					Layout.alignment: Qt.AlignRight

					text: qsTr("Register type:")
				}

				Label {
					Layout.alignment: Qt.AlignRight

					text: qsTr("Address:")
				}

				Label {
					Layout.alignment: Qt.AlignRight

					text: qsTr("Value:")
				}

				CoilControl {
					layout: clientControllersLayout

					controller: CoilController {
						device: client
					}
				}

				DiscreteInputControl {
					layout: clientControllersLayout
					text: qsTr("Discrete input (read-only)")

					controller: DiscreteInputController {
						device: client
					}
				}

				HoldingRegisterControl {
					layout: clientControllersLayout

					controller: HoldingRegisterController {
						device: client
					}
				}

				InputRegisterControl {
					layout: clientControllersLayout
					text: qsTr("Input register (read-only)")

					controller: InputRegisterController {
						device: client
					}
				}
			}
		}
	}
}

//(c)MP: Copyright © 2019, Michal Policht <michpolicht@gmail.com>. All rights reserved.
//(c)MP: This file is a part of CuteHMI.
//(c)MP: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)MP: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)MP: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
