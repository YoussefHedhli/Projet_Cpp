#ifndef GS_BILLET_H
#define GS_BILLET_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QImage>
#include <QFileDialog>
#include <QDir>
#include <QImageReader>
#include <QPixmap>
#include "billet.h"
#include "gs_equipe.h"// Ensure this line is in the includes at the top
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>  // Include QUrl for encoding URLs

namespace Ui {
class gs_billet;
}

class gs_billet : public QMainWindow
{
    Q_OBJECT

public:
    explicit gs_billet(QWidget *parent);
    ~gs_billet();

private slots:
    void on_res_clicked();        // Slot for adding a new ticket
    void on_modif_clicked();      // Slot for checking and modifying a ticket
    void on_res2_clicked();       // Slot for confirming modification
    void on_sup_clicked();        // Slot for deleting a ticket
    void on_cherch_clicked();     // Slot for the search button
    void on_aff_clicked();
    void on_confirm_clicked();
    void on_pdf_clicked();
    void on_siege_clicked();
    void on_stat_clicked();       // New slot for stat button
    void on_generate_clicked();   // Slot for generate button
    void onQRCodeDownloaded(QNetworkReply* reply);
    void generateQRCodeViaAPI(const QString &tableData);  // Function to generate QR code via API
    void displayTableDataInTextEdit(const QString &qrData);
    void onQRCodeScanned(const QString &qrData);
    void onCloseQRCode();
    void onSubmitClicked();  // Slot for Submit button
    void onGoClicked();      // Slot for Go button
    void paintEvent(QPaintEvent *event);
    void on_equipepass_clicked();

private:
    Ui::gs_billet *ui;

    // Declaring variables for matching
    QLineEdit *matchLineEdit;  // Line edit for inputting match ID
    QPushButton *submitBtn;    // Submit button
    QPushButton *goBtn;        // Go button

    QString datebValue;        // Store DATEB value
    QString etatValue;         // Store ETAT value
    QString lieuValue;         // Store LIEU value
    gs_equipe *equipeWindow = nullptr;

    bool ajouterBillet(const Billet &billet, int id_b);  // Function to add a ticket
    bool modifierBillet(int id_b, const QDate &newDateB, const QString &new_qrid);  // Function to modify a ticket
    bool fetchBilletById(int id_b);  // Function to check if a ticket exists

    void refreshTableWidget();  // Function to refresh the table

    QLineEdit *inputField;  // Declare inputField as a QLineEdit
    QNetworkAccessManager *networkManager;  // Declare networkManager for network requests
    QLineEdit *qridLineEdit;  // Declare the pointer to QLineEdit for QR ID input
    QLabel *qrCodeLabel;  // QLabel to display generated QR code
    QLineEdit* inputIdB;
    QPushButton* submitButton;
    QPushButton* goButton;
    QString qrDataToGenerate;
};

#endif // GS_BILLET_H
