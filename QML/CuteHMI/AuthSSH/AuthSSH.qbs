import qbs

import cutehmi

cutehmi.QMLExtension {
	name: "CuteHMI.AuthSSH"

	major: 1

	minor: 0

	micro: 0

	vendor: "CuteHMI"

	friendlyName: "SSH Authentication QML"

	description: "QML components for authentication and tunneling with SSH protocol."

	author: "Michal Policht"

	copyright: "Michal Policht"

	license: "Mozilla Public License, v. 2.0"

	files: [
        "qmldir",
        "src/CuteHMIAuthSSHQMLPlugin.cpp",
        "src/CuteHMIAuthSSHQMLPlugin.hpp",
    ]

	//<workaround id="qbs-cutehmi-depends-1" target="Qbs" cause="design">
	Depends { name: "cutehmi_authssh_1" } cutehmi_authssh_1.reqMinor: 0
	//</workaround>
}

