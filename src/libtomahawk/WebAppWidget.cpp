#include "WebAppWidget.h"

WebAppWidget::WebAppWidget(QWidget* parent = 0)
    : QWidget(parnt)
{

}
void WebAppWidget::setDetailedView() {

}

Tomahawk::artist_ptr descriptionArtist() const { return Tomahawk::artist_ptr(); }
Tomahawk::album_ptr descriptionAlbum() const { return Tomahawk::album_ptr(); }

QString WebAppWidget::longDescription() const { return QString(); }
QPixmap WebAppWidget::pixmap() const { return QPixmap( RESPATH "icons/tomahawk-icon-128x128.png" ); }

bool WebAppWidget::showInfoBar() const { return true; }
bool WebAppWidget::showFilter() const { return false; }
bool WebAppWidget::queueVisible() const { return true; }

QString WebAppWidget::filter() { return m_filter; }
bool WebAppWidget::setFilter( const QString& filter ){
    m_filter = filter;
}

bool WebAppWidget::willAcceptDrag( const QMimeData* data ) {
    return false;
}

bool WebAppWidget::dropMimeData( const QMimeData*, Qt::DropAction ){
    return false;
}

void WebAppWidget::setDetailedView() {

}

bool WebAppWidget::jumpToCurrentTrack() {
    return false;
}

bool WebAppWidget::isTemporaryPage() {
    return false;
}
bool WebAppWidget::loaded() const {
    return m_loaded;
}

bool WebAppWidget::isBeingPlayed() {
    return false;
}

void WebAppWidget::setApp(const Tomahawk::app_ptr& app) {
    this->m_webApp = app;
}

virtual QList<PlaylistUpdaterInterface*> updaters() const { return QList<PlaylistUpdaterInterface*>(); }

