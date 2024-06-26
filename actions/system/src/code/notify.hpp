/*
	Actiona
	Copyright (C) 2005 Jonathan Mercier-Ganady

	Actiona is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Actiona is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.

	Contact: jmgr@jmgr.info
*/

#pragma once

#include "actiontools/code/codeclass.hpp"

#include <QJSValue>
#include <QStringList>

struct _NotifyNotification;

namespace Code
{
	class Notify : public CodeClass
	{
		Q_OBJECT
		
	public:
        Q_INVOKABLE Notify();
        Q_INVOKABLE Notify(const QJSValue &parameters);
		~Notify() override;
		
        Q_INVOKABLE QString toString() const override                                { return QStringLiteral("Notify"); }
        Q_INVOKABLE Notify *show(const QJSValue &parameters);

        static void registerClass(ActionTools::ScriptEngine &scriptEngine);
		
	private:
		_NotifyNotification *mNotification{nullptr};
		QString mTitle;
		QString mText;
		QString mIcon;
		int mTimeout{5000};
	};
}

