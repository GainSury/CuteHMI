#ifndef CUTEHMI_CUTEHMI__BASE__1__LIB_INCLUDE_BASE_XMLBACKENDPLUGIN_HPP
#define CUTEHMI_CUTEHMI__BASE__1__LIB_INCLUDE_BASE_XMLBACKENDPLUGIN_HPP

#include "internal/common.hpp"
#include "IBackendPlugin.hpp"

#include <QObject>

#include <memory>

namespace cutehmi {
namespace xml {

class CUTEHMI_XML_API BackendPlugin:
	public QObject
{
	Q_OBJECT

	public:
		explicit BackendPlugin(IBackendPlugin * implementation, QObject * parent = 0);

		IBackendPlugin * implementation();

	private:
		struct Members
		{
			IBackendPlugin * implementation;
		};

		MPtr<Members> m;
};

}
}

#endif

//(c)MP: Copyright © 2017, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
