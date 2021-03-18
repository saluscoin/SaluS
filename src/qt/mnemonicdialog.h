// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef VEIL_MNEMONICDIALOG_H
#define VEIL_MNEMONICDIALOG_H

#include <mnemonic/walletinitflags.h>

#include <QDialog>
#include <QThread>

namespace Ui {
    class MnemonicDialog;
}

class MnemonicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MnemonicDialog(QWidget *parent = 0);
    ~MnemonicDialog();
    bool ShutdownRequested() const { return shutdown; }
    MnemonicWalletInitFlags GetSelection() const { return selection; }

private Q_SLOTS:
    void radioSelection();
    void buttonClicked();

private:
    Ui::MnemonicDialog *ui;
    bool shutdown;
    MnemonicWalletInitFlags selection;
};


#endif //VEIL_MNEMONICDIALOG_H
