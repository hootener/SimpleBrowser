
// System Includes
#include <QWebView.h>

// Application Includes

// Forward Declaratoins
class QWebInspector;

class SimpleWebView: public QWebView {
	Q_OBJECT
public:
	SimpleWebView(QString homeUrl, QWidget * pParent = nullptr);
	Q_SLOT void LoadUrl(QString url);
	Q_SLOT void LoadHome();
	Q_SLOT void RefreshPage();

protected:
	QString m_CurrentUrl;
	QString m_HomeUrl;

	QWebInspector * m_pWebInspector;

	Q_SLOT void UpdateOnPageLoad(bool ok);
};