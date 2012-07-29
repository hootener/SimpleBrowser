// System Includes
#include <QUrl>
#include <QGestureEvent>
#include <QPinchGesture>
#include <QApplication>

// Application Includes
#include "SimpleWebView.h"

SimpleWebView::SimpleWebView(QString homeUrl, QWidget * pParent):QWebView(pParent),
m_HomeUrl(homeUrl),
m_CurrentUrl(homeUrl){
	load(QUrl(homeUrl));
	show();
	grabGesture(Qt::PinchGesture);
}

void SimpleWebView::LoadUrl(QString url){
	m_CurrentUrl = url;
	load(QUrl(url));
}
void SimpleWebView::LoadHome(){
	m_CurrentUrl = m_HomeUrl;
	load(QUrl(m_HomeUrl));

}

void SimpleWebView::RefreshPage(){
	load(m_CurrentUrl);
}

bool SimpleWebView::event (QEvent* pEvent) {

	if (pEvent->type() == QEvent::Gesture) {
		if (QGesture *pPinch = static_cast<QGestureEvent*>(pEvent)->gesture(Qt::PinchGesture)) {
			HandlePinch(static_cast<QPinchGesture *>(pPinch));
		}
	}
	return QWebView::event(pEvent);
};

void SimpleWebView::HandlePinch(QPinchGesture* pGesture) {
	// Note: could use QCursor::pos() or pGesture->startCenterPoint() instead of pGesture->centerPoint()
	// Note: subtracting the scale factors is probably not correct
	QWheelEvent wheelEvent(pGesture->centerPoint().toPoint(), pGesture->scaleFactor() - pGesture->lastScaleFactor(), Qt::NoButton, Qt::NoModifier);
	QApplication::sendEvent(this, &wheelEvent);
}