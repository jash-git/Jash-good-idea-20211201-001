import sys

from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton

def click():

    print("Hy Button is clicked!")

app = QApplication(sys.argv)

win = QMainWindow()

win.setGeometry(400, 400, 400, 300)

win.setWindowTitle("Pyqt5 Tutorial")

\# Button

button = QPushButton(win)

button.resize(200, 100)

button.setText("Hi! Click Me")

button.move(100, 100)

button.clicked.connect(click)

win.show()

sys.exit(app.exec_())
