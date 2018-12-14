#include "Daemon.hpp"
//#include "Settings.hpp"
//#include "Core.hpp"

#include <thread>
#include <chrono>

namespace cutehmi {
namespace daemon {

//constexpr int Daemon::SLEEP_UNIT;

Daemon::Daemon():
	m_terminate(false)
{
	_init();
}

Daemon::~Daemon()
{
	_destroy();
}

void Daemon::terminate()
{
	m_terminate = true;
}

//void Daemon::exec(int maxFails)
//{
//}

}
}

//(c)MP: Copyright © 2018, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
