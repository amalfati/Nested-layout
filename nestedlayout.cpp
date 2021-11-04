#include "nestedlayout.h"
#include<QApplication>
nestedlayout::nestedlayout(QWidget *parent) : QWidget(parent)
{
    createWidgets();

    placeWidgets();

    makeConnexions();
}
nestedlayout::~nestedlayout()
{
    delete nameLabel;
    delete nameEdit;
    delete backward;
    delete match;
    delete search;
    delete close;
}
void nestedlayout::createWidgets(){
    nameLabel =new QLabel("<h2> <i>name</i> </h2>");
    nameEdit =new QLineEdit;
    backward = new QCheckBox("search backward");
    match = new QCheckBox("match case");
    search =new QPushButton("search");
    close =new  QPushButton("close");
}
void nestedlayout::makeConnexions(){
   connect(close, &QPushButton::clicked,qApp, &QApplication::exit);
   connect(search, SIGNAL(clicked()),
             this, SLOT(findClicked()));
   connect(nameEdit, SIGNAL(textChanged(const QString &)),
              this, SLOT(enableFindButton(const QString &)));
}

void nestedlayout::placeWidgets(){
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
      topLeftLayout->addWidget(nameLabel);
      topLeftLayout->addWidget(nameEdit);

      QVBoxLayout *leftLayout = new QVBoxLayout;
       leftLayout->addLayout(topLeftLayout);
       leftLayout->addWidget(match);
       leftLayout->addWidget(backward);

       QVBoxLayout *rightLayout = new QVBoxLayout;
       rightLayout->addWidget(search);
       rightLayout->addWidget(close);
       rightLayout->addStretch();

       QHBoxLayout *mainLayout = new QHBoxLayout;
       mainLayout->addLayout(leftLayout);
       mainLayout->addLayout(rightLayout);
       setLayout(mainLayout);
}
