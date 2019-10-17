import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

import CuteHMI.Services 2.0

RowLayout {
	spacing: 20

	property Service service

	ColumnLayout {
		GridLayout {
			columns: 2

			Label {
				text: qsTr("%1 status:").arg(service.name)
			}

			Label {
				text: service.status
			}
		}

		Row {
			Layout.alignment: Qt.AlignRight

			spacing: 5

			Button {
				text: qsTr("Start")
				onClicked: service.start()
			}

			Button {
				text: qsTr("Stop")
				onClicked: service.stop()
			}
		}
	}
}

//(c)MP: Copyright © 2019, Michal Policht <michpolicht@gmail.com>. All rights reserved.
//(c)MP: This file is a part of CuteHMI.
//(c)MP: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)MP: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)MP: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
