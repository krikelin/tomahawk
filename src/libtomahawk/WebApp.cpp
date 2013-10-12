#include "WebApp.h"
using namespace Tomahawk;
WebApp::WebApp(QObject *parent) :
    QObject(parent)
{
}

WebApp::WebApp(QObject *parent, QString bundleIdentifier):
    QObject(parent) {
    this->m_bundleIdentifier = bundleIdentifier;
}

void WebApp::argumentsChanged(QStringList arguments) {

}

QString WebApp::title() {
    return QString("app");
}

QString WebApp::description() {
    return QString("T");
}
bool WebAppWidget::loaded() const {
    return m_loaded;
}
QString WebApp::bundleIdentifier() {
    return m_bundleIdentifier;
}

bool WebApp::loaded() {
    return true;
}
