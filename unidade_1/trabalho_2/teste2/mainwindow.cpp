#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QPixmap>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   //método construtor
    ui->setupUi(this);
    //cor branco como padrão incial do teste
    ui->label_3->setStyleSheet("background-color: #ffffff;");
    //imagem das setas
    QPixmap setas_colors("/home/ubuntu/teste2/setas_colors.png");
    ui->label->setPixmap(setas_colors.scaled(251,251,Qt::KeepAspectRatio));
    //Frase inicial da barra de status
    ui->statusbar->showMessage("Teste seu tempo de reação.");
    //Frase inicial da cor branca
    ui->label_3->setText("Pressione *Enter* para começar...");
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_6_clicked()
{
    close();
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::warning(this,"REGRAS!!!","* Pressione a seta do teclado que corresponde a respectiva cor. * Cada erro terá desconto de 1 ponto num score total de 10 pontos. * Será considerado erro se o usuário não clicar na cor num tempo máximo de 3 segundos ou se clicar numa cor no teclado que não corresponde a cor mostrada na tela.");
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //Arquivo tempomicro
    //time_t tempo_inicial, tempo_final;
    //sleep

    //variável que armazena o evento de pressionar qual tecla
    int key = e->key();

    /*
     Representação das cores pelas posições do vetor cores:
     amarelo = elemento 0
     verde = elemento 1
     azul = elemento 2
     vermelho = elemento 3
    */

    //variável para armazenar o score inicial de 10 pontos
    int score = 10;
    //Gera um número por sorteio de 0 até 3

    //for(int i=0;i<10;i++){
    int cor_sorteada = rand()%4;

    if (cor_sorteada == 0){
        ui->label_3->setStyleSheet("background-color: #ffff00;"); //amarelo
        if (key == Qt::Key_Up){
            ui->label_3->setText("Acertou!!!");
        }else{
            ui->label_3->setText("Errou!!!");
            score = score - 1;
            ui->label_5->setNum(score);
        }
    }
    else if (cor_sorteada == 1){
        ui->label_3->setStyleSheet("background-color: #32cd32;"); //verde
        if (key == Qt::Key_Down){
            ui->label_3->setText("Acertou!!!");
        }else{
            ui->label_3->setText("Errou!!!");
            score = score - 1;
            ui->label_5->setNum(score);
        }
    }
    else if (cor_sorteada == 2){
        ui->label_3->setStyleSheet("background-color: #ff0000;"); //vermelho
        if (key == Qt::Key_Left){
            ui->label_3->setText("Acertou!!!");
        }else{
            ui->label_3->setText("Errou!!!");
            score = score - 1;
            ui->label_5->setNum(score);
        }
    }
    else if (cor_sorteada == 3){
        ui->label_3->setStyleSheet("background-color: #0000ff;"); //azul
        if (key == Qt::Key_Right){
            ui->label_3->setText("Acertou!!!");
        }else{
            ui->label_3->setText("Errou!!!");
            score = score - 1;
            ui->label_5->setNum(score);
        }
    }

    /*if (key == Qt::Key_Up)
        ui->label_3->setStyleSheet("background-color: #ffff00;");

    if (key == Qt::Key_Down)
        ui->label_3->setStyleSheet("background-color: #32cd32;");

    if (key == Qt::Key_Left)
        ui->label_3->setStyleSheet("background-color: #ff0000;");

    if (key == Qt::Key_Right)
        ui->label_3->setStyleSheet("background-color: #0000ff;");*/

}
