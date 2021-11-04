#ifndef NESTEDLAYOUT_H
#define NESTEDLAYOUT_H

#include <QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QCheckBox>
#include<QLineEdit>

class nestedlayout : public QWidget
{
    Q_OBJECT
public:
    explicit nestedlayout(QWidget *parent = nullptr);
virtual ~ nestedlayout();
protected:
    void createWidgets();
    void placeWidgets();
    void makeConnexions();
protected:
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QCheckBox *match;
    QCheckBox *backward;
    QPushButton *search;
    QPushButton *close;






};

#endif
