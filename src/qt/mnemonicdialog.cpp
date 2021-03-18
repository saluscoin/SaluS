// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <mnemonic/walletinitflags.h>
#include "mnemonicdialog.h"
#include "forms/ui_mnemonicdialog.h"

MnemonicDialog::MnemonicDialog(QWidget *parent) : QDialog(parent), ui(new Ui::MnemonicDialog)
{
    shutdown = true;
    ui->setupUi(this);
    connect(ui->seedNew, SIGNAL(clicked(bool)), this, SLOT(radioSelection()));
    connect(ui->seedImport, SIGNAL(clicked(bool)), this, SLOT(radioSelection()));
    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(buttonClicked()));
}

MnemonicDialog::~MnemonicDialog()
{
    delete ui;
}

void MnemonicDialog::radioSelection()
{
    if (ui->seedNew->isChecked() || ui->seedImport->isChecked())
        ui->buttonBox->setEnabled(true);
    else
        ui->buttonBox->setEnabled(false);
}

void MnemonicDialog::buttonClicked()
{
    shutdown = false;
    if (ui->seedNew->isChecked())
        selection = NEW_MNEMONIC;

    else if (ui->seedImport->isChecked())
        selection = IMPORT_MNEMONIC;

    this->close();
}