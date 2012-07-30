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
