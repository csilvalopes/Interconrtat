from PySide6.QtWidgets import QApplication, QWidget

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Mon test d'application")


app = QApplication() #Instancie l'application du programme dans app
#win = QWidget() #Instancie une fenetre pour l'application dans win
#win.show() #Permet d'afficherr la fenetre

main_window = MainWindow()
main_window.show()
app.exec() #Lance l'application