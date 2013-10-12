/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2010-2011, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *   Copyright 2010-2011, Jeff Mitchell <jeff@tomahawk-player.org>
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

#ifndef WEBAPP_PAGE_H
#define VEBAPP_PAGE_H

#include "Typedefs.h"
#include "PlaylistInterface.h"
#include "Artist.h"
#include "Album.h"
#include "Source.h"
#include "utils/TomahawkUtils.h"
#include "playlist/PlaylistUpdaterInterface.h"

#include <QtGui/QPixmap>
#include <QString>


class WebAppWidget : public QWidget, public Tomahawk::ViewPage
{
public:


    WebAppWidget(QWidget* parent = 0) {}
    ~WebAppWidget() {

    }

    virtual QWidget* widget();



    virtual QString title() const {
        return QString("App");
    }

    virtual QString description() const {
        return QString("desc");
    }

    QString longDescription() const { return QString(); }
    QPixmap pixmap() const { return QPixmap( RESPATH "icons/tomahawk-icon-128x128.png" ); }

    bool showInfoBar() const { return true; }
    bool showFilter() const { return false; }
    bool queueVisible() const { return true; }

    QString filter() const { return m_filter; }
    bool setFilter( const QString& filter );

    bool willAcceptDrag( const QMimeData* data );
    bool dropMimeData( const QMimeData*, Qt::DropAction );

    bool jumpToCurrentTrack();

    bool isTemporaryPage() const { return false; }
    bool loaded() const;
    bool isBeingPlayed() const { return false; }
    void setApp(const Tomahawk::app_ptr& app);
    virtual void setDetailedView();
    virtual Tomahawk::playlistinterface_ptr playlistInterface() const {
        return m_playlistInterface;
    }

    /** subclasses implementing ViewPage can emit the following signals:
     * nameChanged( const QString& )
     * descriptionChanged( const QString& )
     * descriptionChanged( const Tomahawk::artist_ptr& artist )
     * descriptionChanged( const Tomahawk::album_ptr& album )
     * longDescriptionChanged( const QString& )
     * pixmapChanged( const QPixmap& )
     * destroyed( QWidget* widget );
     *
     * See DynamicWidget for an example
     */
private:
    Tomahawk::playlistinterface_ptr m_playlistInterface;
    QString m_filter;
    Tomahawk::app_ptr m_webApp;
    QWidget* m_widget;
    bool m_loaded;
};



#endif //VIEWPAGE_H
