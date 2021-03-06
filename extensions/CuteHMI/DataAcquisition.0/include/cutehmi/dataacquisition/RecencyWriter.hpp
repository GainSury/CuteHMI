#ifndef H_EXTENSIONS_CUTEHMI_DATAACQUISITION_0_INCLUDE_CUTEHMI_DATAACQUISITION_RECENCYWRITER_HPP
#define H_EXTENSIONS_CUTEHMI_DATAACQUISITION_0_INCLUDE_CUTEHMI_DATAACQUISITION_RECENCYWRITER_HPP

#include "internal/common.hpp"
#include "internal/RecencyCollective.hpp"
#include "AbstractWriter.hpp"

#include <cutehmi/services/Serviceable.hpp>

#include <QTimer>

namespace cutehmi {
namespace dataacquisition {

class CUTEHMI_DATAACQUISITION_API RecencyWriter:
	public AbstractWriter,
	private internal::DbServiceableMixin<RecencyWriter>
{
		Q_OBJECT

		friend class internal::DbServiceableMixin<RecencyWriter>;

	public:
		static constexpr int INITIAL_INTERVAL = 1000;

		/**
		  Interval [ms] between samples.

		  @assumption{cutehmi::dataacquisition::History-interval_non_negative}
		  Value of @a interval property should be non-negative.
		  */
		Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY intervalChanged)

		RecencyWriter(QObject * parent = nullptr);

		int interval() const;

		void setInterval(int interval);

		std::unique_ptr<ServiceStatuses> configureStarting(QState * starting) override;

		std::unique_ptr<ServiceStatuses> configureStarted(QState * active, const QState * idling, const QState * yielding) override;

		std::unique_ptr<ServiceStatuses> configureStopping(QState * stopping) override;

		std::unique_ptr<ServiceStatuses> configureBroken(QState * broken) override;

		std::unique_ptr<ServiceStatuses> configureRepairing(QState * repairing) override;

		std::unique_ptr<ServiceStatuses> configureEvacuating(QState * evacuating) override;

		std::unique_ptr<QAbstractTransition> transitionToStarted() const override;

		std::unique_ptr<QAbstractTransition> transitionToStopped() const override;

		std::unique_ptr<QAbstractTransition> transitionToBroken() const override;

		std::unique_ptr<QAbstractTransition> transitionToYielding() const override;

		std::unique_ptr<QAbstractTransition> transitionToIdling() const override;

	signals:
		void intervalChanged();

	CUTEHMI_PROTECTED_SIGNALS:
		void updateTimerStarted();

		void updateTimerStopped();

		void collectiveFinished();

	private slots:
		void updateValues();

		void onSchemaChanged();

		void startUpdateTimer();

		void stopUpdateTimer();

		void confirmCollectiveFinished();

	private:
		std::unique_ptr<services::Serviceable::ServiceStatuses> configureStartingOrRepairing(QState * parent);

		struct Members
		{
			internal::RecencyCollective dbCollective;
			QTimer updateTimer;
			int interval;

			Members():
				interval(INITIAL_INTERVAL)
			{
			}
		};

		MPtr<Members> m;
};

}
}

#endif

//(c)C: Copyright © 2020, Michał Policht <michal@policht.pl>. All rights reserved.
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
