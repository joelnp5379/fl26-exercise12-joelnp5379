#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  void initialState();
  void clickTogglesRadioButton();
  
};

// Implement the tests here
void TestToggleWidget::initialState() {
  ToggleWidget w;
  QVERIFY(!w.isOn());
}

void TestToggleWidget::clickTogglesRadioButton() {
  ToggleWidget w;
  w.show();
  
  QPushButton *pb = w.findChild<QPushButton *>();
  QVERIFY(pb != nullptr);

  QVERIFY(!w.isOn());
 
  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(w.isOn());
 
  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(!w.isOn());
}


QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
