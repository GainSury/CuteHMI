#ifndef H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_NOTIFICATIONLISTMODEL_HPP
#define H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_NOTIFICATIONLISTMODEL_HPP

#include "internal/common.hpp"
#include "Notification.hpp"

#include <QAbstractListModel>

namespace cutehmi {

/**
 * %Notification list model.
 */
class CUTEHMI_API NotificationListModel:
	public QAbstractListModel
{
		Q_OBJECT
		typedef QAbstractListModel Parent;

	public:
		enum Role {
			TYPE_ROLE = Qt::UserRole,
			DATE_TIME_ROLE
		};

		NotificationListModel(QObject * parent = nullptr);

		~NotificationListModel() override;

		int rowCount(const QModelIndex & parent = QModelIndex()) const override;

		QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

		QHash<int, QByteArray> roleNames() const override;

		void prepend(std::unique_ptr<Notification> notification);

		void removeLast(int num = 1);

		void clear();

	private:
		typedef QList<Notification *> NotificationsContainer;

		struct Members
		{
			NotificationsContainer notifications;
		};

		MPtr<Members> m;
};

}

#endif

//(c)MP: Copyright © 2018-2019, Michal Policht <michpolicht@gmail.com>. All rights reserved.
//(c)MP: This file is a part of CuteHMI.
//(c)MP: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)MP: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)MP: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
