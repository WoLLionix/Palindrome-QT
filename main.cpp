#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <algorithm>

bool isPalindrome(const QString& str)
{
    QString reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Перевірка паліндрому");

    // Елементи інтерфейсу
    QLabel label("Введіть рядок:");
    QLineEdit input;
    QPushButton button("Перевірити");
    QLabel resultLabel;

    // Вертикальний layout
    QVBoxLayout layout(&window);
    layout.addWidget(&label);
    layout.addWidget(&input);
    layout.addWidget(&button);
    layout.addWidget(&resultLabel);

    // Подія при натисканні кнопки
    QObject::connect(&button, &QPushButton::clicked, [&]()
    {
        QString text = input.text().toLower(); // Конвертуємо текст у нижній регістр
        if (isPalindrome(text))
        {
            resultLabel.setText("Рядок є паліндромом.");
        }
        else
        {
            resultLabel.setText("Рядок не є паліндромом.");
        }
    });

    window.show();

    return app.exec();
}
