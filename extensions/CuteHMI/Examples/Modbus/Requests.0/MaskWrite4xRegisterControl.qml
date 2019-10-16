import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import CuteHMI.Modbus 2.0

RowLayout {
	property AbstractDevice device

	property int andMask: 0
	property int orMask: 0

	Button {
		text: "Mask write 4X register"
		onClicked: device.requestMaskWriteHoldingRegister(addressBox.value, parent.andMask, parent.orMask)
	}

	Label {
		text: qsTr("Address:")
	}

	SpinBox {
		id: addressBox

		editable: true
		from: 0
		to: 65535
	}

	Label {
		text: qsTr("And mask (hex):")
	}

	TextField {
		text: "0x" + parent.andMask.toString(16)
		validator: RegExpValidator {
			regExp: /0x[0-9A-Fa-f]{1,4}/
		}

		onAccepted: parent.andMask = parseInt(text)
	}

	Label {
		text: qsTr("Or mask (hex):")
	}

	TextField {
		text: "0x" + parent.orMask.toString(16)
		validator: RegExpValidator {
			regExp: /0x[0-9A-Fa-f]{1,4}/
		}

		onAccepted: parent.orMask = parseInt(text)
	}
}
