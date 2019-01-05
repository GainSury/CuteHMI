import qbs

import cutehmi

cutehmi.Test
{
	testNamePrefix: parent.parent.name

	Depends { name: "CuteHMI.BitcoinCash.0" }
	Depends { name: "CuteHMI.Test.0" }
}

//(c)MP: Copyright © 2019, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
