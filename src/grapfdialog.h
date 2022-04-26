#ifndef SRC_GRAPFDIALOG_H_
#define SRC_GRAPFDIALOG_H_

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class GrapfDialog;
}
QT_END_NAMESPACE

class GrapfDialog : public QDialog {
  Q_OBJECT

 public:
  explicit GrapfDialog(QWidget *parent = nullptr);
  ~GrapfDialog();

 private:
  Ui::GrapfDialog *ui;
};

#endif  // SRC_GRAPFDIALOG_H_
