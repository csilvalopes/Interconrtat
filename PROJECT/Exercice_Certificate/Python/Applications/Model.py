from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QHBoxLayout, QVBoxLayout, QGridLayout, QLineEdit, QSizePolicy
from PySide6.QtGui import QShortcut, QKeySequence
import PySide6.QtCore as QtCore

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Model d'application")
        self.setup_ui()

    def setup_ui (self):
            self.create_widgets()
            self.create_layouts()
            self.modify_widgets()
            self.add_widgets_to_layouts()
            self.setup_connections()

    def create_widgets (self) :
        pass
    def modify_widgets (self) :
        pass
    def create_layouts (self) :
        pass
    def add_widgets_to_layouts (self) :
        pass
    def setup_connections (self) :
        pass



app = QApplication() #Instancie l'application du programme dans app
#win = QWidget() #Instancie une fenetre pour l'application dans win
#win.show() #Permet d'afficherr la fenetre

main_window = MainWindow()
main_window.show()
app.exec() #Lance l'application