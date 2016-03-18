#ifndef CUTEHMI_LIBWIDGETS_SRC_WIDGETS_ERRORBOX_HPP
#define CUTEHMI_LIBWIDGETS_SRC_WIDGETS_ERRORBOX_HPP

#include "../platform.hpp"

#include <base/Error.hpp>
#include <base/ExtError.hpp>
#include <base/ErrorInfo.hpp>
#include <base/ExtErrorInfo.hpp>

#include <QMessageBox>
#include <QApplication>

#include <typeinfo>

namespace cutehmi {
namespace widgets {

class CUTEHMI_WIDGETS_API ErrorBox:
	public QObject
{
	public:
		ErrorBox(const QString & text = QString(), const QString & informativeText = QString(), const QString & detailedText = QString(), const QString & title = QCoreApplication::applicationName());

		QString title() const;

		void setTitle(const QString & title);

		QString text() const;

		void setText(const QString & text);

		QString informativeText() const;

		void setInformativeText(const QString & informativeText);

		QString detailedText() const;

		void setDetailedText(const QString & detailedText);

		/**
		 * Execute. Shows message box on failure, that is when error code has a value different than
		 * @p base::Error::OK.
		 * @param error error object. Must be derived from base::Error.
		 * @return error object.
		 */
		template <typename ERROR>
		ERROR exec(ERROR error);

		/**
		 * Execute extended. Shows message box on failure, that is when error code has a value different than
		 * @p base::ExtError::OK.
		 * @param error error object. Must be derived from base::ExtError.
		 * @return extended error object.
		 */
		template <typename EXTERROR>
		EXTERROR execExt(EXTERROR extError);

	public slots:
		void execInfo(base::ErrorInfo errInfo);

		void execExtInfo(base::ExtErrorInfo extErrInfo);

	private:
		void execCommon(QMessageBox & msgBox, base::ErrorInfo & errInfo);

	private:
		QString m_title;
		QString m_text;
		QString m_informativeText;
		QString m_detailedText;
};

template <typename ERROR>
ERROR ErrorBox::exec(ERROR error)
{
	if (error == base::Error::OK)
		return error;
	execInfo(base::errorInfo(error));
	return error;
}

template <typename EXTERROR>
EXTERROR ErrorBox::execExt(EXTERROR extError)
{
	if (extError == base::ExtError::OK)
		return extError;
	execExtInfo(base::extErrorInfo(extError));
	return extError;
}

}
}

#endif

//(c)MP: Copyright © 2016, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
