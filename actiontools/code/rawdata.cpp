/*
	Actionaz
	Copyright (C) 2008-2010 Jonathan Mercier-Ganady

	Actionaz is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Actionaz is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.

	Contact : jmgr@jmgr.info
*/

#include "rawdata.h"

namespace Code
{
	QScriptValue RawData::constructor(QScriptContext *context, QScriptEngine *engine)
	{
		Q_UNUSED(context)
		
		return engine->newQObject(new RawData, QScriptEngine::ScriptOwnership);
	}
	
	QScriptValue RawData::constructor(const RawData &other, QScriptContext *context, QScriptEngine *engine)
	{
		Q_UNUSED(context)
		
		return engine->newQObject(new RawData(other), QScriptEngine::ScriptOwnership);
	}
	
	QScriptValue RawData::constructor(const QByteArray &byteArray, QScriptContext *context, QScriptEngine *engine)
	{
		Q_UNUSED(context)
		
		return engine->newQObject(new RawData(byteArray), QScriptEngine::ScriptOwnership);
	}
	
	RawData::RawData()
		: QObject(),
		QScriptable()
	{
	}
	
	RawData::RawData(const RawData &other)
		: QObject(),
		QScriptable(),
		mByteArray(other.mByteArray)
	{
	}
	
	RawData::RawData(const QByteArray &byteArray)
		: QObject(),
		QScriptable(),
		mByteArray(byteArray)
	{
	}
	
	RawData &RawData::operator=(RawData other)
	{
		swap(other);
		
		return *this;
	}
	
	RawData &RawData::operator=(QByteArray byteArray)
	{
		swap(byteArray);
		
		return *this;
	}
	
	void RawData::swap(RawData &other)
	{
		std::swap(mByteArray, other.mByteArray);
	}
	
	void RawData::swap(QByteArray &byteArray)
	{
		std::swap(mByteArray, byteArray);
	}
	
	QByteArray RawData::byteArray() const
	{
		return mByteArray;
	}
	
	QScriptValue RawData::append(const QVariant &data)
	{
		mByteArray.append(data.toByteArray());
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::chop(int n)
	{
		mByteArray.chop(n);
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::clear()
	{
		mByteArray.clear();
		
		return context()->thisObject();
	}
	
	bool RawData::contains(const QVariant &data)
	{
		return mByteArray.contains(data.toByteArray());
	}
	
	int RawData::count(const QVariant &data) const
	{
		return mByteArray.count(data.toByteArray());
	}
	
	int RawData::count() const
	{
		return mByteArray.count();
	}
	
	bool RawData::endWith(const QVariant &data) const
	{
		return mByteArray.endsWith(data.toByteArray());
	}
	
	int RawData::indexOf(const QVariant &data, int from) const
	{
		return mByteArray.indexOf(data.toByteArray(), from);
	}
	
	bool RawData::isEmpty() const
	{
		return mByteArray.isEmpty();
	}
	
	int RawData::lastIndexOf(const QVariant &data) const
	{
		return mByteArray.lastIndexOf(data.toByteArray());
	}
	
	QScriptValue RawData::left(int len) const
	{
		mByteArray.left(len);
		
		return context()->thisObject();
	}
	
	int RawData::length() const
	{
		return mByteArray.length();
	}
	
	QScriptValue RawData::mid(int pos, int len) const
	{
		mByteArray.mid(pos, len);
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::prepend(const QVariant &data)
	{
		mByteArray.prepend(data.toByteArray());
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::remove(int pos, int len)
	{
		mByteArray.remove(pos, len);
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::replace(const QString &before, const QString &after)
	{
		mByteArray.replace(before.toLatin1(), after.toLatin1());
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::resize(int size)
	{
		mByteArray.resize(size);
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::right(int len) const
	{
		mByteArray.right(len);
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::setData(const QVariant &data)
	{
		mByteArray = data.toByteArray();
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::simplified() const
	{
		mByteArray.simplified();
		
		return context()->thisObject();
	}
	
	int RawData::size() const
	{
		return mByteArray.size();
	}
	
	bool RawData::startsWith(const QVariant &data)
	{
		return mByteArray.startsWith(data.toByteArray());
	}
	
	double RawData::toNumber() const
	{
		return mByteArray.toDouble();
	}
	
	QString RawData::toString(Code::Encoding encoding) const
	{
		return Code::fromEncoding(mByteArray, encoding);
	}
	
	QScriptValue RawData::trimmed() const
	{
		mByteArray.trimmed();
		
		return context()->thisObject();
	}
	
	QScriptValue RawData::truncate(int pos)
	{
		mByteArray.truncate(pos);
		
		return context()->thisObject();
	}
}