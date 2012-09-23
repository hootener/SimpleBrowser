// System Includes
#include <QUrl>
#include <QGestureEvent>
#include <QPinchGesture>
#include <QApplication>
#include <QWebInspector>
#include <QDebug>

// Application Includes
#include "SimpleWebView.h"

SimpleWebView::SimpleWebView(QString homeUrl, QWidget * pParent):QWebView(pParent),
m_HomeUrl(homeUrl),
m_CurrentUrl(homeUrl){
	load(QUrl(homeUrl));
	show();
	//grabGesture(Qt::PinchGesture);
	setAttribute(Qt::WA_AcceptTouchEvents);

	page()->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
	this->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

	m_pWebInspector = new QWebInspector();

	connect(this,SIGNAL(loadFinished(bool)), this, SLOT(UpdateOnPageLoad(bool)));
}

void SimpleWebView::LoadUrl(QString url){
	if(!url.contains("http://") && !url.contains("ftp://") && !url.contains("https://") && !url.contains("ftps://")){
		//default to http, don't overwrite ftp.
		url.prepend("http://");
	}
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

void SimpleWebView::UpdateOnPageLoad(bool ok){
	if(!ok){
		qDebug() << "Something went wront with the page load";
		return;
	}

	if(m_pWebInspector->isVisible()){ 
		m_pWebInspector->setPage(this->page());
	}
}
