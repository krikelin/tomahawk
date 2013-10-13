#include "WebAppWidget.h"
#include "MetaPlaylistInterface.h"
using namespace Tomahawk;
WebAppWidget::WebAppWidget(QWidget *parent) :
    QWidget(parent)
{

    MetaPlaylistInterface* mpl = new MetaPlaylistInterface();
    m_playlistPtr = Tomahawk::playlistinterface_ptr( mpl) ;
}

WebAppWidget::~WebAppWidget() {

}
QWidget* WebAppWidget::widget() {
    return this;
}

QString WebAppWidget::title() const {
    return QString("Test");
}

QString WebAppWidget::description() const {
    return QString("description");
}

bool WebAppWidget::willAcceptDrag(QMimeData const* t) const {
    return FALSE;
}

bool WebAppWidget::dropMimeData(QMimeData const* t, Qt::DropAction action) {
    return FALSE;
}

bool WebAppWidget::setFilter(const QString &filter) {
    this->filter() = filter;
}
bool WebAppWidget::jumpToCurrentTrack() {
    return false;
}
Tomahawk::playlistinterface_ptr WebAppWidget::playlistInterface() const {
    return m_playlistPtr;
}
