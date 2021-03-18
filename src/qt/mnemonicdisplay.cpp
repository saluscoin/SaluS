// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "mnemonicdisplay.h"
#include "forms/ui_mnemonicdisplay.h"

#include <sstream>
#include <boost/algorithm/string/join.hpp>

MnemonicDisplay::MnemonicDisplay(bool fRetry, QWidget *parent) : QDialog(parent), ui(new Ui::MnemonicDisplay)
{
    shutdown = true;
    ui->setupUi(this);
    if (fRetry) {
        ui->lblExplanation->setText("INVALID SEED: Please try again.");
        ui->lblExplanation->setStyleSheet("QLabel { color : red; }");
    } else
        ui->lblExplanation->setText("Please paste your seed in the box below.");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

MnemonicDisplay::MnemonicDisplay(QString seed, QWidget *parent) : QDialog(parent), ui(new Ui::MnemonicDisplay)
{
    shutdown = true;
    ui->setupUi(this);
    ui->seedEdit->setText(seed);
    ui->seedEdit->setReadOnly(true);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

MnemonicDisplay::~MnemonicDisplay()
{
    delete ui;
}

void MnemonicDisplay::buttonClicked()
{
    shutdown = false;
    importSeed = ui->seedEdit->toPlainText();
    this->close();
}
