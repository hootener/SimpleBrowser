
// System Includes
#include <QWebView>

// Application Includes

// Forward Declaratoins
class QPinchGesture;

class SimpleWebView: public QWebView{
	Q_OBJECT
public:
	SimpleWebView(QString homeUrl, QWidget * pParent = NULL);
	Q_SLOT void LoadUrl(QString url);
	Q_SLOT void LoadHome();
	Q_SLOT void RefreshPage();
protected:
	virtual bool event(QEvent* pEvent);

	/**
	 * Receives pinch gesture events when performed within the webview
	 */
	void HandlePinch(QPinchGesture* pGesture);
protected:
	QString m_CurrentUrl;
	QString m_HomeUrl;
};