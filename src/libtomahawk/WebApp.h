/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2013, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *   Copyright 2013, Teo Mrnjavac <teo@kde.org>
 *   Copyright 2013, Uwe L. Korn <uwelk@xhochy.com>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef WEBAPP_H
#define WEBAPP_H

#include "DllMacro.h"
#include "PlaybackLog.h"
#include "SocialAction.h"
#include "Typedefs.h"
#include "ViewManager.h"

#include <QList>
#include <QStringList>
namespace Tomahawk
{

class DLLEXPORT WebApp : public QObject
{
    Q_OBJECT
public:
    explicit WebApp(QObject *parent = 0);
    explicit WebApp(QString bundleIdentifier);
    void argumentsChanged(QStringList arguments);
    QString title() const;
    QString description() const;
    QString bundleIdentifier() const;
    bool loaded() const;
signals:

public slots:
private:
    QString m_bundleIdentifier;
    bool m_loaded;
};

}

Q_DECLARE_METATYPE( Tomahawk::app_ptr )
#endif // WEBAPP_H
