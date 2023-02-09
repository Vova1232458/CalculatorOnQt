#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <mybutton.h>
class Calculator : public QWidget
{
    Q_OBJECT
public:
    Calculator();
private slots:
    void digit_clicked();
    void unary_operator_clicked();
    void double_operand_clicked();
    void equal_clicked();
    void point_clicked();
    void change_sign_clicked();
    void backspace_clicked();
    void clear();
    void clear_all();
    void clear_memory();
    void read_memory();
    void add_memory();
    void min_to_memory();
private:
    Button *create_button(const QString& text, const char* member);

    void abort_operation();
    bool calculate(double operand, const QString &m_pendingOperator);

    double m_sum_in_memory;

    QString m_pending_Operation;

    bool m_equalPressed;

    QLineEdit* m_display_up;
    QLineEdit* m_display_down;
    QLabel*    m_sign;

    static const int NumDigitButtons = 10;
    Button* m_digitButtons[NumDigitButtons];

    bool calculate(const QString& operation);

    QString m_squareRoot_sign = QChar(0x221A);
    QString m_power_sign      = 'x' + QChar(0x000000b2);
    QString m_reciprocal_sign = "1/x";

    QString m_division_sign = QChar(0x000000F7);
    QString m_times_sign    = QChar(0x000000D7);
    QString m_plus_sign     = "+";
    QString m_minus_sign    = "-";
    QString m_change_sign   = QChar(0x000000b1);




};

#endif // CALCULATOR_H
